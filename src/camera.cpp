#include "camera.hpp"
#include "fps.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

Camera::Camera(const std::string& screenshotPath,
               const std::string& videoPath)
    : screenshot(screenshotPath),
      recorder(videoPath)
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

        if (recorder.isRecording())
        {
            recorder.write(frame);

            cv::putText(
                frame,
                "REC",
                cv::Point(20,70),
                cv::FONT_HERSHEY_SIMPLEX,
                0.8,
                cv::Scalar(0,0,255),
                2
            );
        }

        cv::imshow("EdgeEye Camera", frame);

        char key = cv::waitKey(1);

        if (key == 'q')
        {
            if (recorder.isRecording())
                recorder.stop();

            break;
        }
        else if (key == 's')
        {
            screenshot.save(frame);
        }
        else if (key == 'r')
        {
            if (!recorder.isRecording())
            {
                double cameraFPS = cap.get(cv::CAP_PROP_FPS);

                if (cameraFPS <= 1)
                    cameraFPS = 30;

                recorder.start(
                    frame.cols,
                    frame.rows,
                    cameraFPS
                );
            }
            else
            {
                recorder.stop();
            }
        }
    }
}