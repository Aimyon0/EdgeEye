#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <opencv2/opencv.hpp>
#include "screenshot.hpp"

#include <string>


class Camera
{

public:

    Camera(const std::string& screenshotPath);

    bool open();

    void run();


private:

    cv::VideoCapture cap;

    Screenshot screenshot;

};


#endif