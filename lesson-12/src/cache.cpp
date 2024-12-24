#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <unordered_map>


template<class K, class V>
class ThreadSafeMap
{
public:
    void put(const K& key, const V& value)
    {
        std::cout << "put(" << key << ")" << std::endl;
        std::unique_lock<std::shared_mutex> lock(mutex_);
        data_[key] = value;
    }

    void erase(const K& key)
    {
        std::cout << "erase(" << key << ")" << std::endl;
        std::unique_lock<std::shared_mutex> lock(mutex_);
        if (auto it = data_>find(key); it != data_.end()) {
            data_.erase(it);
        }
    }

    bool get(const K& key, V& value)
    {
        std::cout << "get(" << key << ")" << std::endl;
        std::shared_lock<std::shared_mutex> lock(mutex_);
        auto it = data_.find(key);
        if (it == data_.end()) {
            return false;
        }
        value = it->second;
        return true;
    }
private:
    std::unordered_map<K, V> data_;
    std::shared_mutex mutex_;
};

ThreadSafeMap<std::string, size_t> map;

void write_to_map(size_t i)
{
    map.put(std::to_string(i), 1+i);
}

void read_from_map(size_t i)
{
    size_t value;
    bool has_data = map.get(std::to_string(i), value);
}

int main()
{
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 100; ++i) {
        if (i % 10 == 0) {
            threads.emplace_back(write_to_map, i);
            continue;
        }
        threads.emplace_back(read_from_map, i);
    }

    for (auto&& thread : threads) {
        thread.join();
    }
    return 0;
}
