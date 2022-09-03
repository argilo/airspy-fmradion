// airspy-fmradion
// Software decoder for FM broadcast radio with Airspy
//
// Copyright (C) 2015 Edouard Griffiths, F4EXB
// Copyright (C) 2019-2022 Kenji Rikitake, JJ1BDX
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

#ifndef INCLUDE_DATABUFFER_H
#define INCLUDE_DATABUFFER_H

#include <condition_variable>
#include <mutex>
#include <queue>

/** Buffer to move sample data between threads. */
template <class Element> class DataBuffer {
public:
  /** Constructor. */
  DataBuffer() : m_qlen(0), m_end_marked(false) {}

  /** Add samples to the queue. */
  void push(std::vector<Element> &&samples) {
    if (!samples.empty()) {
      {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_qlen += samples.size();
        m_queue.push(std::move(samples));
        // unlock m_mutex here by getting out of scope
      }
      m_cond.notify_all();
    }
  }

  /** Mark the end of the data stream. */
  void push_end() {
    {
      std::lock_guard<std::mutex> lock(m_mutex);
      m_end_marked = true;
      // unlock m_mutex here by getting out of scope
    }
    m_cond.notify_all();
  }

  /** Return number of samples in queue. */
  std::size_t queued_samples() {
    {
      std::lock_guard<std::mutex> lock(m_mutex);
      return m_qlen;
      // unlock m_mutex here by getting out of scope
    }
  }

  /**
   * If the queue is non-empty, remove a block from the queue and
   * return the samples. If the end marker has been reached, return
   * an empty vector. If the queue is empty, wait until more data is pushed
   * or until the end marker is pushed.
   */
  std::vector<Element> pull() {
    std::vector<Element> ret;
    {
      std::unique_lock<std::mutex> lock(m_mutex);
      m_cond.wait(lock, [&] { return !(m_queue.empty() && !m_end_marked); });
      if (!m_queue.empty()) {
        m_qlen -= m_queue.front().size();
        std::swap(ret, m_queue.front());
        m_queue.pop();
      }
      return ret;
      // unlock m_mutex here by getting out of scope
    }
  }

  /** Return true if the end has been reached at the Pull side. */
  bool pull_end_reached() {
    {
      std::lock_guard<std::mutex> lock(m_mutex);
      return (m_qlen == 0 && m_end_marked);
      // unlock m_mutex here by getting out of scope
    }
  }

  /** Wait until the buffer contains minfill samples or an end marker. */
  void wait_buffer_fill(std::size_t minfill) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cond.wait(lock, [&] { return !(m_qlen < minfill && !m_end_marked); });
  }

private:
  std::size_t m_qlen;
  bool m_end_marked;
  std::queue<std::vector<Element>> m_queue;
  std::mutex m_mutex;
  std::condition_variable m_cond;
};

#endif
