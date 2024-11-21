#include "python_interface.h"
#include <stdio.h>


int main()
{
    create_lidar("192.168.7.101", "2368", "192.168.7.2", "2368");
    while (1) {
        repark_t scan;
        get_scan(scan);
        int i = 0;
        printf("%d\n", scan.maxdots);
        for (i = 0; i < scan.maxdots; i++) {
            printf("Angle=%1.2f, Distance=%d\n", 0.01* float(scan.dotcloud[i].angle), scan.dotcloud[i].distance);
        }
    }
    return 0;
}