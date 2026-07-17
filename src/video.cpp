#include "video.hpp"
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

namespace fs = std::filesystem;

VideoRecorder::VideoRecorder(const std::string& path)
{
    savePath = path;
    recording = false;
}

std::string VideoRecorder::getTimestamp() const
{
    auto now = std::chrono::system_clock::now();

    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm* tm = std::localtime(&t);

    std::ostringstream oss;

    oss << std::put_time(tm, "%Y%m%d_%H%M%S");

    return oss.str();
}

bool VideoRecorder::start(int width, int height, double fps)
{
    fs::create_directories(savePath);

    std::string filename =
        savePath + "/" +
        getTimestamp() +
        ".avi";

    writer.open(
        filename,
        cv::VideoWriter::fourcc('M','J','P','G'),
        fps,
        cv::Size(width, height)
    );

    if (!writer.isOpened())
    {
        std::cout << "Video open failed." << std::endl;
        return false;
    }

    recording = true;

    std::cout << "Recording started: "
              << filename
              << std::endl;

    return true;
}

void VideoRecorder::write(const cv::Mat& frame)
{
    if (!recording)
        return;

    std::cout << "write begin" << std::endl;

    writer.write(frame);

    std::cout << "write end" << std::endl;
}

void VideoRecorder::stop()
{
    if (!recording)
        return;

    writer.release();

    recording = false;

    std::cout << "Recording stopped." << std::endl;
}

bool VideoRecorder::isRecording() const
{
    return recording;
}