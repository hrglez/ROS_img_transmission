/*This node will simply publish the fotograms from a camera using ROS*/

#include "cam_stream/hal/cam_stream_hal.hpp"
#include <stdio.h>

//ROS
#include "ros/ros.h"
#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/image_encodings.h"
#include "image_transport/image_transport.h"

//OpenCV
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

#define ROS_LOOP_RATE 3

void hal_init(int argc, char **argv, std::string node_name, int video_source);
int hal_ok (void);
void publish_img (void);
void finish_hal (void);

static cv::VideoCapture input_video;        //Init object to capture video
static image_transport::ImageTransport *im_transport;
static cv_bridge::CvImage cv_image;
static image_transport::Publisher pub_rgb;

void hal_init(int argc, char **argv, std::string node_name, int video_source)
{
    ros::init(argc, argv, "cam_stream");
    static ros::NodeHandle node_handler;        /*Init node handler object,
                                                must be AFTER ros::init*/
    im_transport = new image_transport::ImageTransport(node_handler);

    input_video.open(video_source);                 //Open video using camera at source 0

    ROS_INFO("Initialization without problems.");

    if ( !input_video.isOpened() )      //Conditional to verify video is working
    {
        ROS_ERROR("Unable to open the camera.");
        ros::shutdown();
    }

    ROS_INFO("Camera is working.");

    cv_image.header.frame_id = "RGB";
    cv_image.encoding = sensor_msgs::image_encodings::BGR8;

    ROS_INFO("Encoding ok.");

    //Publish the image from the camera
    pub_rgb = im_transport->advertise("cam_rgb_pub", 1);
    ROS_INFO("Camera and Publishers OK...");
}

int hal_ok (void)
{
    return ros::ok();
}

void publish_img (void)
{
    static ros::Rate loop_rate(ROS_LOOP_RATE);
    input_video.read(cv_image.image);
    pub_rgb.publish( cv_image.toImageMsg() );
    loop_rate.sleep();
}

void finish_hal (void)
{
    input_video.release();
}