//
// Created by william on 2023/1/10.
//

#include "timer.h"

#include <iostream>
#include <map>

// 使用：红黑树实现
void mulitimapTest()
{
    std::multimap<long, std::string> mulMap;
    char buf[10]{};
    
    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            mulMap.emplace(std::pair{i, buf});
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsed() << " ms" << std::endl;
    std::cout << "mulMap.size():" << mulMap.size() << std::endl;
    std::cout << "mulMap.max_size():" << mulMap.max_size() << std::endl;

    constexpr long target = 23456;
    {
        timer.reset();
        auto item = mulMap.find(target);
        std::cout << "find() milli-seconds:" << timer.elapsed() << " ms\n";
        if (item != mulMap.end())
            std::cout << "found " << (*item).second << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
}