#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <opencv2/opencv.hpp>
#include "screenshot.hpp"

#include <string>


class Camera
{
public:
    bool open();

    bool read(cv::Mat& frame);
    double getFPS() const;
private:
    cv::VideoCapture cap;
};


#endif