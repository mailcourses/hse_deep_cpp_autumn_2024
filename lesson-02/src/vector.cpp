#include "vector.hpp"

namespace fake {

int
Fake::get_const() const
{
    return 10;
}

std::string
Fake::get_const_string() const
{
    return "Hello, world!";
}

}
