#pragma once
#include <vector>
#include <iostream>
#include "Order.hpp"
#include "Items/Item.hpp"
#include "Utils/OrderUtils.hpp"
#include "Utils/ConsoleUtils.hpp"
#include "Order_ClientInterface.hpp"

class ClientInterface
{
    public:
        ClientInterface();
        void startRunning(std::vector<Order*>* orders);
    private:
        void printMainMenu(std::vector<Order*>* orders);
        void createOrder(std::vector<Order*>* orders);
        void displayOrders(std::vector<Order*>* orders);
        void displayOrdersMenu(std::vector<Order*>* orders);
        void updateOrdersMenu(std::vector<Order*>* orders);
        void deleteOrdersMenu(std::vector<Order*>* orders);
        void deleteSucessfullMenu(std::vector<Order*>* orders, int itemIndex);
        void displayOrderClientInterface(Order* order);
};