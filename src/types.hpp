#pragma once


/**
 * Namespace used for the application constant values.
 * This method was used over #define in order to keep the variables in scope.
 */

extern int managerFlag;


namespace constants {
    unsigned const int PORT = 4162;
     enum EVENTTIMEMS {
        GPSLocation = 1000,
        MotionDetection = 500,
        CellularConnectionChange = 50,
        BatteryStateChange = 200
    };
};