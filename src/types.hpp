#pragma once


/**
 * Namespace used for the application constant values.
 * This method was used over #define in order to keep the variables in scope.
 */

extern int managerFlag;


namespace constants {
    unsigned const int PORT = 4161;
     enum EVENTTIMEMS {
        GPSLocation = 1000,
        MotionDetection = 5000,
        CellularConnectionChange = 10,
        BatteryStateChange = 10000
    };
};