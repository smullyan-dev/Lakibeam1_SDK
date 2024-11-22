#pragma once

#include "LakiBeamUDP.h"

struct LidarPoint {
    float timestamp;
    float angle;
    float distance;
    float rssi;
};

struct LidarScan {
    u32_t interval;
    u32_t maxdots;
    LidarPoint points[CONFIG_CIRCLE_DOTS];
};

extern "C" {

void create_lidar(const char* host_ip, const char* host_port, const char* lidar_ip, const char* lidar_port);
void close_lidar();
bool get_scan(LidarScan & scan);
}