#pragma once
#include <string>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <memory>

#include "Item.hpp"

class Juice : public Item
{
    public:
        enum class JuiceFlavorEnum
        {  
            APPLE, CHERRY, COCONUT, CUCUMBER, GRAPE, ORANGE, STRAWBERRY, 
            GRAPEFRUIT, LEMONADE,  PINEAPPLE, RASPBERRY, TAMARIND
        };
        
        enum class JuiceSizeEnum { _250ml, _500ml, _750ml, _1l };

        Juice(JuiceFlavorEnum flavor, JuiceSizeEnum size, float value);

        std::string to_string() override;
        bool isEquals(Item* other) const override;

        bool operator==(const Juice& other) const;
    private:
        JuiceFlavorEnum flavor;
        JuiceSizeEnum size;

        std::string to_string(JuiceFlavorEnum flavor);
        std::string to_string(JuiceSizeEnum size);

        void setupJuiceFlavors();
        void setupJuiceSizes();
};