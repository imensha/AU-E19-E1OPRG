#include <iostream>
#include "Switch.h"
using namespace std;

int main(int argc, char const *argv[])
{
    while (1)
    {
        system("cls");
        cout << "Current switch status: " << Switch::mode() ? "ON" : "OFF";
    }

    return 0;
}
