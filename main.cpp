
#include <iostream>
#include "src/manager.hpp"
#include "src/client.hpp"

int main()
{
    Manager m;
    Client clientList[] = {Client("System A"), Client("System B"), Client("System C"), Client("System D")};
    m.addClient(&clientList[0]);
    m.addClient(&clientList[1]);
    m.addClient(&clientList[2]);
    m.addClient(&clientList[3]);
    m.runTime();
    return 0;
}