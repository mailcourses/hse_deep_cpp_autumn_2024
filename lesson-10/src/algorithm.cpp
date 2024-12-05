#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::srand(time(nullptr));
    std::vector<int> randomNumbers;
    auto iter = std::back_inserter(randomNumbers);
    std::generate_n(iter, 10, std::rand);

    for (auto num : randomNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::string str = "Text\t with\t \ttabs";
    auto from = std::remove_if(str.begin(), str.end(), [](char x) { return x == '\t'; });
    std::cout << "str: [" << str << "]" << std::endl;
    // Text with tabs\t\t\t
    str.erase(from, str.end());
    // // Text with tabs
    std::cout << "str: [" << str << "]" << std::endl;
}
