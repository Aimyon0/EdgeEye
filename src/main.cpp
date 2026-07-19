#include "camera.hpp"
#include "fps.hpp"
#include "screenshot.hpp"
#include "video.hpp"

#include <opencv2/opencv.hpp>
#include <nlohmann/json.hpp>
#include <onnxruntime_cxx_api.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using json = nlohmann::json;

int main()
{
    std::cout << "EdgeEye start" << std::endl;
    Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "EdgeEye");

    std::cout << "ONNX Runtime loaded successfully." << std::endl;
    /*-------------------------
      Load Config
    -------------------------*/
    std::ifstream file("config.json");

    if (!file.is_open())
    {
        std::cout << "Failed to open config.json" << std::endl;
        return -1;
    }

    json config;
    file >> config;

    Screenshot screenshot(
        config["screenshot_path"].get<std::string>()
    );

    VideoRecorder recorder(
        config["video_path"].get<std::string>()
    );

    Camera camera;

    if (!camera.open())
        return -1;

    FPSCounter fps;

    cv::Mat frame;

    /*-------------------------
      Main Loop
    -------------------------*/
    while (camera.read(frame))
    {
        fps.update();

        // 录像
        if (recorder.isRecording())
        {
            recorder.write(frame);

            cv::putText(
                frame,
                "REC",
                cv::Point(20, 70),
                cv::FONT_HERSHEY_SIMPLEX,
                0.8,
                cv::Scalar(0, 0, 255),
                2
            );
        }

        // FPS
        std::ostringstream ss;
        ss << std::fixed
           << std::setprecision(1)
           << "FPS: "
           << fps.getFPS();

        cv::putText(
            frame,
            ss.str(),
            cv::Point(20, 35),
            cv::FONT_HERSHEY_SIMPLEX,
            0.8,
            cv::Scalar(0, 255, 0),
            2
        );

        cv::imshow("EdgeEye Camera", frame);

        char key = cv::waitKey(1);

        switch (key)
        {
        case 'q':
            if (recorder.isRecording())
                recorder.stop();

            return 0;

        case 's':
            screenshot.save(frame);
            break;

        case 'r':
            if (!recorder.isRecording())
            {
                double cameraFPS = camera.getFPS();

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
            break;
        }
    }

    return 0;
}