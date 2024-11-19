#include <iostream>
#include <cstdarg>

void foo(const int& a)
{
    std::cout << "foo(const lvalue ref)" << std::endl;
}

void foo(int& a)
{
    std::cout << "foo(lvalue ref)" << std::endl;
}

void foo(int&& a)
{
    std::cout << "foo(rvalue ref)" << std::endl;
}

int sum(size_t n, ...)
 {
    va_list args;
    va_start(args, n);
    int result{};
    while(n--) {
       auto next_element = va_arg(args, int);
       result += next_element;
    }
    va_end(args);
    return result;
 }

struct A
{
    A(int x) : x_(x) {}
    int y_ = 1000;
    int x_ = 0;
};

int main()
{
    int a = 1;
    const int b = 2;
    foo(a);
    foo(b);
    foo(10);
    std::cout << "sum: " << sum(4, 10, 1, 2, A(100)) << std::endl;
}
