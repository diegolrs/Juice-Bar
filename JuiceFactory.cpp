#include "JuiceFactory.hpp"

JuiceFactory::JuiceFactory() {}

Juice* JuiceFactory::createJuice(Juice::JuiceFlavorEnum flavor, Juice::JuiceSizeEnum size)
{
    return new Juice(flavor, size, calculatePriceForSize(size));
}

float JuiceFactory::calculatePriceForSize(Juice::JuiceSizeEnum size)
{
    switch(size)
    {
        case Juice::JuiceSizeEnum::_250ml: return _250ml_JUICE_PRICE;
        case Juice::JuiceSizeEnum::_500ml: return _500ml_JUICE_PRICE;
        case Juice::JuiceSizeEnum::_750ml: return _750ml_JUICE_PRICE;
        case Juice::JuiceSizeEnum::_1l: return _1l_JUICE_PRICE;
        default: throw std::runtime_error("Bad JuiceSizeEnum");
    }
}