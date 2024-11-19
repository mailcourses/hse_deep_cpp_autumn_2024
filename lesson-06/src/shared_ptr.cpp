#include <iostream>

namespace my
{

using T = int64_t;

//template<class T>
class shared_ptr
{
public:
    shared_ptr() {} // (1)
    shared_ptr(T* ptr) : data_(new wrapper_(1, ptr)) // (4)
    {
        std::cout << "shared_ptr(T*)::counter = " << data_->counter_ << std::endl;
    }

    // shared_ptr sp1;
    // shared_ptr sp2 = sp1;
    shared_ptr(const shared_ptr& rhs) // (2)
    {
        data_ = rhs.data_;
        if (data_)
        {
            data_->counter_ += 1;
            std::cout << "shared_ptr(const shared_ptr&)::counter = " << data_->counter_ << std::endl;
        }
    }

    // shared_ptr sp1;
    // shared_ptr sp2 = std::move(sp1);
    shared_ptr(shared_ptr&& rhs) // (5)
    {
        data_ = rhs.data_;
        rhs.data_ = nullptr;
    }

    // shared_ptr sp1(new T(10));
    // shared_ptr sp2(new T(20));
    // sp1 = sp2;
    // sp1 = sp1;
    //shared_ptr& operator=(const shared_ptr& rhs) == default;
    shared_ptr& operator=(const shared_ptr& rhs) // (3)
    {
        if (this == &rhs || rhs.data_ == data_)
        {
            return *this;
        }
        destroy();
        data_ = rhs.data_;
        if (data_)
        {
            data_->counter_ += 1;
            std::cout << "operator=(const shared_ptr&)::counter = " << data_->counter_ << std::endl;
        }
        return *this;
    }

    // shared_ptr sp1(new T(10));
    // shared_ptr sp2(new T(20));
    // sp1 = std::move(sp2);
    // sp1 = std::move(sp1);
    shared_ptr& operator=(shared_ptr&& rhs) // (6)
    {
        if (this == &rhs || rhs.data_ == data_)
        {
            return *this;
        }

        destroy();
        data_ = rhs.data_;
        rhs.data_ = nullptr;

        return *this;
    }

    void reset(T* ptr)
    {
        destroy();
        data_ = new wrapper_(1, ptr);
    }

    ~shared_ptr()
    {
        destroy();
    }
private:
    void destroy()
    {
        if (data_ && --(data_->counter_) == 0)
        {
            // Защита от data_->ptr_ == nullptr
            if (data_->ptr_)
            {
                delete data_->ptr_;
            }
            delete data_;
            std::cout << "memory was freed" << std::endl;
        }
    }
private:
    struct wrapper_
    {
        size_t counter_ = 0;
        T* ptr_ = nullptr;
        // wrapper(size_t counter, T* ptr) : counter_(counter), ptr_(ptr) {}
    };

    wrapper_* data_ = nullptr;
};

} // namespace my

int main()
{
    my::shared_ptr sp1; // (1)
    // sp1.reset(new int(10));
    my::shared_ptr sp2 = sp1; // (2)
    sp2 = sp1 = sp1; // (3)
    my::shared_ptr sp3(new my::T(100500)); // (4)
    {
        my::shared_ptr sp4 = sp3;
        sp3.reset(new my::T(10));
    }

    my::shared_ptr sp5 = std::move(sp1); // (5)
    sp1 = std::move(sp5); // (6)

    /*my::T* obj = new my::T(100);
    my::shared_ptr sp5(obj);
    my::shared_ptr sp6(obj);
    sp5 = sp6;*/
}
