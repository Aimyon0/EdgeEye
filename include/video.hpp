#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <opencv2/opencv.hpp>
#include <string>

class VideoRecorder
{
public:
    VideoRecorder(const std::string& savePath);

    bool start(int width, int height, double fps);

    void write(const cv::Mat& frame);

    void stop();

    bool isRecording() const;

private:
    std::string getTimestamp() const;

private:
    cv::VideoWriter writer;
    std::string savePath;
    bool recording;
};

#endif