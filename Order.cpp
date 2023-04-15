#include "Order.hpp"

Order::Order(int number)
{
    this->number = number;
    items = new std::vector<Item*>();
}

std::string Order::to_string()
{
    std::stringstream stream;

    stream << "-----------------";
    stream << std::endl << "#ticket " << number << std::endl;

    for(int i = 0; i < items->size(); i++)
    {
        stream << items->at(i)->to_string() << std::endl;
    }

    stream << "Total: $";
    stream << std::fixed << std::setprecision(Item::MONEY_PRECISION) << calculateTotal();
    stream << std::endl;

    return stream.str();
}

std::string Order::to_string_with_index()
{
    std::stringstream stream;

    for(int i = 0; i < items->size(); i++)
    {
        stream << i << ") " << items->at(i)->to_string() << std::endl;
    }

    return stream.str();
}

void Order::addItem(Item* item)
{
    for(int i = 0; i < items->size(); i++)
    {
        if(items->at(i)->isEquals(item))
        {
            items->at(i)->increaseQuantity();
            return;
        }
    }

    items->push_back(item);
}

void Order::removeItem(Item* item)
{
    for(int i = 0; i < items->size(); i++)
    {
        if(items->at(i)->isEquals(item))
        {
            if(items->at(i)->getQuantity() > 1)
                items->at(i)->decreaseQuantity();
            else
                items->erase(items->begin()+i);
            return;
        }
    }
}

void Order::setItem(Item* item, int index)
{
    items->at(index) = item;
}

std::vector<Item*>* Order::getItems()
{
    return this->items;
}

float Order::calculateTotal()
{
    float total = 0;
    for(int i = 0; i < items->size(); i++)
        total += items->at(i)->getValue();
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