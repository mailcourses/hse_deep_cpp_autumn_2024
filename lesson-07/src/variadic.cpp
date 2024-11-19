#include <iostream>

template <class T>
void print(T&& val)
{
    std::cout << val << '\n';
}
template <class T, class... Args>
void print(T&& val, Args&&... args)
{
    std::cout << val << '\n';
    print(std::forward<Args>(args)...);
}

int main()
{
    print(1, "abc", 2.5);
}
