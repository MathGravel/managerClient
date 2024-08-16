#pragma once

#include <syncstream>
#include <iostream>
#include <thread>
#include <set>
#include <list>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <queue>
#include <mutex>
#include <thread>
#include "event.hpp"
#include "types.hpp"
#include <exception>

/**
 * Client class
 *
 * @note Based on the client requirements given, it was chosen to implement the class as a task thread structure. This choice was made to show
 * the client being able to work off the main thread. In cases where the client would need to run on the main thread, the threading would
 * have been changed to work inside the client class itself. In the different case of needing client to be a seperate program than the manager system,
 * the client codebase would have been seperated and would have a socket communication system added.
 * The class could also have been changed to use inheritance in order to modelize the the difference of events needed for each clients, and to make it more explicit
 * that the manager system only knows the basic client class existance but not its children,
 *  but that choice was rejected in order to keep the architecture more simple for the moment.
 * @author Mathieu Gravel
 */
class Client
{
public:
    Client(std::string name = "");
    void attach();
    bool checkWork();
    void addEvent(Event ev);

private:
    void executeBatteryChange();
    std::mutex threadMutex;
    static int UID;
    void executeCellularConnectionChange();
    void executeGpsLocation();
    void executeMotionDetection();
    std::set<int> workEvents;
    std::queue<Event> workQueue;
    std::string clientId;
    friend std::ostream &operator<<(std::ostream &os, Client const &cl)
    {
        os << "Client :" << cl.clientId << " " << cl.workEvents.size() << " " << cl.workQueue.size();
        return os;
    }
};