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
        std::cout << "4: Modify item quantity" << std::endl;
        std::cout << "5: Return to main menu" << std::endl;
        std::cout << "Choose one option: " << std::endl;
        std::cin >> option;

        switch(option)
        {
            case 0: 
                displayCreateMenu(order);
                break;
            case 1:
                ConsoleUtils::clearConsole();
                displayOrderItems(order);
                ConsoleUtils::waitKey();
                break;
            case 2:
                displayUpdateMenu(order);
                break;
            case 3:
                deleteOrderItems(order);
                break;
            case 4:
                modifyItemQuantityMenu(order);
                break;
            case 5:
                return;
            default:
                break;
        }
    }
}

void Order_ClientInterface::displayCreateMenu(Order* order)
{
    Juice* j = createJuice();
    if(j != nullptr)
    {
        order->addItem(j);
        onCreationSucessfullMenu(j);
    }
    else
        onCreationErrorMenu(nullptr);
}

void Order_ClientInterface::displayUpdateMenu(Order* order)
{
    std::vector<Item*>* items = order->getItems();
    
    if(items->size() == 0)
    {
        ConsoleUtils::clearConsole();
        std::cout << "There is no item to update" << std::endl;
        ConsoleUtils::waitKey();
        return;
    }

    int itemIndexToUpdate;
    Item* itemToModify = nullptr; 
    while(true)
    {
        ConsoleUtils::clearConsole();
        displayOrderItemsWithIndex(order);
        std::cout << std::endl << "Choose an order ticket to update(-1 to return): ";
        std::cin >> itemIndexToUpdate;

        if(itemIndexToUpdate == -1)
            break;

        if(items->size() > itemIndexToUpdate)
        {
            itemToModify = items->at(itemIndexToUpdate);
            break;
        }
    }

    if (Juice* juice = dynamic_cast<Juice*>(itemToModify))
    {
        Juice* aux = createJuice();

        if(aux != nullptr)
        {
            order->setItem(aux, itemIndexToUpdate);
            onUpdateSucessfullMenu(itemToModify);
        }      
        else
        {
            onUpdateErrorMenu(itemToModify);
        }
    }
}

Juice* Order_ClientInterface::createJuice()
{
    int flavor;
    int size;
    while(true)
    {
        ConsoleUtils::clearConsole();
        std::cout << Juice::get_flavors_str() << std::endl;
        std::cout << "Choose Juice Flavor: ";
        std::cin >> flavor;

        ConsoleUtils::clearConsole();
        std::cout << Juice::get_sizes_str() << std::endl;
        std::cout << "Choose Juice Size: ";
        std::cin >> size;

        try
        {
            Juice *j = JuiceFactory::createJuice(flavor, size);
            return j;
        }
        catch(const std::exception& e)
        {
            return nullptr;
        }
    } 
}

void Order_ClientInterface::onCreationSucessfullMenu(Item* item)
{
    ConsoleUtils::clearConsole();
    std::cout << std::endl << item->getName() << " was sucessfull created" << std::endl;
    ConsoleUtils::waitKey();
}

void Order_ClientInterface::onCreationErrorMenu(Item* item)
{
    ConsoleUtils::clearConsole();
    std::cerr << "Error creating item, invalid inputs was inserted." << std::endl;
    ConsoleUtils::waitKey();
}

void Order_ClientInterface::onUpdateSucessfullMenu(Item* item)
{
    ConsoleUtils::clearConsole();
    std::cout << std::endl << item->getName() << " was sucessfull updated" << std::endl;
    ConsoleUtils::waitKey();
}

void Order_ClientInterface::onUpdateErrorMenu(Item* item)
{
    ConsoleUtils::clearConsole();
    std::cerr << "Error updating item, invalid inputs was inserted." << std::endl;
    ConsoleUtils::waitKey();
}

void Order_ClientInterface::displayOrderItems(Order* order)
{
    std::cout << order->to_string();
}

void Order_ClientInterface::displayOrderItemsWithIndex(Order* order)
{
    std::cout << order->to_string_with_index();
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
    while(true)
    {
        ConsoleUtils::clearConsole();
        displayOrderItemsWithIndex(order);
        std::cout << std::endl << "Choose an order ticket to delete(-1 to return): ";
        std::cin >> itemIndexToDelete;

        if(itemIndexToDelete == -1)
            break;

        if(items->size() > itemIndexToDelete)
        {
            Item* item = items->at(itemIndexToDelete);
            //order->removeItem(item);
            items->erase(items->begin()+itemIndexToDelete);
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

void Order_ClientInterface::modifyItemQuantityMenu(Order* order)
{
    std::vector<Item*>* items = order->getItems();

    if(items->size() == 0)
    {
        std::cout << "There is no item to modify" << std::endl;
        ConsoleUtils::waitKey();
        return;
    }

    int itemIndexToModify;
    Item* itemToModify = nullptr;

    while(true)
    {
        ConsoleUtils::clearConsole();
        displayOrderItemsWithIndex(order);
        std::cout << std::endl << "Choose an order ticket to modify(-1 to return): ";
        std::cin >> itemIndexToModify;

        if(itemIndexToModify == -1)
            return;

        // invalid index  
        if(itemIndexToModify >= items->size() || itemIndexToModify < 0)
            continue;

        itemToModify = items->at(itemIndexToModify);
        break;
    } 

    if(itemToModify != nullptr)
        insertItemQuantityMenu(order, itemToModify);
}

void Order_ClientInterface::insertItemQuantityMenu(Order* order, Item* item)
{
    int newQuantity = -1;

    while(newQuantity < 0)
    {
        ConsoleUtils::clearConsole();
        std::cout << item->to_string() << std::endl;
        std::cout << "Insert new quantity: ";

        std::cin >> newQuantity;
    }

    item->setQuantity(newQuantity);
    
    if(newQuantity <= 0)
        order->removeItem(item);
}