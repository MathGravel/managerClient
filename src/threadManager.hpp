#pragma once

#include <forward_list>
#include <vector>
#include <syncstream>
#include <utility>
#include <mutex>
#include <thread>
#include "client.hpp"
#include "event.hpp"

/**
 * Client Manager class
 * Simple thread pool implementation mixed with an event dispatcher system. This class permit the client class to subscribe to a dispatch system in order to
 * receive new Event data in real-time, while also storing the application threads.
 * Note, the thread pool implementation was chosen in order to give a seperate thread to each client in the app. If the system were to be changed to support
 * an exponential number of clients, the threading system would be modified to remove the unique thread per client structure, and permit the client themselves
 * to create tasks that would then be send to the thread pool.
 * @author Mathieu Gravel
 */
class ClientManager
{
public:
	ClientManager();
	void subscribeClient(Client *cl);
	void postEvent(const Event &ev);
	bool clientFinishedWorking();
	//~ClientManager();

private:
	std::forward_list<Client *> clients;

	//jThread was used to offer a better control of the tread termination, that would have needed additional work with conventional threads.
	std::vector<std::jthread> clientThreads;
};
