#pragma once
#include <vector>
#include <iostream>
#include "Order.hpp"
#include "Items/Item.hpp"
#include "Utils/OrderUtils.hpp"
#include "Utils/ConsoleUtils.hpp"

class Order_ClientInterface
{
    public:
        Order_ClientInterface();
        void startRunning(Order* order);
    private:
        void printOrderMenu(Order* order);
        void displayOrderItems(Order* order);
        void deleteOrderItems(Order* order);
        void deleteSucessfullMenu(Order* order, int itemIndex);
};