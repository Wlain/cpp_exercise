//
// Created by william on 2023/1/10.
//

#include "timer.h"

#include <forward_list>
#include <iostream>

void forwardListTest()
{
    std::forward_list<std::string> li;
    char buf[10]{};

    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            li.push_front(buf);
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsedSecond() << "s" << std::endl;
    std::cout << "li.max_size():" << li.max_size() << std::endl;
    std::cout << "li.front():" << li.front() << std::endl;

    std::string target = "test";
    {
        timer.reset();
        auto item = std::find(li.begin(), li.end(), target);
        std::cout << "find() milli-seconds:" << timer.elapsedSecond() << " s\n";
        if (item != li.end())
            std::cout << "found " << *item << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
    {
        timer.reset();
        li.sort();
        std::cout << "sort milli-seconds:" << timer.elapsedSecond() << " s\n";
    }
}