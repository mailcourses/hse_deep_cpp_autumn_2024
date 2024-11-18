#include <iostream>
#include <functional>
#include <vector>

struct RightMover
{
    void operator()(int&x, int& y)
    {
        std::cout << "Foo::operator()" << std::endl;
    }
};

using MoveFunction =
     std::function<void (int& x, int& y)>;

void moveLeft(int &x, int &y)
{
    std::cout << "moveLeft()" << std::endl;
}

int main()
{
    std::vector<MoveFunction> trajectories =
    {
       [](int& x, int& y)
       {
           std::cout << "lambda()" << std::endl;
       },
       moveLeft,
       RightMover()
    };

    int x = 10;
    int y = -10;
    for (auto trajectory : trajectories) {
        trajectory(x, y);
    }
}
