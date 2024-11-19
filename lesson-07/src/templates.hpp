#pragma once

#include <iostream>

struct Foo
{
    Foo() = delete; //TODO: как сделать для new T[]?
    //Foo() {}
    Foo(size_t n) {}
};

template<class T>
class vector
{
public:
    vector(size_t n) : data_(new T[n]{n}), size_(n)
    {
    }

    size_t size() const;
    //size_t size() const { return size_; }

    ~vector()
    {
        delete[] data_;
    }

private:
    T* data_ = nullptr;
    size_t size_ = 0;
};

#include "templates.tpp"
