#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Items/Item.hpp"

class Order
{
    public:
        Order(int number=-1);
        std::string to_string();

        void addItem(Item* item);
        void removeItem(Item* item);
        std::vector<Item*> getItems();

        int getNumber();
        void setNumber(int number);
        float calculateTotal();
    private:
        int number;
        std::vector<Item*> items;
};