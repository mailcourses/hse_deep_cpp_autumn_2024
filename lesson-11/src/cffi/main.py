#! /usr/bin/env python3

import cffi

def ABI():
    ffi = cffi.FFI()
    lib = ffi.dlopen('./libsum.so')
    ffi.cdef('''
    int sum(int*, int);

    struct Point
    {
        int x;
        int y;
    };

    int area(struct Point*, struct Point*);
    ''')

    l = list(range(1,5))
    c_l = ffi.new('int[]', l)
    res = lib.sum(c_l, len(l))
    print(f"Sum of {l} is {res}")
    #res = lib.fibonacci(10)
    #print(f"10-th elemnt of fibonacci is {res}")
    p1 = ffi.new('struct Point*')
    p2 = ffi.new('struct Point*')
    p1.x, p1.y = 10, -10
    p2.x, p2.y = 1, 2
    print(p1.x, p2.x, p1.y, p2.y)
    res = lib.area(p1, p2)
    print(f'Area {p1} {p2} is {res}')

def API():
    ffi = cffi.FFI()
    ffi.cdef('''
    int sum(int*, int);

    struct Point
    {
        int x;
        int y;
    };

    int area(struct Point*, struct Point*);
    ''')

    ffi.set_source('sample',
    r'''
    #include <stdlib.h>
    #include <stdio.h>

    struct Point
    {
        int x;
        int y;
    };

    int area(struct Point* p1, struct Point* p2)
    {
        //printf("%d %d %d %d", p1->x, p1->y, p2->x, p2->y);
        return abs((p1->x - p2->x) * (p1->y - p2->y));
    }

    int sum(int *arr, int len)
    {
        int res = 0;
        for (int i = 0; i < len; ++i)
        {
           res += arr[i];
        }
        return res;
    }
    ''')
    ffi.compile()
    from sample import lib
    l = list(range(1,6))
    c_l = ffi.new('int[]', l)
    res = lib.sum(c_l, len(l))
    print(f"Sum of {l} is {res}")

def main():
    print("=== ABI ===")
    ABI()
    print("=== API ===")
    API()

if __name__ == "__main__":
    main()

