#pragma once
#include <vector>
#include <algorithm>
#include "../Order.hpp"

namespace OrderUtils
{
    bool containsOrderNumber(std::vector<Order*>* orders, int orderNumber);
    int getOrderIndexPosition(std::vector<Order*>* orders, int orderNumber);
    void sortOrders(std::vector<Order*>* orders);
}