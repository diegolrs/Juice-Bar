#include "OrderUtils.hpp"

bool OrderUtils::containsOrderNumber(std::vector<Order*>* orders, int orderNumber)
{
    for(int i = 0; i < orders->size(); i++)
    {
        if(orders->at(i)->getNumber() == orderNumber)
        {
            return true;
        }
    }

    return false;
}

int OrderUtils::getOrderIndexPosition(std::vector<Order*>* orders, int orderNumber)
{
    for(int i = 0; i < orders->size(); i++)
    {
        if(orders->at(i)->getNumber() == orderNumber)
        {
            return i;
        }
    }

    return -1;
}