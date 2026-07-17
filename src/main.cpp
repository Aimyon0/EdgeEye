#include "camera.hpp"

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    std::cout << "EdgeEye start" << std::endl;

    std::ifstream file("config.json");

    if (!file.is_open())
    {
        std::cout << "Failed to open config.json" << std::endl;
        return -1;
    }

    json config;
    file >> config;

    Camera camera(
        config["screenshot_path"].get<std::string>(),
        config["video_path"].get<std::string>()
    );

    if (!camera.open())
        return -1;

    camera.run();

    return 0;
}