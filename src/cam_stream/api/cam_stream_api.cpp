#include "cam_stream/api/cam_stream_api.hpp"
#include "cam_stream/hal/cam_stream_hal.hpp"

void system_init (int argc, char **argv, std::string node_name, int video_source);
int system_ok (void);
void stream (void);
void finish_system (void);

void system_init (int argc, char **argv, std::string node_name, int video_source)
{
    hal_init (argc, argv, node_name, video_source);
}

int system_ok (void)
{
    return hal_ok();
}

void stream (void)
{
   publish_img();
}

void finish_system (void)
{
    finish_hal();
}