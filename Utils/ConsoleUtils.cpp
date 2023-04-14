#include "ConsoleUtils.hpp"

void ConsoleUtils::clearConsole()
{
#if __linux__
    system("clear");
#elif _WIN32 // windows 32/64
    system("cls");
#endif
}

void ConsoleUtils::waitKey()
{
#if __linux__
    std::cout << "Press enter to continue...";
    std::cin.get();
#elif _WIN32 // windows 32/64
    std::cout << "Press any key to return...";
    getch();
#endif
}