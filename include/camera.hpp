#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <opencv2/opencv.hpp>

class Camera
{
public:

    Camera();

    bool open();

    void run();

private:

    cv::VideoCapture cap;

};

#endif
