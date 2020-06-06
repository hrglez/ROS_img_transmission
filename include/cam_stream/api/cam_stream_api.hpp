/**
 * \file cam_stream_api.hpp
 * \file cam_stream_api.cpp
*/

#ifndef CAM_STREAM_API
#define CAM_STREAM_API

#include <string>

/**
 * Initialize necessary variables and ROS environment.
 * @param argc Number of arguments, in case they exist.
 * @param argv Value of arguments, in case they exist.
 * @param node_name Name of the publisher.
 * @param video_source Identifier of the camera to use.
*/
void system_init (int argc, char **argv, std::string node_name, int video_source);
/**
 * Function that checks for the correct running of the system.
*/
int system_ok (void);
/**
 * Function in charge of streaming the image.
*/
void stream (void);
/**
 * Function in charge of releasing the system resources.
*/
void finish_system (void);

#endif