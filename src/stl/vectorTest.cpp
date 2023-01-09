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

void vectorTest()
{
    std::vector<std::string> vec;
    char buf[10]{};
    Timer timer;
    constexpr long value = 500000;
    for (int i = 0; i < value; ++i)
    {
        try
        {
            snprintf(buf, 10, "%d", rand());
            vec.emplace_back(buf);
        }
        catch (std::exception& e)
        {
            std::cout << "i=" << i << e.what() << std::endl;
            std::terminate();
        }
    }
    std::cout << "milli-seconds:" << timer.elapsed() << "ms" << std::endl;
    std::cout << "vector.size:" << vec.size() << std::endl;
    std::cout << "vector.front():" << vec.front() << std::endl;
    std::cout << "vector.back():" << vec.back() << std::endl;
    std::cout << "vector.data():" << vec.data() << std::endl;
    std::cout << "vector.capacity():" << vec.capacity() << std::endl;
}