#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

template<class C, class I>
auto authAndAccess(C& counter, const I& index) -> decltype(counter[index])
{
    //...
    return counter[index];
}

int main()
{
    std::map<std::string, int64_t> counter1 = {{"hello", 10}};
    std::unordered_map<std::string, int64_t> counter2 = {{"hello", 10}};
    std::vector<int64_t> counter3(20, 0);

    authAndAccess(counter1, "hello");
    authAndAccess(counter2, "hello");
    authAndAccess(counter3, 10);

    //void f; <-- CE
}
