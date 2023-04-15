// @autor: Diego Reis
// 04/14/2023

#include <iostream>
#include <string>
#include <vector>
#include "Order.hpp"
#include "FileHandler.hpp"
#include "ClientInterface.hpp"

#define FILE_ADDRESS "data.order"

using namespace std;

int main() 
{
    ClientInterface* client = new ClientInterface();
    vector<Order*>* orders = FileHandler::readOrders(FILE_ADDRESS);
    client->startRunning(orders);
    FileHandler::writeOrders(orders, FILE_ADDRESS);
    
    return 0;
}