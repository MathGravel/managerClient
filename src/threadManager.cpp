#include "threadManager.hpp"

ClientManager::ClientManager()
{
}

/*Code was commented out since its job was automatically done by jthread mechanisms.
ClientManager::~ClientManager()
{
    for (auto &it : clientThreads)
    {
        it.join();
    }
}*/

void ClientManager::postEvent(const Event &ev)
{
    for (const auto &it : clients)
    {
        it->addEvent(ev);
    }
}

void ClientManager::subscribeClient(Client *cl)
{
    std::mutex temp;
    std::lock_guard<std::mutex> lock(temp);
    clients.push_front(cl);
    clientThreads.emplace_back(&Client::attach, std::ref(cl));
}

bool ClientManager::clientFinishedWorking()
{
    for (const auto &it : clients)
    {
        if (it->checkWork())
            return false;
    }
    return true;
}