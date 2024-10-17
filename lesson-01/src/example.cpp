#define PI 3.1415

#define MAX(x, y) x > y ? x : y
#define MULT(x, y) (x) * (y)
#define NAME(world) #world

#include <iostream>

int main()
{
    std::cout << PI << std::endl;
    int res = MULT(5+5, 4+4);
    int a = 1;
    int b = 10;
    res = MAX(++a, b);
    #line 100
    std::cout << "Hello, " << NAME(world) << " from " << __FILE__ << " and line #" << __LINE__ << std::endl;
    return 0;
}
