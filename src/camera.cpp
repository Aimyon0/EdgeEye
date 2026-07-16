#include "camera.hpp"
#include <iostream>


Camera::Camera()
{

}


bool Camera::open()
{

    cap.open(0);


    if(!cap.isOpened())
    {
        std::cout<<"Camera open failed"<<std::endl;
        return false;
    }


    std::cout<<"Camera opened"<<std::endl;

    return true;

}



void Camera::run()
{

    cv::Mat frame;


    while(true)
    {

        cap >> frame;


        if(frame.empty())
            break;


        cv::imshow(
            "EdgeEye Camera",
            frame
        );


        char key=cv::waitKey(1);


        if(key=='q')
            break;

    }


}
