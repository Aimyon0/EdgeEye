#include "camera.hpp"

#include <iostream>

int main()
{
    std::cout << "EdgeEye start" << std::endl;

    Camera camera;

    if (!camera.open())
        return -1;
    
    camera.run();

    return 0;
}