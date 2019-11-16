#include <iostream>
#include "Inventory.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Inventory product1("Nuts", 200);
    Inventory product2("Bolts", 10);

    product1.display();
    product2.display();

    for (size_t i = 0; i < 100; i++)
    {
        product1.Sale();
    }
    product1.display();

    for (size_t i = 0; i < 50; i++)
    {
        product1.Purchase();
    }
    product1.display();

    product2.Sale();
    for (size_t i = 0; i < 20; i++)
    {
        product2.Purchase();
    }
    product2.display();
    product2.Sale();
    product2.display();

    return 0;
}
