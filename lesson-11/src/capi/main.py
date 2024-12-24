#! /usr/bin/env python3

import cutils

def main():
    l = list(range(1,7))
    res = cutils.sum(l)
    print(f"Sum of {l} is {res}")
    d = {"hello": 1, "d": 2}
    cutils.sum(d)
    

if __name__ == "__main__":
    main()
