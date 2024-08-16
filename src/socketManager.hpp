#pragma once

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h> 
#include "types.hpp"

/**
 * SocketManager class
 * The class is used to represent (and permit personal testing of the app) the communication structure used by the manager system to receive the event signals, that 
 * is then propaged to the clients.
 * @author Mathieu Gravel
 */
class SocketManager{
    public : 
    SocketManager();
    ssize_t getNewEvents();
    private:
    void openSocket();
    void closeSocket();
    int socketConnector;
    sockaddr_in socketParams;
};