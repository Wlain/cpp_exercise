//
// Created by william on 2023/1/10.
//
#include "timer.h"

#include <iostream>
#include <queue> // 包含一个deque

void queueTest()
{
    std::queue<std::string> qu;
    char buf[10]{};

    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            qu.push(buf);
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsed() << " ms" << std::endl;
    std::cout << "qu.size():" << qu.size() << std::endl;
    std::cout << "qu.front():" << qu.front() << std::endl;
    std::cout << "qu.back():" << qu.back() << std::endl;
    qu.pop();
    std::cout << "qu.size():" << qu.size() << std::endl;
    std::cout << "qu.front():" << qu.front() << std::endl;
    std::cout << "qu.back():" << qu.back() << std::endl;
}