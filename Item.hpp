#pragma once
#include <string>

class Item
{
    public:
        static const int MONEY_PRECISION = 2;

        Item(std::string name, float value, int quantity=1);
        std::string getName();
        void setName(std::string name);
        float getValue();
        void setValue(float value);

        int getQuantity();
        int increaseQuantity(int amount=1);
        int decreaseQuantity(int amount=1);

        virtual std::string to_string() = 0;
        virtual bool isEquals(Item* other) const = 0;
    protected:
        std::string name;
        float value;
        int quantity;
};