#include <iostream>

template <class T>
T max (T &a, T &b)
{
    return (a > b)? a : b;
}

template <>
int max <int> (int &a, int &b)
{
    std::cout << "Called ";
    return (a > b)? a : b;
}

int main ()
{
    {
        int a = 10, b = 20;
        std::cout << max <int> (a, b) << std::endl;
    }
    {
        double a = 10, b = 20;
        std::cout << max <double> (a, b) << std::endl;
    }
}
