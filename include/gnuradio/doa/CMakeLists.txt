# Copyright 2011,2012 Free Software Foundation, Inc.
#
# This file was generated by gr_modtool, a tool from the GNU Radio framework
# This file is a part of gr-doa
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Install public header files
########################################################################
install(FILES api.h
    calibrate_lin_array.h
    autocorrelate.h
    MUSIC_lin_array.h
    find_local_max.h
    antenna_correction.h
    rootMUSIC_linear_array.h DESTINATION include/gnuradio/doa)
