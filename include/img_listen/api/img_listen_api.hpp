/**
 * \file img_listen_api.hpp
 * \file img_listen_api.cpp
*/

#ifndef IMG_LISTEN_API
#define IMG_LISTEN_API

/**
 * Initialize necessary variables and ROS environment.
 * @param argc Number of arguments, in case they exist.
 * @param argv Value of arguments, in case they exist.
 * @param publisher Name of the publisher to listen to.
 * @param mono_transport Name to initialize the image transport.
*/
void system_init (int argc, char** argv, char* publisher, char* mono_transport);
/**
 * API function that checks for the correct running of the system.
*/
int system_ok (void);
/**
 * API function that enables the node but leaves it at an idle state (necessary).
*/
void idle_state (void);

#endif