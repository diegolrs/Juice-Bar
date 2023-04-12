#include <iostream>
#include <string>
#include <vector>

#include "JuiceFactory.hpp"
#include "Order.hpp"

using namespace std;

int main() 
{
    Juice* j = new Juice(Juice::JuiceFlavorEnum::CHERRY, Juice::JuiceSizeEnum::_250ml, 25);
    cout << j->to_string();

    Item* j2 = new Juice(Juice::JuiceFlavorEnum::CHERRY, Juice::JuiceSizeEnum::_500ml, 57.58);
    cout << endl << j2->to_string();

    cout << endl << j->isEquals(j2);
    
    return 0;
}