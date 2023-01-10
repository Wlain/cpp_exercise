//
// Created by wildeam on 2023/1/10.
//

#include "timer.h"

#include <iostream>
#include <deque>

// 分段连续，是一种假象
void dequeTest()
{
    std::deque<std::string> de;
    char buf[10]{};
    
    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            de.emplace_back(buf);
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsedSecond() << "s" << std::endl;
    std::cout << "de.size():" << de.size() << std::endl;
    std::cout << "de.front():" << de.front() << std::endl;
    std::cout << "de.back():" << de.back() << std::endl;
    std::cout << "de.max_size():" << de.max_size() << std::endl;

    std::string target = "23456";
    {
        timer.reset();
        auto item = std::find(de.begin(), de.end(), target);
        std::cout << "find() milli-seconds:" << timer.elapsedSecond() << " s\n";
        if (item != de.end())
            std::cout << "found " << *item << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
    {
        timer.reset();
        std::sort(de.begin(), de.end());
        std::cout << "sort milli-seconds:" << timer.elapsedSecond() << " s\n";
    }
}
