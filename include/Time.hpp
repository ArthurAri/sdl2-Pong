#pragma once
#include <ctime>
#include <chrono>

#ifndef TIME_HPP
#define TIME_HPP

namespace Time
{
    extern float deltaTime;
    void timeInit();
    void frameStart();
    void frameEnd();
}

#endif