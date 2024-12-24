#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> counter = 0;

void func(size_t outer_id)
{
    counter += 1; // counter = counter + 1;
    std::cout << "outer_id=" << outer_id << ", counter = " << counter << std::endl;
}


int main()
{
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 500; ++i) {
        threads.push_back(std::thread(func, i));
    }

    for (auto&& thread : threads) {
        thread.join();
    }
    std::cout << "final counter value is  " << counter << std::endl;
}
