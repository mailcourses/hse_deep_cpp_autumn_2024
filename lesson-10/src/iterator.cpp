#include <iostream>
#include <iterator>
#include <cassert>
#include <numeric>
#include <random>

//using iterator_tag = std::forward_iterator_tag;
using iterator_tag = std::random_access_iterator_tag;

template<typename _Tp>
class ArrayIterator : public std::iterator<iterator_tag, _Tp>
{
private:
    _Tp *ptr_;
public:

    using reference = _Tp&;
    using pointer = _Tp*;
    using value_type = _Tp;
    using difference_type = std::ptrdiff_t;
    using iterator_category = iterator_tag;

    ArrayIterator(_Tp* ptr) : ptr_(ptr)
    {
    }

    bool operator==(const ArrayIterator& rhs)
    {
        return ptr_ == rhs.ptr_;
    }

    bool operator!=(const ArrayIterator& rhs)
    {
        return !(*this == rhs);
    }

    ArrayIterator& operator+(size_t n)
    {
        ptr_ += n;
        return *this;
    }

    difference_type operator+(const ArrayIterator& rhs)
    {
        difference_type diff = ptr_ + rhs.ptr_;
        return diff;
    }

    difference_type operator-(const ArrayIterator& rhs)
    {
        difference_type diff = ptr_ - rhs.ptr_;
        return diff;
    }

    ArrayIterator& operator-(size_t n)
    {
        ptr_ -= n;
        return *this;
    }

    value_type operator*() const
    {
        return *ptr_;
    }

    ArrayIterator& operator++()
    {
        ++ptr_;
        return *this;
    }

    ArrayIterator operator++(int)
    {
        value_type* tmp = ptr_;
        ++ptr_;
        return ArrayIterator(tmp);
    }

};

template<typename _Tp, size_t _Size>
class Array
{
public:

    using iterator = ArrayIterator<_Tp>;

    Array(std::initializer_list<_Tp> list)
    {
        assert(list.size() <= _Size);
        size_ = list.size();
        auto begin = list.begin();
        const auto end = list.end();
        for (size_t i = 0; begin < end; ++begin, ++i)
        {
            data_[i] = *begin;
        }
    }

    iterator begin() noexcept
    {
        return iterator(data_);
    }

    iterator end() noexcept
    {
        return iterator(data_ + size_);
    }
private:
    _Tp data_[_Size];
    size_t size_;
};

int main()
{
    Array<int32_t, 5> arr = {6, 2, 1, 5, 10};
    size_t sum = std::accumulate(std::begin(arr), std::end(arr), 0);
    std::cout << "sum of our array is " << sum << std::endl;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(arr), std::end(arr), g);

    for (auto it : arr) {
        std::cout << it << std::endl;
    }

}

