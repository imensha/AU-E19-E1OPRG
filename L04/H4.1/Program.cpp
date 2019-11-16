#include <iostream>
#include "Func.h"

int main(int argc, char const *argv[])
{
    double n1 = 54.39;
    double n2 = 0.10;

    std::cout << n1 << " contains integer part: " << getInteger(n1) << " and decimal part: " << getDecimal(n1) << std::endl;
    std::cout << n2 << " contains integer part: " << getInteger(n2) << " and decimal part: " << getDecimal(n2) << std::endl;

    return 0;
}
