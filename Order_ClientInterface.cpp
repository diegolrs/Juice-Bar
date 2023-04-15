#include "Order_ClientInterface.hpp"

Order_ClientInterface::Order_ClientInterface() {}

void Order_ClientInterface::startRunning(Order* order)
{
    printOrderMenu(order);
}

void Order_ClientInterface::printOrderMenu(Order* order)
{
    int option;
    while(true)
    {
        ConsoleUtils::clearConsole();

        std::cout << "0: Create item" << std::endl;
        std::cout << "1: Display items" << std::endl;
        std::cout << "2: Update item" << std::endl;
        std::cout << "3: Delete item" << std::endl;
        std::cout << "4: Return" << std::endl;
        std::cout << "Choose one option: " << std::endl;
        std::cin >> option;

        switch(option)
        {
            case 0: break;
            case 1:
                ConsoleUtils::clearConsole();
                displayOrderItems(order);
                ConsoleUtils::waitKey();
                break;
            case 4:
                return;
            default:
                break;
        }
    }
}

void Order_ClientInterface::displayOrderItems(Order* order)
{
    std::cout << order->to_string();
}

void Order_ClientInterface::deleteOrderItems(Order* order)
{
    std::vector<Item*>* items = order->getItems();
    
    if(items->size() == 0)
    {
        ConsoleUtils::clearConsole();
        std::cout << "There is no item to delete" << std::endl;
        ConsoleUtils::waitKey();
        return;
    }

    int itemIndexToDelete;
    Item* item = nullptr;

    while(true)
    {
        ConsoleUtils::clearConsole();
        displayOrderItems(order);
        std::cout << std::endl << "Choose an order ticket to delete(-1 to return): ";
        std::cin >> itemIndexToDelete;

        if(itemIndexToDelete == -1)
            break;

        if(items->size() < itemIndexToDelete)
        {
            items->erase(items->begin() + itemIndexToDelete);
            deleteSucessfullMenu(order, itemIndexToDelete);
            break;
        }
    }
}

void Order_ClientInterface::deleteSucessfullMenu(Order* order, int itemIndex)
{
    std::cout << std::endl << "Item #" << itemIndex << " was sucessfull deleted" << std::endl;
    ConsoleUtils::waitKey();
}