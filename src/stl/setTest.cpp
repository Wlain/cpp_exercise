//
// Created by william on 2023/1/10.
//

#include "timer.h"

#include <iostream>
#include <set>

// 关联式容器，不可以重复, 红黑树
void setTest()
{
    std::set<std::string> s;
    char buf[10]{};

    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            s.insert(buf);
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsed() << " ms" << std::endl;
    std::cout << "s.size():" << s.size() << std::endl;
    std::cout << "s.max_size():" << s.max_size() << std::endl;

    std::string target = "23456";
    {
        timer.reset();
        auto item = std::find(s.begin(), s.end(), target);
        std::cout << "find() milli-seconds:" << timer.elapsed() << " ms\n";
        if (item != s.end())
            std::cout << "found " << *item << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
    {
        timer.reset();
        auto item = s.find(target);
        // 自带的find快很多
        std::cout << "s.find() milli-seconds:" << timer.elapsed() << " ms\n";
        if (item != s.end())
            std::cout << "found " << *item << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
}