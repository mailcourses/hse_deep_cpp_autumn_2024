#include <iostream>
#include <deque>

void foo(std::deque<int32_t> &arr) {
    for (size_t i = 0; i < 10; ++i) {
        //for (int32_t num : arr) {
        size_t arr_size = arr.size();
        for (size_t j = 0; j < arr_size; ++j) {
            std::sort(std::begin(arr), std::end(arr));
            arr.push_front(arr[j]);
        }
    }
}

int main()
{
    std::deque<int32_t> arr = {2,3,1};
    foo(arr);
    for (auto num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
