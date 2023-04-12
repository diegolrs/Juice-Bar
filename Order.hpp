#pragma once
#include <string>
#include <vector>
#include "Item.hpp"

class Order
{
    public:
        Order(int number)
        {
            this->number = number;
        }
        
        void addItem(Item* item)
        {
            for(int i = 0; i < items.size(); i++)
            {
                if(items[i]->isEquals(item))
                {
                    items[i]->increaseQuantity();
                    return;
                }
            }

            items.push_back(item);
        }

        float calculateTotal()
        {
            float total = 0;
            for(int i = 0; i < items.size(); i++)
                total += items[i]->getValue();
            return total;
        }
    private:
        int number;
        std::vector<Item*> items;
};
