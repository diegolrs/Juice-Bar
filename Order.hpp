#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Item.hpp"

class Order
{
    public:
        Order(int number);
        void addItem(Item* item);
        void removeItem(Item* item);
        std::string to_string();
        float calculateTotal();
    private:
        int number;
        std::vector<Item*> items;
};