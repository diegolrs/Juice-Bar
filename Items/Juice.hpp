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

        JuiceFlavorEnum getFlavor();
        JuiceSizeEnum getSize();

        static std::string get_flavors_str(bool includeIndex=true, int firstIndex=0);
        static std::string get_sizes_str(bool includeIndex=true, int firstIndex=0);
    private:
        JuiceFlavorEnum flavor;
        JuiceSizeEnum size;

        const static std::string to_string(JuiceFlavorEnum flavor);
        const static std::string to_string(JuiceSizeEnum size);

        void setupJuiceFlavors();
        void setupJuiceSizes();
};