#include <iostream>

void foo(int)
{
    std::cout << "foo(int)" << std::endl;
}

void foo(int&)
{
    std::cout << "foo(int&)" << std::endl;
}

void foo(int&&)
{
    std::cout << "foo(int&&)" << std::endl;
}

int main()
{
    int x = 10;
    //foo(std::move(x));
}
