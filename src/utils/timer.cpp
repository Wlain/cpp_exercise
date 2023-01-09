//
// Created by william on 2023/1/9.
//

#include "timer.h"
Timer::Timer() :
    m_begin(std::chrono::high_resolution_clock::now())
{
}

Timer::~Timer() = default;

template <typename Duration>
int64_t Timer::elapsed() const
{
    return std::chrono::duration_cast<Duration>(std::chrono::high_resolution_clock::now() - m_begin).count();
}

int64_t Timer::elapsedMicro() const
{
    return elapsed();
}

int64_t Timer::elapsedNano() const
{
    return elapsed<std::chrono::nanoseconds>();
}

int64_t Timer::elapsedSecond() const
{
    return elapsed<std::chrono::seconds>();
}

int64_t Timer::elapsedMinutes() const
{
    return elapsed<std::chrono::minutes>();
}

int64_t Timer::elapsedHours() const
{
    return elapsed<std::chrono::hours>();
}

void Timer::reset()
{
    m_begin = std::chrono::high_resolution_clock::now();
}
