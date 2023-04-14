// @autor: Diego Reis
// 04/14/2023

#include <iostream>
#include <string>
#include <vector>
#include "Order.hpp"
#include "FileHandler.hpp"
#include "ClientInterface.hpp"

using namespace std;

int main() 
{
    ClientInterface* client = new ClientInterface();
    vector<Order*>* orders = FileHandler::readOrders("order1.order");
    client->startRunning(orders);
    FileHandler::writeOrders(orders, "order2.order");
    
    return 0;
}