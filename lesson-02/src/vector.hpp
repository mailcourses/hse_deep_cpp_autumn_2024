#include <iostream>

namespace fake {

struct Fake
{
    int get_const() const;
    std::string get_const_string() const;

    int i = 10;
};

}
