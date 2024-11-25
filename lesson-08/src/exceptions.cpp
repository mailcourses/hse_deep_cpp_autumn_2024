#include <iostream>

struct Foo
{
    Foo()
    {
        try {
            data = new int32_t[1024];
            std::cout << "Foo ctr" << std::endl;
            throw std::exception{};
        } catch(.../*NetException& ex*/) {
            // pass
        }
    }

    ~Foo() noexcept(false) // <-- помечаем, что деструктор может кидать исключения.
    {
        std::cout << "~Foo dtr" << std::endl;
        delete[] data;
        throw std::exception{};
    }

private:
    int32_t *data;
};

int main()
{
    try {
        Foo foo;
    } catch (std::exception& ex)
    {
        std::cout << "catch up" << std::endl;
        //throw ex; <-- пробрасывание исключения
    }
}
