#include <iostream>

struct Foo
{
//public:
    //!
    int size() const { return size_; }

    //!
    void foo() const
    {
        int size(size_);
        size_ += 1;
    }
public:
    mutable int size_ = 10;
};

class Boo
{
//private:
    int b = 20;
};

int main()
{
    const Foo foo;
    foo.size_;
    foo.size();
    foo.foo();

    Boo boo;
    //boo.b;
}
