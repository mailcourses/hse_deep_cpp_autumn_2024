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

template<class X, class Y>
struct IsSame
{
    static constexpr bool value = false;
};

template<class X>
struct IsSame<X, X>
{
    static constexpr bool value = true;
};

template<class T>
struct has_fast
{
private:
    static void check(...);

    template<class U>
    static auto check(U* u) -> decltype(u->fast());
public:
    //static constexpr bool value = std::is_same<int, decltype(check((T*)nullptr))>::value;
    static constexpr bool value = IsSame<int, decltype(check((T*)nullptr))>::value;

};

template<class T>
void optimize(T& t,
              typename std::enable_if<has_fast<T>::value>::type* = nullptr)
{
    std::cout << "optimize has fast" << std::endl;
    t.fast();
}

template<class T>
void optimize(T& t,
              typename std::enable_if<!has_fast<T>::value>::type* = nullptr)
{
    std::cout << "optimize has slow" << std::endl;
    t.slow();
}


int main()
{
    std::cout << std::boolalpha << "Has fast for Foo: " << has_fast<Foo>::value << std::endl;
    std::cout << std::boolalpha << "Has fast for Boo: " << has_fast<Boo>::value << std::endl;
    std::cout << std::boolalpha << "Has fast for Moo: " << has_fast<Moo>::value << std::endl;
    std::cout << std::boolalpha << "Has fast for int: " << has_fast<int>::value << std::endl;

    Foo foo;
    Boo boo;
    Moo moo;
    optimize(foo);
    optimize(boo);
    optimize(moo);
}
