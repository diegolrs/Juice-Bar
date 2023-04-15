#include "OrderUtils.hpp"

namespace OrderUtils
{
// Private Members
    namespace
    {
        bool sortOrdersFunction(Order* a, Order*b)
        {
            return a->getNumber() < b->getNumber();
        }
    }

// Public Members
    bool containsOrderNumber(std::vector<Order*>* orders, int orderNumber)
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

    int getOrderIndexPosition(std::vector<Order*>* orders, int orderNumber)
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

    void sortOrders(std::vector<Order*>* orders)
    {
        std::sort(orders->begin(), orders->end(), sortOrdersFunction);
    }
}