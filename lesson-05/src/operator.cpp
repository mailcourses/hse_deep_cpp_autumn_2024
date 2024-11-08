#include <iostream>

class Dummy
{
public:
    Dummy() = default;
    Dummy(const std::string& str)
    {
        data_ = static_cast<uint64_t>(std::stol(str));
    }

    Dummy(uint64_t data) : data_(data) {}

    Dummy operator+(const Dummy& rhs)
    {
        return Dummy(data_ + rhs.data_);
    }

    // Dummy num;
    // num << std::cout;
    std::ostream& operator<<(/*Dummy* this,*/std::ostream& out)
    {
        out << this->data_;
        return out;
    }

    friend std::ostream& operator<<(std::ostream& out, const Dummy& rhs);

private:
    uint64_t data_{0};
};

std::ostream& operator<<(std::ostream& out, const Dummy& rhs)
{
    out << rhs.data_;
    return out;
}

int main()
{
    Dummy num1("123");
    Dummy num2(321);
    // Dummy::operator<<
    num1+num2 << std::cout << std::endl;
    // ::operator<<
    std::cout << num1+num2 << std::endl;
}
