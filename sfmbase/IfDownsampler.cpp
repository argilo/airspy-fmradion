// airspy-fmradion
// Software decoder for FM broadcast radio with Airspy
//
// Copyright (C) 2015 Edouard Griffiths, F4EXB
// Copyright (C) 2019 Kenji Rikitake, JJ1BDX
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <cassert>
#include <cmath>

#include "IfDownsampler.h"

// ////////////////  class FourthDownconverterIQ /////////////////

// Construct Fs/4 downconverting tuner.
FourthDownconverterIQ::FourthDownconverterIQ() : m_index(0) {}

// Process samples.
// See Richard G. Lyons' explanation at
// https://www.embedded.com/print/4007186
inline void FourthDownconverterIQ::process(const IQSampleVector &samples_in,
                                           IQSampleVector &samples_out) {
  unsigned int tblidx = m_index;
  unsigned int n = samples_in.size();

  samples_out.resize(n);

  for (unsigned int i = 0; i < n; i++) {
    IQSample y;
    const IQSample &s = samples_in[i];
    const IQSample::value_type re = s.real();
    const IQSample::value_type im = s.imag();
    switch (tblidx) {
    case 0:
      // multiply +1
      y = s;
      tblidx = 1;
      break;
    case 1:
      // multiply +j
      y = IQSample(im, -re);
      tblidx = 2;
      break;
    case 2:
      // multiply -1
      y = IQSample(-re, -im);
      tblidx = 3;
      break;
    case 3:
      // multiply -j
      y = IQSample(-im, re);
      tblidx = 0;
      break;
    default:
      // unreachable, error here;
      assert(tblidx < 4);
      break;
    }
    samples_out[i] = y;
  }

  m_index = tblidx;
}

// Class IfDownsampler

IfDownsampler::IfDownsampler(
    bool fourth_downsampler, unsigned int first_downsample,
    const std::vector<IQSample::value_type> &first_coeff,
    unsigned int second_downsample,
    const std::vector<IQSample::value_type> &second_coeff)

    // Initialize member fields
    : m_first_downsample(first_downsample),
      m_second_downsample(second_downsample),
      m_fourth_downsampler(fourth_downsampler), m_if_level(0),
      // Construct LowPassFilterFirIQ
      m_iffilter_first(first_coeff, m_first_downsample),
      m_iffilter_second(second_coeff, m_second_downsample)

{
  // do nothing
}

void IfDownsampler::process(const IQSampleVector &samples_in,
                            IQSampleVector &samples_out) {

  // Fine tuning is not needed
  // so long as the stability of the receiver device is
  // within the range of +- 1ppm (~100Hz or less).

  if (m_fourth_downsampler) {
    // Fs/4 downconvering is required
    // to avoid frequency zero offset
    // because Airspy HF+ is a Zero IF receiver
    m_downconverter.process(samples_in, m_buf_iftuned);
  } else {
    // No shifting here
    m_buf_iftuned = samples_in;
  }

  // First stage of the low pass filters to isolate station,
  // and perform first stage decimation.
  m_iffilter_first.process(m_buf_iftuned, m_buf_iffirstout);

  if (m_second_downsample > 1) {
    // Second stage of the low pass filters to isolate station,
    m_iffilter_second.process(m_buf_iffirstout, samples_out);
  } else {
    // No second downsampling here
    samples_out = m_buf_iffirstout;
  }

  // Measure IF level.
  double if_rms = rms_level_approx(samples_out);
  m_if_level = 0.95 * m_if_level + 0.05 * (double)if_rms;
}

// Compute RMS over a small prefix of the specified sample vector.
double IfDownsampler::rms_level_approx(const IQSampleVector &samples) {
  unsigned int n = samples.size();
  n = (n + 63) / 64;

  IQSample::value_type level = 0;
  for (unsigned int i = 0; i < n; i++) {
    level += std::norm(samples[i]);
  }
  // Return RMS level
  return sqrt(level / n);
}

/* end */