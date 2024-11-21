#pragma once

#include "LakiBeamUDP.h"

struct scan_data_t
{
    float timestamp;
    float angle;
    float distance;
    float quality;
};

extern "C" {

void create_lidar(const char* host_ip, const char* host_port, const char* lidar_ip, const char* lidar_port);
void close_lidar();
bool get_scan(repark_t & scan);
}