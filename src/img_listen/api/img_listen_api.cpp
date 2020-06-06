#include "img_listen/api/img_listen_api.hpp"
#include "img_listen/hal/img_listen_hal.hpp"

//ROS
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

//OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void system_init (int argc, char **argv, char* publisher, char* mono_transport);
int system_ok (void);
void idle_state (void);

void system_init(int argc, char **argv, char* pub, char* mono_tr)
{
    hal_init (argc, argv, pub, mono_tr);
}

int system_ok (void)
{
    return hal_ok();
}

void idle_state (void)
{
    listen_state();
}