#include <iostream>

#include "header1.hpp"

static int k = 0;

int foo()
{
    int i = 0;
    static int j = 0;
    ++i; ++j; ++k;
    std::cout << "i = " << i << ", j = " << j << ", k = " << k << std::endl;
    return i + j;
}

int main()
{
    for (size_t i = 0; i < 5; ++i) {
        foo();
    }
    std::cout << "main::k = " << k << std::endl;
    std::cout << "::fluffy = " << fluffy << std::endl;
    return 0;
}
