#pragma once
#include <fstream>
#include <string>
#include "Order.hpp"

#define META_FILES_ADDRESS "config.meta"

namespace FileHandler
{
    // void readMetaFile(std::string address)
    // {
    //     std::ifstream file(META_FILES_ADDRESS);
    //     std::string line;

    //     if (file.is_open())
    //     {
    //         while (std::getline(file,line))
    //         {

    //         }

    //         file.close();
    //     }
    // }

    // void writeDefaultMetaConfig()
    // {
    //     std::ofstream file(address);
    //     file << order->to_string();
    //     file.close();
    // }

    void writeOrder(Order* order, std::string address)
    {
        std::ofstream file(address);
        file << order->to_string();
        file.close();
    }
};