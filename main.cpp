#include <iostream>
#include <string>
#include <vector>

#include "JuiceFactory.hpp"
#include "Order.hpp"
#include "FileHandler.hpp"

using namespace std;

int main() 
{
    JuiceFactory* factory = new JuiceFactory();
    Order* order = new Order(1);

    Juice* j = factory->createJuice(Juice::JuiceFlavorEnum::CHERRY, Juice::JuiceSizeEnum::_250ml);
    Item* j2 = factory->createJuice(Juice::JuiceFlavorEnum::CHERRY, Juice::JuiceSizeEnum::_250ml);
    Item* j3 = factory->createJuice(Juice::JuiceFlavorEnum::APPLE, Juice::JuiceSizeEnum::_250ml);

    order->addItem(j);
    order->addItem(j2);
    order->addItem(j3);
    cout << order->to_string();

    order->removeItem(j2);
    order->removeItem(j2);
    order->removeItem(j2);
    cout << order->to_string();

    FileHandler::writeOrder(order, "order1.order");
    
    return 0;
}