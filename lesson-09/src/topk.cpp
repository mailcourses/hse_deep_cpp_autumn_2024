#include <iostream>
#include <queue>
#include <vector>

int main()
{
    constexpr size_t k = 3;
    std::vector<int> arr = {8, 3, 5, 10, 2, 7, 9, 1};
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int num : arr) {
        pq.push(num);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
}
