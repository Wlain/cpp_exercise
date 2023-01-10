//
// Created by william on 2023/1/9.
//
#include "timer.h"

#include <algorithm>
#include <cstdio>  // snprintf
#include <cstdlib> // std::terminate();
#include <iostream>
#include <stdexcept>
#include <vector>

int compareString(const void* a, const void* b)
{
    if (*(std::string*)a > *(std::string*)b)
    {
        return 1;
    }
    else if (*(std::string*)a < *(std::string*)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void vectorTest()
{
    std::vector<std::string> vec;
    char buf[10]{};
    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            vec.emplace_back(buf);
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsedSecond() << "s" << std::endl;
    std::cout << "vector.size():" << vec.size() << std::endl;
    std::cout << "vector.front():" << vec.front() << std::endl;
    std::cout << "vector.back():" << vec.back() << std::endl;
    std::cout << "vector.data():" << vec.data() << std::endl;
    std::cout << "vector.capacity():" << vec.capacity() << std::endl;

    std::string target = "23456";
    {
        timer.reset();
        // 标准库的查找
        auto item = std::find(vec.begin(), vec.end(), target);
        std::cout << "find() milli-seconds:" << timer.elapsed() << " ms\n";
        if (item != vec.end())
            std::cout << "found " << *item << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
    {
        timer.reset();
        std::sort(vec.begin(), vec.end());
        std::cout << "sort milli-seconds:" << timer.elapsed() << " ms\n";
        auto* item = (std::string*)std::bsearch(&target, vec.data(), vec.size(), sizeof(std::string), compareString);
        std::cout << "sort + bsearch() milli-seconds:" << timer.elapsed() << " ms\n";
        if (item != nullptr)
            std::cout << "found ";
        else
            std::cout << "not found ";
    }
}
