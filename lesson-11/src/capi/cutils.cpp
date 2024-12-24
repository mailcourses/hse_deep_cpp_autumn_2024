#include <iostream>
#include <Python.h>

PyObject* cutils_sum(PyObject* self, PyObject* args)
{
    PyObject* py_list;
    if (!PyArg_ParseTuple(args, "O", &py_list)) {
        std::cerr << "Failed to parse py obj" << std::endl;
        return nullptr;
    }

    if (!PyList_Check(py_list)) {
        std::cerr << "PyObject is not a list" << std::endl;
        PyErr_Format(PyExc_TypeError, "PyObject is not a list");
        return nullptr;
    }

    size_t list_len = PyList_Size(py_list);
    size_t res = 0;
    for (size_t i = 0; i < list_len; ++i)
    {
        PyObject* item = PyList_GetItem(py_list, i);
        res += PyLong_AsLong(item);
    }
    //return PyLong_FromLong(res);
    return Py_BuildValue("l", res);
}

int32_t fibonacci(int32_t num)
{
    if (num < 2)
        return 1;
    return fibonacci(num-1) + fibonacci(num-2);
}

PyObject* cutils_fibonacci(PyObject* self, PyObject* args)
{
    int32_t num = 0;
    if (!PyArg_ParseTuple(args, "l", &num)) {
        std::cerr << "Failed to parse py obj" << std::endl;
        return nullptr;
    }

    int32_t res = fibonacci(num);
    return PyLong_FromLong(res);
}

static PyMethodDef cutils_methods[] = {
    {"sum", cutils_sum, METH_VARARGS, "Метод, суммирующий элементы входного списка."},
    {"fibonacci", cutils_fibonacci, METH_VARARGS, "Метод, возвращающий i-ый элемент последовательности Фибоначчи."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef cutils_module = {
    PyModuleDef_HEAD_INIT,
    "cutils",
    "Модуль для примера",
    -1,
    cutils_methods
};

PyMODINIT_FUNC PyInit_cutils() {
    return PyModule_Create(&cutils_module);
}
