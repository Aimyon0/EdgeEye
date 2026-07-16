#include "fps.hpp"

FPSCounter::FPSCounter()
{
    frameCount = 0;
    fps = 0.0;
    lastTime = std::chrono::steady_clock::now();
}

void FPSCounter::update()
{
    frameCount++;

    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - lastTime;

    if (elapsed.count() >= 1.0)
    {
        fps = frameCount / elapsed.count();
        frameCount = 0;
        lastTime = now;
    }
}

double FPSCounter::getFPS() const
{
    return fps;
}