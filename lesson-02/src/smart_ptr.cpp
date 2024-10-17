#include <iostream>
#include <memory>

struct A
{
    A()
    {
        std::cout << "A ctr" << std::endl;
    }
    A(const A& rhs)
    {
        std::cout << "A ctr" << std::endl;
    }
    A& operator=(const A& rhs)
    {
        std::cout << "A ctr" << std::endl;
        return *this;
    }
    ~A()
    {
        std::cout << "A dctr" << std::endl;
    }
};

void foo(std::shared_ptr<A> sp)
{
    std::cout << "foo::ref count " << sp.use_count() << std::endl;
}

int main()
{
    std::shared_ptr<A> sp1(new A);
    {
        std::shared_ptr<A> sp2 = sp1;
        sp2.reset(new A);
        foo(sp1);
        std::cout << "ref count " << sp1.use_count() << " " << sp2.use_count() << std::endl;
    }

    /*std::unique_ptr<int> up1(new int(10));
    std::unique_ptr<int> up2 = up1;*/
}

