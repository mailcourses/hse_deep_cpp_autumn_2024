#include <iostream>

#pragma pack(push, 1)
struct S {
    //int m3;
    char m1;
    double m2;
    //int m4;
};
#pragma pack(pop)

int main()
{
    std::cout << "sizeof(char) " << sizeof(char) << std::endl;
    std::cout << "sizeof(double) " << sizeof(double) << std::endl;
    std::cout << "sizeof(int) " << sizeof(int) << std::endl;
    std::cout << "sizeof(S) " << sizeof(S) << std::endl;
    //std::cout << "offsetof(S, m1) " << offsetof(S, m1) << std::endl;
    //std::cout << "offsetof(S, m2) " << offsetof(S, m2) << std::endl;
    //std::cout << "offsetof(S, m3) " << offsetof(S, m3) << std::endl;
}
