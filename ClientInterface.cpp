#include "ClientInterface.hpp"

ClientInterface::ClientInterface() {}

void ClientInterface::startRunning(std::vector<Order*>* orders) { printMainMenu(orders); }

void ClientInterface::printMainMenu(std::vector<Order*>* orders)
{
    int option;
    while(true)
    {
        ConsoleUtils::clearConsole();

        std::cout << " -------- WELCOME  -------- " << std::endl;
        std::cout << "0: Create order" << std::endl;
        std::cout << "1: Display orders" << std::endl;
        std::cout << "2: Update order" << std::endl;
        std::cout << "3: Delete order" << std::endl;
        std::cout << "4: Exit" << std::endl;
        std::cout << "Choose one option: " << std::endl;
        std::cin >> option;

        switch(option)
        {
            case 0: break;
            case 1: 
                displayOrdersMenu(orders);
                break;
            case 2: 
                updateOrdersMenu(orders);
                break;
            case 3: 
                deleteOrdersMenu(orders);
                break;
            case 4:
                std::cout << "Thank you and come back often!" << std::endl;
                return;
            default: 
                break;
        }
    }
}

void ClientInterface::displayOrders(std::vector<Order*>* orders)
{
    for(int i = 0; i < orders->size(); i++)
        std::cout << orders->at(i)->to_string();
}

void ClientInterface::displayOrdersMenu(std::vector<Order*>* orders)
{   
    ConsoleUtils::clearConsole();
    displayOrders(orders);
    ConsoleUtils::waitKey();
}

void ClientInterface::updateOrdersMenu(std::vector<Order*>* orders)
{
    int orderToUpdate;
    Order* order = nullptr;

    while(true)
    {
        ConsoleUtils::clearConsole();

        displayOrders(orders);
        std::cout << std::endl << "Choose an order ticket to update(-1 to return): ";
        std::cin >> orderToUpdate;

        if(orderToUpdate == -1)
            break;

        if(OrderUtils::containsOrderNumber(orders, orderToUpdate))
        {
            int index = OrderUtils::getOrderIndexPosition(orders, orderToUpdate);
            order = orders->at(index);
            break;
        }
    }

    updateOrder(order);
}

void ClientInterface::updateOrder(Order* order)
{
    while(true)
    {
        break;
    }
}

void ClientInterface::deleteOrdersMenu(std::vector<Order*>* orders)
{
    int orderToDelete;
    Order* order = nullptr;

    while(true)
    {
        ConsoleUtils::clearConsole();

        displayOrders(orders);
        std::cout << std::endl << "Choose an order ticket to delete(-1 to return): ";
        std::cin >> orderToDelete;

        if(orderToDelete == -1)
            break;

        if(OrderUtils::containsOrderNumber(orders, orderToDelete))
        {
            int index = OrderUtils::getOrderIndexPosition(orders, orderToDelete);
            int orderNumber = orders->at(index)->getNumber();
            orders->erase(orders->begin() + index);
            deleteSucessfullMenu(orders, orderNumber);
            break;
        }
    }
}

void ClientInterface::deleteSucessfullMenu(std::vector<Order*>* orders, int itemIndex)
{   
    std::cout << std::endl << "Ticket order #" << itemIndex << " was sucessfull deleted" << std::endl;
    ConsoleUtils::waitKey();
}