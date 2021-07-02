#!/bin/sh
./generate-cxx-coeff-list.py jj1bdx_ssb_12khz_1500hz 12kHz-ssb-1500Hz-383taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_am_48khz_narrow 48kHz-am-3kHz-255taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_am_48khz_medium 48kHz-am-4.5kHz-255taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_am_48khz_default 48kHz-am-6kHz-255taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_am_48khz_wide 48kHz-am-9kHz-127taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_cw_12khz_500hz 12kHz-cw-500Hz-383taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_nbfm_48khz_default 48kHz-nbfm-10kHz-127taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_nbfm_48khz_narrow 48kHz-nbfm-6.25kHz-127taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_nbfm_48khz_medium 48kHz-nbfm-8kHz-127taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_nbfm_48khz_wide 48kHz-nbfm-20kHz-127taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_fm_384kHz_narrow 384kHz-242kHz-127taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_fm_384kHz_medium 384kHz-312kHz-127taps-coeff.txt
./generate-cxx-coeff-list.py jj1bdx_div4_predownsampling div4-400kHz-for-3100kHz-64taps-coeff.txt
