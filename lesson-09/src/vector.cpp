#include <iostream>
#include <vector>

struct A
{
    A()
    {
        std::cout << "A()" << std::endl;
    }
};

int main()
{
    constexpr int max_size = 16;
    {
        std::vector<A> v(max_size);
        v.reserve(max_size);
        std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
        for (size_t i = 0; i < max_size; ++i) {
            //v[i] = A();
            v.push_back(A());
            std::cout << i << ") size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
        }
        std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
    }

    {
        constexpr size_t n = 10;
        constexpr size_t m = 20;
        std::vector<std::vector<bool>> matrix(n, std::vector<bool>(m, false));
    }

    {
        std::vector<int> v(1024);
        v.clear();
        std::cout << "capacity: " << v.capacity() << std::endl;
        std::vector<int>().swap(v);
        std::cout << "capacity: " << v.capacity() << std::endl;
    }
}
