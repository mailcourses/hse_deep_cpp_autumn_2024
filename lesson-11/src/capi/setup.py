#! /usr/bin/env python3

from setuptools import setup, Extension

def main():
    setup(
        name="cutils",
        version="1.0.1",
        description="sample descr",
        author="Kukhtichev A.A.",
        ext_modules=[Extension('cutils', ['cutils.cpp'])]
    )

if __name__ == "__main__":
    main()
