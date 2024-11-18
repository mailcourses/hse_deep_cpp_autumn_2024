#include <iostream>

#include "templates.hpp"

int main()
{
    vector<int> arr1(10);
    std::cout << arr1.size() << std::endl;

    vector<Foo> arr2(5);
    std::cout << arr2.size() << std::endl;

    vector<double> arr3(10);
    std::cout << arr3.size() << std::endl;
}
