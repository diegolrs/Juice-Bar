#include "Item.hpp"

Item::Item(std::string name, float value, int quantity)
{
    this->name = name;
    this->value = value;
    this->quantity = quantity;
}

std::string Item::getName()
{
    return this->name;
}

void Item::setName(std::string name)
{
    this->name = name;
}

float Item::getValue()
{
    return this->value;
}

void Item::setValue(float value)
{
    this->value = value;
}

int Item::getQuantity()
{
    return this->quantity;
}

int Item::increaseQuantity(int amount)
{
    quantity += 1;
}