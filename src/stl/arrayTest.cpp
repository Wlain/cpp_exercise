//
// Created by william on 2023/1/9.
//
#include "timer.h"

#include <array>
#include <cstdlib>
#include <iostream>

#define ARRAY_SIZE 500000

int compareLongs(const void* a, const void* b)
{
    return (*(long*)a - *(long*)b);
}
void arrayTest()
{
    std::array<long, ARRAY_SIZE> arr{};
    Timer timer;
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        arr[i] = rand();
    }
    std::cout << "milli-seconds:" << timer.elapsed() << "ms" << std::endl;
    std::cout << "array.size:" << arr.size() << std::endl;
    std::cout << "array.front():" << arr.front() << std::endl;
    std::cout << "array.back():" << arr.back() << std::endl;
    std::cout << "array.data():" << arr.data() << std::endl;

    long target = 10000;
    timer.reset();
    std::qsort(arr.data(), ARRAY_SIZE, sizeof(long), compareLongs);
    auto* item = (long*)std::bsearch(&target, (arr.data()), ARRAY_SIZE, sizeof(long), compareLongs);
    std::cout << "qsort + bsearch, milli-seconds:" << timer.elapsed() << "ms" << std::endl;
    if (item != nullptr)
        std::cout << "found ";
    else
        std::cout << "not found ";
    std::cout << target << std::endl;
}
