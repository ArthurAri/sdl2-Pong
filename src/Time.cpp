#include "Time.hpp"

namespace Time {
    float deltaTime;

    using Clock = std::chrono::high_resolution_clock;
    Clock::time_point currentTime;
    Clock::time_point previousTime;

    std::chrono::duration<float> deltaTimeDuration;

    void timeInit(){
        currentTime = Clock::now();
        previousTime = currentTime;
    }

    void frameStart(){
        currentTime = Clock::now();
        deltaTimeDuration = currentTime - previousTime;
    }

    void frameEnd(){
        previousTime = currentTime;
        deltaTime = deltaTimeDuration.count();
    }
}
