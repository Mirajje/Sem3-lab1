#include <iostream>
#include "SortsTests.hpp"
#include "Interface.hpp"
#include <algorithm>

int main (int argc, char* args[])
{
    runTimeTests<int>();
    SortsTests::allTestsTogether();

    std::cout << "\nChoose array data type: 1 - int, 2 - float, 3 - string\n";
    long n = -1;
    while (n <= 0 || n > 3)
        input(&n);

    switch (n)
    {
        case 1:
            menu<int>();
            break;

        case 2:
            menu<float>();
            break;

        case 3:
            menu<std::string>();
            break;

        default:
            return -1;
    }
    return 0;

}