#include <iostream>
#include <vector>
#include <algorithm>

struct Foo
{
    Foo(int a) : a_(a) {}
    int a_ = 0;
    /*bool operator<(const Foo& rhs)
    {
        return a_ < rhs.a_;
    }*/
};

bool compare(const Foo& lhs, const Foo& rhs)
{
    return lhs.a_ > rhs.a_;
}
/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
int main()
{
    std::vector<Foo> elems = {Foo(100), Foo(5), Foo(25)};


    bool greater = false;
    /*
     *  if (greater) return true;
     *  return false;
     *
     *  -->
     *
     *  return greater;
     */
    auto comp = [greater](const Foo& lhs, const Foo& rhs) -> bool {
        return greater ? lhs.a_ > rhs.a_ : lhs.a_ < rhs.a_;
    };
    std::sort(std::begin(elems), std::end(elems), comp);
    for (auto elem : elems) {
        std::cout << elem.a_ << std::endl;
    }
}
