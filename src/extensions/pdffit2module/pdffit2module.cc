/***********************************************************************
*
* pdffit2           by DANSE Diffraction group
*                   Simon J. L. Billinge
*                   (c) 2006 trustees of the Michigan State University
*                   All rights reserved.
*
* File coded by:    Chris Farrow
*
* See AUTHORS.txt for a list of people who contributed.
* See LICENSE.txt for license information.
*
************************************************************************
*
* The python pdffit2 module.
*
* Comments:
*
***********************************************************************/
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <ostream>

#include "pyexceptions.h"
#include "bindings.h"
#include "../libpdffit2/pdffit.h"

using namespace std;

char pypdffit2_module__doc__[] =
    "pdffit2 - interface to the core calculation routines in C++";

// local helper for transfer version information from
// Python to C++ PdfFit class.

namespace {

void transfer_version()
{
    // obtain version information from the Python module
    PyObject* mdiffpy_pdffit2;
    mdiffpy_pdffit2 = PyImport_ImportModule("diffpy.pdffit2");
    if (!mdiffpy_pdffit2)   return;
    PyObject* pyversion;
    pyversion = PyObject_GetAttrString(mdiffpy_pdffit2, "__version__");
    Py_DECREF(mdiffpy_pdffit2);
    if (!pyversion)         return;
    const char* cversion;
#if PY_MAJOR_VERSION >= 3
    cversion = PyUnicode_AsUTF8(pyversion);
#else
    cversion = PyString_AsString(pyversion);
#endif
    // copy version information to C++ constant
    if (cversion)   PdfFit::version(cversion);
    Py_DECREF(pyversion);
}


void setup_module_contents(PyObject* d)
{
    // install the module exceptions
    pypdffit2_runtimeError = PyErr_NewException("pdffit2.runtime", 0, 0);
    PyDict_SetItemString(d, "RuntimeException", pypdffit2_runtimeError);

    pypdffit2_unassignedError = PyErr_NewException(
            "pdffit2.unassignedError", 0, 0);
    PyDict_SetItemString(d, "unassignedError", pypdffit2_unassignedError);

    pypdffit2_dataError = PyErr_NewException(
            "pdffit2.dataError", 0, 0);
    PyDict_SetItemString(d, "dataError", pypdffit2_dataError);

    pypdffit2_structureError = PyErr_NewException(
            "pdffit2.structureError", 0, 0);
    PyDict_SetItemString(d, "structureError", pypdffit2_structureError);

    pypdffit2_calculationError = PyErr_NewException(
            "pdffit2.calculationError", 0, 0);
    PyDict_SetItemString(d, "calculationError", pypdffit2_calculationError);

    pypdffit2_constraintError = PyErr_NewException(
            "pdffit2.constraintError", 0, 0);
    PyDict_SetItemString(d, "constraintError", pypdffit2_constraintError);

    transfer_version();
}


// Module initialization for Python 3 ----------------------------------------

static struct PyModuleDef pdffit2moduledef = {
    PyModuleDef_HEAD_INIT,
    // .m_name =
    "pdffit2_ext",  // Updated module name here
    // .m_doc =
    pypdffit2_module__doc__,
    // .m_size =
    -1,
    // .m_methods =
    pypdffit2_methods,
};


PyMODINIT_FUNC
PyInit_pdffit2_ext(void)

{
    PyObject *module = PyModule_Create(&pdffit2moduledef);
    if (module == NULL)  return NULL;

    PyObject* d = PyModule_GetDict(module);
    setup_module_contents(d);
    return module;
}

#endif  // PY_MAJOR_VERSION == 2

// End of file
