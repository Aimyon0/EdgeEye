#include "camera.hpp"
#include <iostream>

bool Camera::open()
{
    cap.open(0);

    if(!cap.isOpened())
    {
        std::cout<<"Camera open failed\n";
        return false;
    }

    std::cout<<"Camera opened\n";

    return true;
}

bool Camera::read(cv::Mat& frame)
{
    cap >> frame;

    return !frame.empty();
}

double Camera::getFPS() const
{
    return cap.get(cv::CAP_PROP_FPS);
}