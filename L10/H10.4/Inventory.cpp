#include <iostream>
#include <string>
#include "Inventory.h"
using namespace std;

const int MIN_BALANCE = 20;

Inventory::Inventory(string desc, int initialBalance) : description(desc)
{
    if (initialBalance < MIN_BALANCE)
        cout << "Item balance must be at least " << MIN_BALANCE << endl;

    balance = initialBalance;
}

void Inventory::Purchase()
{
    balance += 1;
}

void Inventory::Sale()
{
    if (balance - 1 < MIN_BALANCE)
    {
        cout << "Cannot sell when item balance is: " << getStock() << " (" << getDescription() << ")" << endl;
    }
    else
    {
        balance -= 1;
    }
}

int Inventory::getStock() const
{
    return balance;
}

string Inventory::getDescription() const
{
    return description;
}

void Inventory::setDescription(string desc)
{
    description = desc;
}

void Inventory::display()
{
    cout << getDescription() << " [Stock: " << getStock() << "]" << endl;
}
