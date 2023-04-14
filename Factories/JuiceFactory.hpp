#pragma once
#include "../Items/Juice.hpp"

namespace JuiceFactory
{
        Juice* createJuice(Juice::JuiceFlavorEnum flavor, Juice::JuiceSizeEnum size);
        Juice* createJuice(int flavor, int size);

        const float _250ml_JUICE_PRICE = 4.99f;
        const float _500ml_JUICE_PRICE = 6.99f;
        const float _750ml_JUICE_PRICE = 8.99f;
        const float _1l_JUICE_PRICE = 12.99f;

        float calculatePriceForSize(Juice::JuiceSizeEnum size);
};