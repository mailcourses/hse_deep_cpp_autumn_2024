#! /usr/bin/env python3

import ctypes

def main():
    lib1 = ctypes.CDLL('./libsum.so')
    lib1.sum.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
    lib1.sum.restype = ctypes.c_int
    l = list(range(1,5))
    arr_len = len(l)
    arr_type = ctypes.c_int * arr_len
    res = lib1.sum(arr_type(*l), len(l))
    print(f"Len of l is {res}")

if __name__ == "__main__":
    main()
