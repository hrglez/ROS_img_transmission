/**
 * \file img_listen_hal.hpp
 * \file img_listen_hal.cpp
*/

#ifndef IMG_LISTEN_HAL
#define IMG_LISTEN_HAL

#include <cv_bridge/cv_bridge.h> /*Necessary for sensor_msgs::ImageConstPtr object*/

/**
 * Initialize necessary variables and ROS environment.
 * @param argc Number of arguments referred to ros::init, in case they exist.
 * @param argv Value of arguments referred to ros::init, in case they exist.
 * @param publisher Name of the publisher to listen to.
 * @param mono_transport Name to initialize the image transport.
*/
void hal_init (int argc, char **argv, char* publisher, char* mono_transport);
/**
 * Callback function used when an image is received.
 * @param msg Image received on the node.
*/
void imageCallback(const sensor_msgs::ImageConstPtr& msg);
/**
 * Function that checks for the correct running of the system.
*/
int hal_ok (void);
/**
 * Function that enables the node but leaves it at an idle state (necessary).
*/
void listen_state (void);

#endif