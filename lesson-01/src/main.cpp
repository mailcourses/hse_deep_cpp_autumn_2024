#include "a.hpp"
#include "b.hpp"
#include "square.hpp"
//#include "utils.hpp"

int g = 100500;
const int h = 100500;

void foo(int num) {
}

void foo(int num1, int num2) {
}

void foo(double num) {
}

int main()
{
    foo();
    short i = 10;
    foo(i);
    square(10);
    return distance(10, 6);
}
