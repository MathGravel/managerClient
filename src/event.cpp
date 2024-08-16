#include "event.hpp"

Event::Event()
{
    this->eventIdentifier = std::rand() % 4;
    switch (this->eventIdentifier)
    {
    case 0:
        this->eventInfo = "Description1";
        this->eventType = "GPS Location";
        this->workTime = constants::GPSLocation;
        break;
    case 1:
        this->eventInfo = "Description2";
        this->eventType = "Motion Detection";
        this->workTime = constants::MotionDetection;
        break;
    case 2:
        this->eventInfo = "Description3";
        this->eventType = "Battery State Change";
        this->workTime = constants::BatteryStateChange;
        break;
    case 3:
        this->eventInfo = "Description4";
        this->eventType = "Cellular Connection Change";
        this->workTime = constants::CellularConnectionChange;
        break;
    default:
        std::cout << "Error, the random number generator broke in an previously impossible way" << std::endl;

        break;
    }
}

Event::Event(int eventId)
{
    this->eventIdentifier = eventId;
    switch (this->eventIdentifier)
    {
    case 0:
        this->eventInfo = "Description1";
        this->eventType = "GPS Location";
        this->workTime = constants::GPSLocation;
        break;
    case 1:
        this->eventInfo = "Description2";
        this->eventType = "Motion Detection";
        this->workTime = constants::MotionDetection;
        break;
    case 2:
        this->eventInfo = "Description3";
        this->eventType = "Battery State Change";
        this->workTime = constants::BatteryStateChange;
        break;
    case 3:
        this->eventInfo = "Description4";
        this->eventType = "Cellular Connection Change";
        this->workTime = constants::CellularConnectionChange;
        break;
    default:
        std::cout << "Error, the random number generator broke in an previously impossible way" << std::endl;
        break;
    }
}

int Event::getEventId()
{
    return this->eventIdentifier;
}