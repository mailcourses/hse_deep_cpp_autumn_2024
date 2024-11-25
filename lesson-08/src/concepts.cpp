#include <iostream>

struct Foo
{
    int fast() { return 100500; }
};

struct Boo
{
    void slow() {}
};

struct Moo
{
    std::string fast() { return std::string(); }
    void slow() {}
};

template<typename T>
concept HasFast =
    requires(T t) {
    //    { t.fast() } -> std::convertible_to<int>;
        { t.fast() } -> std::same_as<int>;
    };


template<HasFast T>
void optimize(T& t)
{
    std::cout << "optimize has fast" << std::endl;
    t.fast();
}

template<class T>
void optimize(T& t)
{
    std::cout << "optimize has slow" << std::endl;
    t.slow();
}

int main()
{
    {
        Foo foo;
        optimize(foo);
    }

    {
        Boo boo;
        optimize(boo);
    }

    {
        Moo moo;
        optimize(moo);
    }
}
