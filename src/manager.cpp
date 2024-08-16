#include "manager.hpp"

int managerFlag = 0;

void cleanExit(int signalType)
{
    std::cout << "Termination signal received. Please wait for the clients threads to finish working before the program closes itself." << std::endl;
    managerFlag = signalType;
};

Manager::Manager()
{
    //We take control of the termination signals, in order to assure that the program will not close the client threads when they are still working on tasks.
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = cleanExit;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);
    sigaction(SIGTERM, &sigIntHandler, NULL);
};
void Manager::addClient(Client *cl)
{
    cm.subscribeClient(cl);
};
void Manager::runTime()
{
    while (managerFlag == 0)
    {

        std::cout << "Manager is currently running" << std::endl;
        /*The method of input, whether it be port communication or a random generator, can be chosen here by swaping the following 2 lines.
        with more time given, an ifndef could have been used to select a specific one at compile time.*/
        //auto eventIdentifier = socket.getNewEvents();
        int eventIdentifier = std::rand() % 4;
        if (eventIdentifier > 0)
        {
            Event ev(eventIdentifier);
            cm.postEvent(ev);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
};
