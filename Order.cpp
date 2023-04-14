#include "Order.hpp"

Order::Order(int number)
{
    this->number = number;
}

std::string Order::to_string()
{
    std::stringstream stream;

    stream << "-----------------";
    stream << std::endl << "#ticket " << number << std::endl;

    for(int i = 0; i < items.size(); i++)
    {
        stream << items[i]->to_string() << std::endl;
    }

    stream << "Total: $";
    stream << std::fixed << std::setprecision(Item::MONEY_PRECISION) << calculateTotal();
    stream << std::endl;

    return stream.str();
}

void Order::addItem(Item* item)
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

void Order::removeItem(Item* item)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i]->isEquals(item))
        {
            if(items[i]->getQuantity() > 1)
                items[i]->decreaseQuantity();
            else
                items.erase(items.begin()+i);
            return;
        }
    }
}

std::vector<Item*> Order::getItems()
{
    return this->items;
}

float Order::calculateTotal()
{
    float total = 0;
    for(int i = 0; i < items.size(); i++)
        total += items[i]->getValue();
    return total;
}

int Order::getNumber()
{
    return number;
}

void Order::setNumber(int number)
{
    this->number = number;
}