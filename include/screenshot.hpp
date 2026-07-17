#ifndef SCREENSHOT_HPP
#define SCREENSHOT_HPP

#include <opencv2/opencv.hpp>
#include <string>

class Screenshot
{
public:

    Screenshot(const std::string& path);

    bool save(const cv::Mat& frame);


private:

    std::string savePath;

    std::string getTimestamp() const;

};


#endif