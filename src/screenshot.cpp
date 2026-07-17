#include "screenshot.hpp"

#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

namespace fs = std::filesystem;


Screenshot::Screenshot(const std::string& path)
{
    savePath = path;
}
std::string Screenshot::getTimestamp() const
{
    auto now = std::chrono::system_clock::now();

    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm* tm = std::localtime(&t);

    std::ostringstream oss;

    oss << std::put_time(tm, "%Y%m%d_%H%M%S");

    return oss.str();
}
bool Screenshot::save(const cv::Mat& frame)
{
    if (frame.empty())
    {
        std::cout << "Screenshot failed: empty frame." << std::endl;
        return false;
    }

    std::string saveDir =
        savePath;

    fs::create_directories(saveDir);
    std::string filename =
        savePath + "/" +
        getTimestamp() +
        ".png";

    bool ok = cv::imwrite(filename, frame);

    if (ok)
    {
        std::cout
            << "Screenshot saved: "
            << filename
            << std::endl;
    }
    else
    {
        std::cout
            << "Screenshot failed."
            << std::endl;
    }

    return ok;
}