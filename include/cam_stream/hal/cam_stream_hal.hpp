/**
 * \file cam_stream_hal.hpp
 * \file cam_stream_hal.cpp
*/

#ifndef CAM_STREAM_HAL
#define CAM_STREAM_HAL

#include <string>

/**
 * Initialize necessary variables and ROS environment.
 * @param argc Number of arguments referred to ros::init, in case they exist.
 * @param argv Value of arguments referred to ros::init, in case they exist.
 * @param node_name Name of the publisher.
 * @param video_source Identifier of the camera to use.
*/
void hal_init(int argc, char **argv, std::string node_name, int video_source);
/**
 * Function that checks for the correct running of the system.
*/
int hal_ok (void);
/**
 * Read image from source and publish it.
*/
void publish_img (void);
/**
 * Release resources.
*/
void finish_hal (void);

#endif