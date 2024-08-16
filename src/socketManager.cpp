

#include "socketManager.hpp"

SocketManager::SocketManager()
{
    //AF_INET was selected to simplify the testing phase.
    socketConnector = socket(AF_INET, SOCK_STREAM, 0);
    socketParams.sin_family = AF_INET;
    socketParams.sin_port = htons(constants::PORT);
    socketParams.sin_addr.s_addr = INADDR_ANY;

    if (bind(socketConnector, (struct sockaddr *)&socketParams, sizeof(sockaddr)) < 0)
    {
        std::cout << "Error, failed to bind the socket to the port" << std::endl;
        exit(EXIT_FAILURE);
    }
    // Start listening. Hold at most 10 connections in the queue
    if (listen(socketConnector, 10) < 0)
    {
        std::cout << "Error, failed to listen to the socket." << std::endl;
        exit(EXIT_FAILURE);
    }
}

ssize_t SocketManager::getNewEvents()
{
    auto addrlen = sizeof(sockaddr);
    // Since the manager main job is receiving event informations to dispatch to the clients, it was judged uneeded at this stage to remove the listener from the main thread.
    int connection = accept(socketConnector, (struct sockaddr *)&socketParams, (socklen_t *)&addrlen);
    if (connection < 0 && managerFlag == 0)
    {
        std::cout << "There was an error reading the events socket. The program will close itself as an security measure. " << std::endl;
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    auto message = read(connection, buffer, 100);
    close(connection);
    return message;
}