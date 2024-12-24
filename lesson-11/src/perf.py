#! /usr/bin/env python3

import time
import functools
import ctypes

import cffi

import cutils
import cyutils

MAX_N = 35

#@functools.lru_cache(128)
def fibonacci(num: int):
    if num < 2:
        return 1
    return fibonacci(num-1) + fibonacci(num-2)

def py_fibonacci(num: int):
    start_ts = time.time()
    res = fibonacci(num)
    end_ts = time.time()
    return res, end_ts-start_ts

def ctypes_fibonacci(num: int):
    clib = ctypes.CDLL('./ctypes/libsum.so')
    clib.fibonacci.argtypes = [ctypes.c_int]
    clib.fibonacci.restype = ctypes.c_int
    start_ts = time.time()
    res = clib.fibonacci(num)
    end_ts = time.time()
    return res, end_ts-start_ts

def cffi_fibonacci(num: int):
    ffi = cffi.FFI()
    lib = ffi.dlopen('./cffi/libsum.so')
    ffi.cdef('''
    int fibonacci(int);
    ''')
    start_ts = time.time()
    res = lib.fibonacci(num)
    end_ts = time.time()
    return res, end_ts-start_ts

def capi_fibonacci(num: int):
    start_ts = time.time()
    res = cutils.fibonacci(num)
    end_ts = time.time()
    return res, end_ts-start_ts

def cython_fibonacci(num: int):
    start_ts = time.time()
    res = cyutils.fibonacci(num)
    end_ts = time.time()
    return res, end_ts-start_ts

def main():
    py_res, py_ts = py_fibonacci(MAX_N)
    print(f"Result of py function is {py_res} and takes {py_ts:.3} s")
    ctypes_res, ctypes_ts = ctypes_fibonacci(MAX_N)
    print(f"Result of ctypes function is {ctypes_res} and takes {ctypes_ts:.3} s")
    cffi_res, cffi_ts = cffi_fibonacci(MAX_N)
    print(f"Result of cffi function is {cffi_res} and takes {cffi_ts:.3} s")
    capi_res, capi_ts = capi_fibonacci(MAX_N)
    print(f"Result of capi function is {capi_res} and takes {capi_ts:.3} s")
    cython_res, cython_ts = cython_fibonacci(MAX_N)
    print(f"Result of cython function is {cython_res} and takes {cython_ts:.3} s")
    assert py_res == ctypes_res == cffi_res == capi_res == cython_res

if __name__ == "__main__":
    main()
