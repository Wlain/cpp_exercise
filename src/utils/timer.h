//
// Created by william on 2023/1/9.
//

#ifndef CPP_EXERCISE_TIMER_H
#define CPP_EXERCISE_TIMER_H
#include <chrono>

class Timer
{
public:
    Timer();
    ~Timer();

public:
    template <typename Duration = std::chrono::microseconds>
    [[nodiscard]] int64_t elapsed() const;
    [[nodiscard]] int64_t elapsedMicro() const;
    [[nodiscard]] int64_t elapsedNano() const;
    [[nodiscard]] int64_t elapsedSecond() const;
    [[nodiscard]] int64_t elapsedMinutes() const;
    [[nodiscard]] int64_t elapsedHours() const;
    void reset();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_begin;
};

#endif // CPP_EXERCISE_TIMER_H
