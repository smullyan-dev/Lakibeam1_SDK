#include "python_interface.h"
#include "LakiBeamUDP.h"
#include <string>

LakiBeamUDP* drv = NULL;



void create_lidar(const char* host_ip, const char* host_port, const char* lidar_ip, const char* lidar_port)
{
    if(drv!=NULL)
        delete drv;
    drv = new LakiBeamUDP(string(host_ip), string(host_port), string(lidar_ip), string(lidar_port));
    printf("Lidar driver created\n");
}

void close_lidar()
{
    if(drv != NULL)
    {
        delete drv;
        drv = NULL;
    }
}

bool get_scan(LidarScan & scan)
{
    if(drv!=NULL)
    {
        repark_t scan_int;
        bool ret =  drv->get_repackedpack(scan_int);
        if (ret) {
            scan.maxdots = scan_int.maxdots;
            scan.interval = scan_int.interval;
            for (int i = 0; i < scan_int.maxdots; i++) {
                scan.points[i].timestamp = 0.001f * float(scan_int.dotcloud[i].timestamp);
                scan.points[i].angle = 0.01f * float(scan_int.dotcloud[i].angle);
                scan.points[i].distance = float(scan_int.dotcloud[i].distance);
                scan.points[i].rssi = float(scan_int.dotcloud[i].rssi);
            }
        }
        return ret;
    }
    return false;
}

class Cleanup {
public:
    ~Cleanup()
    {
        close_lidar();
    }
}

cleanup = Cleanup();