#include <tuple>
#include <iostream>

int main()
{
    auto t = std::make_tuple(1, 2.0, "abc");
    auto [a, b, c] = t;
    //std::print("{0} {1} {2}\n", a, b, c);
    c = 4.3f;
}
