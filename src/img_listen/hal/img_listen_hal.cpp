#include "img_listen/hal/img_listen_hal.hpp"

//ROS
#include <ros/ros.h>
#include <image_transport/image_transport.h>
//#include <cv_bridge/cv_bridge.h> /*Included in .hpp*/
#include <sensor_msgs/image_encodings.h>

//OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void hal_init (int argc, char **argv, char* publisher, char* mono_transport);
void imageCallback(const sensor_msgs::ImageConstPtr& msg);
int hal_ok (void);
void listen_state (void);

static sensor_msgs::ImagePtr mono_msg;
static image_transport::ImageTransport *img_transport;
static image_transport::Publisher mono_publisher;
static image_transport::Subscriber sub;


void hal_init (int argc, char **argv, char* publisher, char* mono_transport)
{
    /* Initialize ROS node*/
    ros::init(argc,argv,"img_listen");
    /* Initialize ros handler*/
    static ros::NodeHandle node_handler;
    /* Initialize image transport handler*/
    img_transport = new image_transport::ImageTransport(node_handler);
    /* Initialize image transport*/
    mono_publisher = img_transport->advertise(mono_transport,1);
    /*Subscribe to image publisher*/
    sub = img_transport->subscribe(publisher, 1, imageCallback);
}

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
        cv::Mat img_rgb=cv_bridge::toCvShare(msg, "bgr8")->image;
        cv::Mat img(msg->height,msg->width, CV_8UC1);
        //cvtColor(img_rgb, img,CV_RGB2GRAY);

        /**********************************************/
        /*Frame processing, optional, by Leonardo*/

        /*mono_msg = cv_bridge::CvImage(std_msgs::Header(),
        sensor_msgs::image_encodings::MONO8, img).toImageMsg();
        mono_msg->header.frame_id = "image_mono";
        mono_msg->width = img_rgb.cols;
        mono_msg->height = img_rgb.rows;
        mono_msg->is_bigendian = false;
        mono_msg->step = sizeof(unsigned char) * img_rgb.cols;
        mono_msg->header.stamp = ros::Time::now();*/
        /**********************************************/

        /*For demostration purposes, the following code was made to write
        or visualize the image received*/

        /*Image is written in ros environment folder*/
        //cv::imwrite("image.jpg", img_rgb);

        /*Display image*/
        cv::namedWindow ("Display Image", cv::WINDOW_AUTOSIZE);
        imshow ("Display Image", img_rgb);
        cv::waitKey(1);
    }

    /*Catch to display error in case there is any*/
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.",
        msg->encoding.c_str());
    }
}

int hal_ok (void)
{
    return ros::ok();
}

void listen_state (void)
{
    static ros::Rate rate = ros::Rate(10);
    ros::spinOnce();
    /* publish new message */
    mono_publisher.publish(mono_msg);
    rate.sleep();
}