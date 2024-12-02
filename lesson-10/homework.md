## Домашнее задание №7

Написать свою реализацию АВЛ-дерева с интерфейсом std::map, аллокатор и двунаправленного итератора для него.

```c++
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class avl;
```
Из поддерживаемых методов достаточно:
- operator[]
- at
- insert
- erase
- find
- contains
- empty
- size
- clear
- begin, rbegin
- end, rend

Интерфейс аллокатора и итератора смотрите в [документации](https://en.cppreference.com/w/).

Примера итератора, который итерирует последовательность по четным числам:
```c++
#include <iostream>
#include <set>
#include <vector>

template <class Iter>
class OddIterator
    : public std::iterator<std::forward_iterator_tag, typename Iter::value_type>
{
    Iter current_;
    Iter end_;

    void findNext()
    {
        while (current_ != end_)
        {
            if (*current_ % 2 == 0)
                return;
            ++current_;
        }
    }

public:
    OddIterator(Iter&& begin, Iter&& end)
        : current_(std::move(begin))
        , end_(std::move(end))
    {
        findNext();
    }

    bool operator==(const OddIterator& other) const
    {
        return current_ == other.current_;
    }

    bool operator!=(const OddIterator& other) const
    {
        return !(*this == other);
    }

    void operator++()
    {
        if (current_ != end_)
        {
            ++current_;
            findNext();
        }
    }

    int operator*() const
    {
        return *current_;
    }
};

template <class Container>
OddIterator<typename Container::const_iterator> getBegin(const Container& data)
{
    return OddIterator<typename Container::const_iterator>(data.cbegin(), data.cend());
}

template <class Container>
OddIterator<typename Container::const_iterator> getEnd(const Container& data)
{
    return OddIterator<typename Container::const_iterator>(data.cend(), data.cend());
}

int main()
{
    std::vector<int> data1 = { 9, 8, 1, 3, 4, 5, 6 };
    std::for_each(getBegin(data1), getEnd(data1), [](int x) { std::cout << x << '\n'; });

    std::cout << '\n';

    std::set<int> data2(data1.begin(), data1.end());
    std::for_each(getBegin(data2), getEnd(data2), [](int x) { std::cout << x << '\n'; });

    return 0;
}
```

Тесты обязательны!!!
