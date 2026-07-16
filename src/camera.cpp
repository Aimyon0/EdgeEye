#include "camera.hpp"
#include "fps.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

Camera::Camera()
{

}

bool Camera::open()
{
    cap.open(0);

    if (!cap.isOpened())
    {
        std::cout << "Camera open failed" << std::endl;
        return false;
    }

    std::cout << "Camera opened" << std::endl;

    return true;
}

void Camera::run()
{
    cv::Mat frame;

    FPSCounter fps;

    while (true)
    {
        cap >> frame;

        if (frame.empty())
            break;

        fps.update();

        std::ostringstream ss;
        ss << std::fixed
           << std::setprecision(1)
           << "FPS: "
           << fps.getFPS();

        cv::putText(
            frame,
            ss.str(),
            cv::Point(20,35),
            cv::FONT_HERSHEY_SIMPLEX,
            0.8,
            cv::Scalar(0,255,0),
            2
        );

        cv::imshow("EdgeEye Camera", frame);
        char key = cv::waitKey(1);

        if (key == 'q')
            break;
    }
}