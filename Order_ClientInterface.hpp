#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include "Order.hpp"
#include "Items/Item.hpp"
#include "Items/Juice.hpp"
#include "Factories/JuiceFactory.hpp"
#include "Utils/OrderUtils.hpp"
#include "Utils/ConsoleUtils.hpp"

class Order_ClientInterface
{
    public:
        Order_ClientInterface();
        void startRunning(Order* order);
    private:
        void printOrderMenu(Order* order);

        Juice* createJuice();
        void displayCreateMenu(Order* order);
        void onCreationSucessfullMenu(Item* item);
        void onCreationErrorMenu(Item* item);

        void displayOrderItems(Order* order);
        void displayOrderItemsWithIndex(Order* order);

        void displayUpdateMenu(Order* order);
        void onUpdateSucessfullMenu(Item* item);
        void onUpdateErrorMenu(Item* item);

        void deleteOrderItems(Order* order);
        void deleteSucessfullMenu(Order* order, int itemIndex);

        void modifyItemQuantityMenu(Order* order);
        void insertItemQuantityMenu(Order* order, Item* item);
};