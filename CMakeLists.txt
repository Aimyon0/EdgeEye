cmake_minimum_required(VERSION 3.10)


project(EdgeEye)


set(CMAKE_CXX_STANDARD 17)


find_package(OpenCV REQUIRED)



include_directories(
    include
)


add_executable(EdgeEye
    src/main.cpp
    src/camera.cpp
    src/fps.cpp
    src/screenshot.cpp
)



target_link_libraries(
    EdgeEye

    ${OpenCV_LIBS}
)
