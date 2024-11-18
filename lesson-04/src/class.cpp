#include <iostream>

void bark()
{
    
}

class Dachshund
{
public:
    //  name_(const_cast<std::string&>(name) -- так делать не нужно!!!!!!!
    Dachshund(uint8_t age, const std::string& name) : name_(const_cast<std::string&>(name)) // конструктор
    {
        age_ = age;
        std::cout << "Dachshund ctr" << std::endl;
        std::cout << "Dachshund ctr::name_ = " << name_ << std::endl;
    }

    ~Dachshund()                           // деструктор
    {
        std::cout << "Dachshund dctr" << std::endl;
    }

    static void bark()
    {
        //weight_ -= 0.001; // this->weight_
        claws_len_ += 1;
    }
public:
    std::string &name_;
    double weight_ = 0;
    uint8_t age_ = 0;
private:
    inline static uint8_t claws_len_ = 10;
};

//Dachshund::claws_len_ = 10;

int main()
{
    std::cout << "before" << std::endl;
    {
        std::string tmp{"unknown"};
        Dachshund roksy(16, "unknown");
        std::cout << "roksy.name = " << roksy.name_ << std::endl;
        roksy.name_ = std::string("Roksy");
        roksy.weight_ = 7;
        roksy.age_ += 1;
        roksy.bark();
        Dachshund::bark();
    }
    std::cout << "after" << std::endl;
}
