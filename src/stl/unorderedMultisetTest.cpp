//
// Created by william on 2023/1/10.
//
#include "timer.h"

#include <iostream>
#include <unordered_set>

// 哈希
void unorderedMultisetTest()
{
    std::unordered_multiset<std::string> unorderedMulSet;
    char buf[10]{};

    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            unorderedMulSet.insert(buf);
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsed() << " ms" << std::endl;
    std::cout << "unorderedMulSet.size():" << unorderedMulSet.size() << std::endl;
    std::cout << "unorderedMulSet.max_size():" << unorderedMulSet.max_size() << std::endl;
    // 篮子一定比个数多
    std::cout << "unorderedMulSet.bucket_count():" << unorderedMulSet.bucket_count() << std::endl;
    std::cout << "unorderedMulSet.load_factor():" << unorderedMulSet.load_factor() << std::endl;
    std::cout << "unorderedMulSet.max_bucket_count():" << unorderedMulSet.max_bucket_count() << std::endl;
    std::cout << "unorderedMulSet.max_load_factor():" << unorderedMulSet.max_load_factor() << std::endl;
    for (unsigned i = 0; i < 20; ++i)
    {
        std::cout << "bucket # " << i << " has " << unorderedMulSet.bucket_size(i) << " elements." << std::endl;
    }
    std::string target = "23456";
    {
        timer.reset();
        auto item = std::find(unorderedMulSet.begin(), unorderedMulSet.end(), target);
        std::cout << "find() milli-seconds:" << timer.elapsed() << " ms\n";
        if (item != unorderedMulSet.end())
            std::cout << "found " << *item << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
    {
        timer.reset();
        auto item = unorderedMulSet.find(target);
        // 自带的find快很多
        std::cout << "unorderedMulSet.find() milli-seconds:" << timer.elapsed() << " ms\n";
        if (item != unorderedMulSet.end())
            std::cout << "found " << *item << std::endl;
        else
            std::cout << "not found!" << std::endl;
    }
}