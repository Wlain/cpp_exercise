//
// Created by william on 2023/1/10.
//
#include "timer.h"

#include <iostream>
#include <list>


void listTest()
{
    std::list<std::string> li;
    char buf[10]{};

    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            li.emplace_back(buf);
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsed() << " ms" << std::endl;
    std::cout << "li.size():" << li.size() << std::endl;
    std::cout << "li.max_size():" << li.max_size() << std::endl;
    std::cout << "li.front():" << li.front() << std::endl;
    std::cout << "li.back():" << li.back() << std::endl;

    std::string target = "23456";
    {
        timer.reset();
        auto item = std::find(li.begin(), li.end(), target);
        std::cout << "find() milli-seconds:" << timer.elapsed() << " ms\n";
        if (item != li.end())
            std::cout << "found " << *item << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
    {
        timer.reset();
        li.sort();
        std::cout << "sort milli-seconds:" << timer.elapsed() << " ms\n";
    }
}