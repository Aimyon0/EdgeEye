#include <iostream>

#include "camera.hpp"


int main()
{

    std::cout<<"EdgeEye start"<<std::endl;


    Camera camera;


    if(camera.open())
    {
        camera.run();
    }


    return 0;

}
