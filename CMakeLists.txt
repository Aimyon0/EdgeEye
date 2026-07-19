cmake_minimum_required(VERSION 3.10)

project(EdgeEye)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

include_directories(
    include
    ${CMAKE_SOURCE_DIR}/third_party/onnxruntime/include
)

add_executable(EdgeEye
    src/main.cpp
    src/camera.cpp
    src/fps.cpp
    src/screenshot.cpp
    src/video.cpp
)

target_link_libraries(
    EdgeEye

    ${OpenCV_LIBS}

    ${CMAKE_SOURCE_DIR}/third_party/onnxruntime/lib/libonnxruntime.so
)

set_target_properties(EdgeEye PROPERTIES
    BUILD_RPATH "${CMAKE_SOURCE_DIR}/third_party/onnxruntime/lib"
)