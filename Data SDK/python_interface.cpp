#include "python_interface.h"
#include "LakiBeamUDP.h"
#include <string>

LakiBeamUDP* drv = NULL;

void create_lidar(const char* host_ip, const char* host_port, const char* lidar_ip, const char* lidar_port)
{
    if(drv!=NULL)
        delete drv;
    drv = new LakiBeamUDP(string(host_ip), string(host_port), string(lidar_ip), string(lidar_port));
    printf("Lidar driver created");
}

void close_lidar()
{
    if(drv != NULL)
    {
        delete drv;
        drv = NULL;
    }
}

void get_scan(repark_t & scan)
{
    if(drv!=NULL)
    {
        drv->get_repackedpack(scan);
    }
}

class Cleanup {
public:
    ~Cleanup()
    {
        close_lidar();
    }
}

cleanup = Cleanup();