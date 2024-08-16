#include "client.hpp"

Client::Client(std::string name)
{
    /*Since the system is not working with real values, we first create a random list subset of [0,1,2,3].
    this subset will be the events treatable by this instance of the client. In a real situation where the complete list
    of event type is unknown, the system will simply ignore those with an unknown identifier */
    int choices[] = {0, 1, 2, 3};
    std::random_shuffle(choices, choices + 4);
    int n = rand() % 3 + 1;
    workEvents = std::set(choices, choices + n);
    this->clientId = name;
}

void Client::attach()
{
    bool isrunning = true;
    while (isrunning)
    {
        //Usage of a string stream to limit sync issues. basic_osyncstream was considered but rejected due to needing additionnal dev time.
        std::stringstream clientInfo;
        clientInfo << "Client #" << this->clientId << " still on and flag is " << managerFlag << std::endl;
        std::cout << clientInfo.str();
        std::lock_guard<std::mutex> lock(threadMutex);
        if (!workQueue.empty())
        {
            Event currentTask = std::move(workQueue.front());
            workQueue.pop();
            if (workEvents.count(currentTask.getEventId()) > 0)
            {
                switch (currentTask.getEventId())
                {
                case 0:
                    executeGpsLocation();
                    break;
                case 1:
                    executeMotionDetection();
                    break;
                case 2:
                    executeBatteryChange();
                    break;
                case 3:
                    executeCellularConnectionChange();
                    break;
                default:
                    std::stringstream errorInfo;
                    errorInfo << "Error, Client #" << this->clientId << " received an event type currently untreatable by the system. Please contact your administrator for the following steps. Event id #" << currentTask.getEventId() << std::endl;
                    std::cout << errorInfo.str();
                    break;
                }
            }
        }
        else if (managerFlag > 0)
        {
            isrunning = false;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void Client::addEvent(Event ev)
{
    std::lock_guard<std::mutex> lock(threadMutex);
    workQueue.push(ev);
}

/**
 * executeBatteryChange 
 * Function to represent the work done by the client class in case of an battery change event
 */
void Client::executeBatteryChange()
{
    std::stringstream s1, s2;
    s1 << "Battery change for client #" << this->clientId << " started." << std::endl;
    std::cout << s1.str();
    std::this_thread::sleep_for(std::chrono::milliseconds(constants::BatteryStateChange));
    s2 << "Battery change for client #" << this->clientId << " finished." << std::endl;
    std::cout << s2.str();
}

/**
 * executeBatteryChange 
 * Function to represent the work done by the client class in case of an cellular connection event
 */
void Client::executeCellularConnectionChange()
{
    std::stringstream s1, s2;
    s1 << "Cellular connection change for client #" << this->clientId << " started." << std::endl;
    std::cout << s1.str();
    std::this_thread::sleep_for(std::chrono::milliseconds(constants::CellularConnectionChange));
    s2 << "Cellular connection change  for client #" << this->clientId << " finished." << std::endl;
    std::cout << s2.str();
}
/**
 * executeBatteryChange 
 * Function to represent the work done by the client class in case of an Motion detection event
 */
void Client::executeMotionDetection()
{
    std::stringstream s1, s2;
    s1 << "Motion Detection for client #" << this->clientId << " started." << std::endl;
    std::cout << s1.str();
    std::this_thread::sleep_for(std::chrono::milliseconds(constants::MotionDetection));
    s2 << "Motion Detection for client #" << this->clientId << " finished." << std::endl;
    std::cout << s2.str();
}
/**
 * executeBatteryChange 
 * Function to represent the work done by the client class in case of an GPS Location event
 */
void Client::executeGpsLocation()
{
    std::stringstream s1, s2;
    s1 << "GPS Location for client #" << this->clientId << " started." << std::endl;
    std::cout << s1.str();
    std::this_thread::sleep_for(std::chrono::milliseconds(constants::GPSLocation));
    s2 << "GPS Location for client #" << this->clientId << " finished." << std::endl;
    std::cout << s2.str();
}

/**
 * checkWork
 * Function to check if the client thread still has work waiting.
 */
bool Client::checkWork()
{
    std::stringstream s;
    std::lock_guard<std::mutex> lock(threadMutex);
    s << "Client #" << this->clientId << " Remaining work " << this->workQueue.size() << std::endl;
    std::cout << s.str();
    return !this->workQueue.empty();
}