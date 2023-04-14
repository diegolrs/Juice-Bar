#pragma once
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <memory>
#include <vector>

#include "Order.hpp"
#include "Utils/StringExtensions.hpp"
#include "Utils/OrderUtils.hpp"
#include "Factories/JuiceFactory.hpp"

#define META_FILES_ADDRESS "config.meta"
#define ORDER_FILE_EXTENSION ".order"

#define JUICE_TAG = "Juice"

namespace FileHandler
{
    const std::string ORDER_DATABASE = "orders.data";
    const std::string CLIENT_DATABASE = "clients.data";

    std::vector<Order*>* readOrders(std::string address)
    {
        std::ifstream file(address);
        std::string line;

        std::vector<Order*>* orders = new std::vector<Order*>();

        if (file.is_open())
        {
            std::getline(file, line); // ignore header

            while (std::getline(file, line))
            {
                std::vector<std::string> data = StringExtensions::Split(line, ",");

                int orderNumber = std::stoi(data[0]);

                if(!OrderUtils::containsOrderNumber(orders, orderNumber))
                    orders->push_back(new Order(orderNumber));

                int idAtVector = OrderUtils::getOrderIndexPosition(orders, orderNumber);
                
                if(StringExtensions::Contains(line, "Juice"))
                {
                    int flavor = std::stoi(data[2]);
                    int size = std::stoi(data[3]);
                    int quantity = std::stoi(data[4]);
                    Juice* j = JuiceFactory::createJuice(flavor, size);
                    j->setQuantity(quantity);

                    orders->at(idAtVector)->addItem(j);
                }
            }

            file.close();
        }

        return orders;
    }

    void writeOrders(std::vector<Order*>* orders, std::string address)
    {
        std::ofstream file(address);

        // Header
        file << "order_id" << ",item_type" << ",flavor" << ",size" << ",qtd"  << std::endl;

        for(int i = 0; i < orders->size(); i++)
        {
            Order* order = orders->at(i);
            std::vector<Item*> items = order->getItems();

            for(int j = 0; j < items.size(); j++)
            {
                // Ticket Order
                file << order->getNumber()  << ",";

                // Juice
                if (Juice* juice = dynamic_cast<Juice*>(items[j]))
                {
                    file << "Juice";
                    file << "," << static_cast<int>(juice->getFlavor());
                    file << "," << static_cast<int>(juice->getSize());
                    file << "," << static_cast<int>(juice->getQuantity());
                }

                file << std::endl;
            }
        }

        file.close();
    }
};