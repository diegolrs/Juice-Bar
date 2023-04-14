#pragma once
#include <vector>
#include "../Order.hpp"

namespace OrderUtils
{
    bool containsOrderNumber(std::vector<Order*>* orders, int orderNumber);
    int getOrderIndexPosition(std::vector<Order*>* orders, int orderNumber);
}