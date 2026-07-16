#pragma once

#include <chrono>

class FPSCounter
{
public:
    FPSCounter();

    void update();

    double getFPS() const;

private:
    int frameCount;

    double fps;

    std::chrono::steady_clock::time_point lastTime;
};