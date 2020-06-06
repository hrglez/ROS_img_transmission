#include "cam_stream/api/cam_stream_api.hpp"

#define NODE_NAME "cam_stream"
#define CAM_ID 0

int main (int argc, char **argv)
{
    system_init(argc, argv, NODE_NAME, CAM_ID);

    while( system_ok() )
    {
        stream();
    }

    finish_system();

    return 0;
}