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
            case 0: 
                createOrder(orders);
                break;
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

void ClientInterface::createOrder(std::vector<Order*>* orders)
{
    int i;
    for(i = 1;;i++)
    {
        if(!OrderUtils::containsOrderNumber(orders, i))
        {
            orders->push_back(new Order(i));
            OrderUtils::sortOrders(orders);
            break;
        }
    }

    ConsoleUtils::clearConsole();
    std::cout << "A ticket order was created with number #" << i << std::endl;
    ConsoleUtils::waitKey();
}

void ClientInterface::displayOrders(std::vector<Order*>* orders)
{
    for(int i = 0; i < orders->size(); i++)
        std::cout << orders->at(i)->to_string();
}

void ClientInterface::displayOrdersMenu(std::vector<Order*>* orders)
{   
    ConsoleUtils::clearConsole();
    if(orders->size() == 0)
        std::cout << "There is no order to display" << std::endl;
    displayOrders(orders);
    ConsoleUtils::waitKey();
}

void ClientInterface::updateOrdersMenu(std::vector<Order*>* orders)
{
    if(orders->size() == 0)
    {
        ConsoleUtils::clearConsole();
        std::cout << "There is no order to update" << std::endl;
        ConsoleUtils::waitKey();
        return;
    }

    int orderToUpdate;
    Order* order = nullptr;

    while(true)
    {
        ConsoleUtils::clearConsole();

        displayOrders(orders);
        std::cout << std::endl << "Choose an order ticket to update(-1 to return): ";
        std::cin >> orderToUpdate;

        if(orderToUpdate == -1)
            return;

        if(OrderUtils::containsOrderNumber(orders, orderToUpdate))
        {
            int index = OrderUtils::getOrderIndexPosition(orders, orderToUpdate);
            order = orders->at(index);
            break;
        }
    }

    displayOrderClientInterface(order);
}

void ClientInterface::deleteOrdersMenu(std::vector<Order*>* orders)
{
    if(orders->size() == 0)
    {
        ConsoleUtils::clearConsole();
        std::cout << "There is no order to delete" << std::endl;
        ConsoleUtils::waitKey();
        return;
    }

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
            OrderUtils::sortOrders(orders);
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

void ClientInterface::displayOrderClientInterface(Order* order)
{
    Order_ClientInterface* orderInterface = new Order_ClientInterface();
    orderInterface->startRunning(order);
}