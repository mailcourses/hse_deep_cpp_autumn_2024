#include <iostream>
#include <cstring>

class Device
{
public:
    Device()
    {
        std::cout << "Device ctr" << std::endl;
        a = new int[10];
    }

    virtual void print(const std::string& message)
    {
        //
        std::cout << "Device::print [" << message << "]" << std::endl;
    }

    // Чисто виртуальную функцию.
    virtual void flush() = 0;

    virtual ~Device()
    {
        std::cout << "Device dctr" << std::endl;
        delete[] a;
    }
private:
    int* a;
};

class Printer : public Device
{
public:
    Printer()
    {
        std::cout << "Printer ctr" << std::endl;
    }

    void print(const std::string& message) override
    {
        //
        std::cout << "Printer::print [" << message << "]" << std::endl;
    }

    void flush() override {}

    virtual ~Printer()
    {
        std::cout << "Printer dctr" << std::endl;
    }
};

class Terminal : public Device
{
public:
    Terminal()
    {
        std::cout << "Terminal ctr" << std::endl;
        data = new char[1024];
    }

    void print(const std::string& message) override
    {
        //
        std::cout << "Terminal::print [" << message << "]" << std::endl;
    }

    void flush() override {}

    virtual ~Terminal()
    {
        std::cout << "Terminal dctr" << std::endl;
        delete[] data;
    }
private:
    char* data;
};

Device* create(char **argv)
{
    if (strcmp(argv[1], "printer") == 0)
    {
        return new Printer;
    }
    else if (strcmp(argv[1], "terminal") == 0)
    {
        return new Terminal;
    }
    return nullptr;
}

int main(int argc, char** argv)
{
    Device* device = create(argv);
    device->print("Hello, kitty");
    device->flush();
    delete device;
}
