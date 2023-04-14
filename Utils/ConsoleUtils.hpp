#pragma once
#include <iostream>

#if _WIN32 // windows 32/64
    #include <conio.h>
#endif

namespace ConsoleUtils
{
    void clearConsole();
    void waitKey();
}