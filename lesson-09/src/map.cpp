#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

int main()
{
    //std::unordered_map<std::string, size_t> frequencyDictionary;
    std::map<std::string, size_t> frequencyDictionary;
    std::vector<std::string> words = {"hello", "it's", "me", "hello", "me", "hello"};
    for (const std::string& word : words)
    {
        auto it = frequencyDictionary.find(word);
        if (it == frequencyDictionary.end()) {
            frequencyDictionary[word] = 1;
        } else {
            it->second++;
        }
        //frequencyDictionary[word] += 1;
    }

    for (auto [key, value]: frequencyDictionary)
    {
        std::cout << "key: " << key << " value: " << value << std::endl;
    }

    auto begin = frequencyDictionary.begin();
    for (; begin != frequencyDictionary.end(); ++begin)
    {
        std::cout << "key: " << begin->first << " value: " << begin->second << std::endl;
    }
}
