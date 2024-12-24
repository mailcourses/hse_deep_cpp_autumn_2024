#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <map>

thread_local std::map<size_t, size_t> counter;

void thread_func(size_t outer_id)
{
    std::map<size_t, size_t> counter2;
    std::this_thread::sleep_for(std::chrono::seconds(4 - outer_id));
    std::cout << "size: " << counter.size() << std::endl;
    std::cout << std::this_thread::get_id() << ", outer_id=" << outer_id << " map[100500]: " << counter[100500] << " size=" << counter.size() << std::endl;
    counter[outer_id] = 1;
}


int main()
{
    size_t optimal_thread_cnt = std::thread::hardware_concurrency();
    std::cout << "std::thread::hardware_concurrency() = " << optimal_thread_cnt << std::endl;
    std::vector<std::thread> threads;
    threads.reserve(optimal_thread_cnt);
    counter[100500] = 500100;
    for (size_t i = 0; i < optimal_thread_cnt; ++i) {
        threads.emplace_back(thread_func, i);
    }


    for (auto&& thread : threads) {
        thread.join();
    }

    for (auto [key, value] : counter) {
        std::cout << "key: " << key << " value: " << value << std::endl;
    }

    {
        auto f = std::async(std::launch::deferred, []() {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            return 5;
        });
        auto status = f.wait_for(std::chrono::seconds(1));
        while( status != std::future_status::ready)
        {
            status = f.wait_for(std::chrono::milliseconds(900));
            if (status == std::future_status::deferred)
            {
                std::cout << "задача еще не стартовала" << std::endl;
                auto res = f.get();
            }
            else if (status == std::future_status::timeout)
                std::cout << "результата не дождались" << std::endl;
            else if (status == std::future_status::ready)
                std::cout << "все готово" << std::endl;
        }
    }
    std::cout << "end of main thread" << std::endl;
    return 0;
}
