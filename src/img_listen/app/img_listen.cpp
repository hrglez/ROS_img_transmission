#include "img_listen/api/img_listen_api.hpp"

static char RGB_IMAGE_PUBLISHER_NAME[] = "cam_rgb_pub";
static char MONO_IMAGE_PUBLISHER_NAME[] = "camera/image_mono";

int main(int argc, char **argv)
{

    system_init(argc, argv, RGB_IMAGE_PUBLISHER_NAME, MONO_IMAGE_PUBLISHER_NAME);

    while( system_ok() )
    {
        idle_state();
    }
    
    return 0;
}