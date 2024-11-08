#include <iostream>

struct A
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

struct B : public A
{
};

struct C : protected A
{
//public:
//protected:
//  int a;
//  int b;
    C()
    {
        //std::cout << "c: " << c << std::endl;
    }
};

struct D : private A
{
//public:
//protected:
//private:
//  int a;
//  int b;
};

int main()
{
    A a;
    a.a;
    //a.b; a.c;
    //
    B b;
    b.a;
    //b.b; b.c;
    //
    C c;
    //c.a;
    //c.b; c.c;
}
