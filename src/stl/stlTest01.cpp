//
// Created by william on 2023/1/8.
//

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void stlTest01()
{
    int arr[6] = { 1, 2, 3, 120, 5, 50 };
    std::vector<int, std::allocator<int>> vec(arr, arr + 6);
    std::cout << std::count_if(vec.begin(), vec.end(), [](const auto& v) { return v < 40; }) << std::endl;
}