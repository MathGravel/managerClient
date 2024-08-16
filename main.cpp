
#include <iostream>
#include "src/manager.hpp"
#include "src/client.hpp"

int main()
{
    Manager m;
    Client clientList[] = {Client(), Client(), Client(), Client()};
    m.addClient(&clientList[0]);
    m.addClient(&clientList[1]);
    m.addClient(&clientList[2]);
    m.addClient(&clientList[3]);
    m.runTime();
    return 0;
}