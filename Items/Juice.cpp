#include "Juice.hpp"

Juice::Juice(JuiceFlavorEnum flavor, JuiceSizeEnum size, float value) : Item("Juice", value)
{
    this->flavor = flavor;
    this->size = size;
}

std::string Juice::to_string()
{
    std::stringstream stream;

    stream << "x" << quantity << " ";
    stream << to_string(this->flavor) << " ";
    stream << getName() << " (";
    stream << to_string(this->size) << ") - ";
    stream << "$" << std::fixed << std::setprecision(Item::MONEY_PRECISION) << getValue();

    return stream.str();
}

bool Juice::operator==(const Juice& other) const 
{
    return flavor == other.flavor && size == other.size;
}

bool Juice::isEquals(Item* other) const
{
    if (Juice* c = dynamic_cast<Juice*>(other))
        return (c->flavor == flavor && c->size == size);
    return false;
}

Juice::JuiceFlavorEnum Juice::getFlavor()
{
    return this->flavor;
}

Juice::JuiceSizeEnum Juice::getSize()
{
    return this->size;
}

std::string Juice::get_flavors_str(bool includeIndex, int firstIndex)
{
    std::stringstream stream;

    for (int i = (int)(JuiceFlavorEnum::APPLE); i <= (int)(JuiceFlavorEnum::TAMARIND); i++)
    {
        if(includeIndex)
            stream << "(" << i+firstIndex << ") ";

        stream << to_string((JuiceFlavorEnum)i) << std::endl;
    }

    return stream.str();
}

std::string Juice::get_sizes_str(bool includeIndex, int firstIndex)
{
    std::stringstream stream;

    for (int i = (int)(JuiceSizeEnum::_250ml); i <= (int)(JuiceSizeEnum::_1l); i++)
    {
        if(includeIndex)
            stream << "(" << i+firstIndex << ") ";

        stream << to_string((JuiceSizeEnum)i) << std::endl;
    }

    return stream.str();
}

const std::string Juice::to_string(JuiceFlavorEnum flavor)
{
    switch (flavor)
    {
        case JuiceFlavorEnum::APPLE: return "Apple";
        case JuiceFlavorEnum::CHERRY: return "Cherry";
        case JuiceFlavorEnum::COCONUT: return "Coconut";
        case JuiceFlavorEnum::CUCUMBER: return "Cucumber"; 
        case JuiceFlavorEnum::GRAPE: return "Grape";
        case JuiceFlavorEnum::ORANGE: return "Orange";
        case JuiceFlavorEnum::STRAWBERRY: return "Strawberry"; 
        case JuiceFlavorEnum::GRAPEFRUIT: return "Grapefruit"; 
        case JuiceFlavorEnum::LEMONADE: return "Lemonade";  
        case JuiceFlavorEnum::PINEAPPLE: return "Pineapple"; 
        case JuiceFlavorEnum::RASPBERRY: return "Raspberry"; 
        case JuiceFlavorEnum::TAMARIND: return "Tamarind";
        default: throw std::runtime_error("Bad JuiceFlavorEnum");
    }
}

const std::string Juice::to_string(JuiceSizeEnum size)
{
    switch(size)
    {
        case JuiceSizeEnum::_250ml: return "250ml";
        case JuiceSizeEnum::_500ml: return "500ml";
        case JuiceSizeEnum::_750ml: return "750ml";
        case JuiceSizeEnum::_1l: return "1l";
        default: throw std::runtime_error("Bad JuiceSizeEnum");
    }
}