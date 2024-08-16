#pragma once

#include "socketManager.hpp"
#include "threadManager.hpp"
#include "client.hpp"
#include <csignal>

/**
 * cleanExit function has the task of catching interruption signals in the system, in order to make sure that the client thread pools have finished executing their tasks and logging
 * and can safely terminate themselves in order to do a clean exit
 * @param  {int} signalType : Terminasion signal code received by the system.
 */
void cleanExit(int signalType);
/**
 * Global variable managing when the system is in operating mode, and when to begin shutdown mode.
 */

/**
 * Manager class
 */
class Manager
{
public:
    Manager();
    void addClient(Client *cl);
    void runTime();

private:
    SocketManager socket;
    ClientManager cm;
};