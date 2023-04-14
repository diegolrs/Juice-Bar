#include <iostream>
#include <string>
#include <vector>

#include "JuiceFactory.hpp"
#include "Order.hpp"
#include "FileHandler.hpp"

using namespace std;

void testCases()
{
    Order* order = new Order(1);

    Juice* j = JuiceFactory::createJuice(Juice::JuiceFlavorEnum::CHERRY, Juice::JuiceSizeEnum::_250ml);
    Item* j2 = JuiceFactory::createJuice(Juice::JuiceFlavorEnum::CHERRY, Juice::JuiceSizeEnum::_250ml);
    Item* j3 = JuiceFactory::createJuice(Juice::JuiceFlavorEnum::APPLE, Juice::JuiceSizeEnum::_250ml);

    order->addItem(j);
    order->addItem(j2);
    order->addItem(j3);
    cout << order->to_string();
}

int main() 
{
    vector<Order*>* orders = FileHandler::readOrders("order1.order");

    for(int i = 0; i < orders->size(); i++)
        cout << orders->at(i)->to_string();

    FileHandler::writeOrders(orders, "order1.order");
    
    return 0;
}