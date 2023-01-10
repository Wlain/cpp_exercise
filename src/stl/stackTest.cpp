//
// Created by wilstam on 2023/1/10.
//
#include "timer.h"

#include <iostream>
#include <stack> // 包含一个deque

void stackTest()
{
    std::stack<std::string> st;
    char buf[10]{};

    Timer timer;
    constexpr long value = 1000000;
    for (long i = 0; i < value; ++i)
    {
        // 抓取异常，防止空间不够
        try
        {
            snprintf(buf, 10, "%d", rand());
            st.push(buf);
        }
        catch (std::exception& e)
        {
            std::cout << "i = " << i << e.what() << std::endl;
            // 表示容量可以达到多少
            std::terminate(); // or abort()
        }
    }
    std::cout << "milli-seconds:" << timer.elapsed() << " ms" << std::endl;
    std::cout << "st.size():" << st.size() << std::endl;
    std::cout << "st.top():" << st.top() << std::endl;
    st.pop();
    std::cout << "st.size():" << st.size() << std::endl;
    std::cout << "st.top():" << st.top() << std::endl;
}