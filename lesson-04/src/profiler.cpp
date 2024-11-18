#include <iostream>
#include <chrono>
#include <thread>
#include <source_location>

using time_point_t = std::chrono::time_point<std::chrono::system_clock>;

using namespace std::chrono;

class Profiler
{
public:
    Profiler(std::source_location location = std::source_location::current())
    {
        start_ts_ = std::chrono::system_clock::now();
        location_ = location;
    }

    ~Profiler()
    {
        auto end_ts_ = std::chrono::system_clock::now();
        std::cout << "Time! of execution function [" << location_.function_name() << "] is " << std::chrono::duration_cast<std::chrono::microseconds>(end_ts_ - start_ts_).count() << std::endl;
    }
private:
    time_point_t start_ts_;
    std::source_location location_;
};

void foo()
{
    Profiler prof;
    for (size_t i = 0; i < 1000000; ++i);
    std::this_thread::sleep_for(12ms);
}

void boo()
{
    Profiler prof;
    for (size_t i = 0; i < 5000000; ++i);
}

int main()
{
    Profiler prof{};
    foo();
    boo();
}
