//
// Created by william on 2023/1/10.
//
#include "timer.h"

#include <iostream>
#include <unordered_map>

// 哈希
void unorderedMultimapTest()
{
    std::unordered_multimap<long, std::string> unorderedMulMap;
    char buf[10]{};
    
    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            unorderedMulMap.emplace(std::pair{i, buf});
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsed() << " ms" << std::endl;
    std::cout << "unorderedMulMap.size():" << unorderedMulMap.size() << std::endl;
    std::cout << "unorderedMulMap.max_size():" << unorderedMulMap.max_size() << std::endl;

    constexpr long target = 23456;
    {
        timer.reset();
        auto item = unorderedMulMap.find(target);
        std::cout << "find() milli-seconds:" << timer.elapsed() << " ms\n";
        if (item != unorderedMulMap.end())
            std::cout << "found " << (*item).second << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
}