/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <pybind11/pybind11.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

namespace py = pybind11;

// Headers for binding functions
/**************************************/
// The following comment block is used for
// gr_modtool to insert function prototypes
// Please do not delete
/**************************************/
// BINDING_FUNCTION_PROTOTYPES(
    void bind_calibrate_lin_array(py::module& m);
    void bind_autocorrelate(py::module& m);
    void bind_MUSIC_lin_array(py::module& m);
    void bind_find_local_max(py::module& m);
    void bind_antenna_correction(py::module& m);
    void bind_rootMUSIC_linear_array(py::module& m);
// ) END BINDING_FUNCTION_PROTOTYPES


// We need this hack because import_array() returns NULL
// for newer Python versions.
// This function is also necessary because it ensures access to the C API
// and removes a warning.
void* init_numpy()
{
    import_array();
    return NULL;
}

PYBIND11_MODULE(doa_python, m)
{
    // Initialize the numpy C API
    // (otherwise we will see segmentation faults)
    init_numpy();

    // Allow access to base block methods
    py::module::import("gnuradio.gr");

    /**************************************/
    // The following comment block is used for
    // gr_modtool to insert binding function calls
    // Please do not delete
    /**************************************/
    // BINDING_FUNCTION_CALLS(
    bind_calibrate_lin_array(m);
    bind_autocorrelate(m);
    bind_MUSIC_lin_array(m);
    bind_find_local_max(m);
    bind_antenna_correction(m);
    bind_rootMUSIC_linear_array(m);
    // ) END BINDING_FUNCTION_CALLS
}