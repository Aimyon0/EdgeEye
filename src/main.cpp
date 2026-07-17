#include "camera.hpp"

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    std::cout << "EdgeEye start" << std::endl;
    std::string screenshotPath;


    std::ifstream file("config.json");

    json config;

    file >> config;


    screenshotPath =
    config["screenshot_path"];
    Camera camera(screenshotPath);

    if (!camera.open())
        return -1;
    
    camera.run();

    return 0;
}