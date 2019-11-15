#include <iostream>
#include "Key.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // Create a Key with valid constructor argument
    Key validKey(P2);
    // Create a Key with invalid constructor argument
    Key invalidKey(5);

    cout << "Testing valid class" << endl
         << "Waiting for P2 pressed...";
    while (!validKey.pressed())
    {
    }
    cout << "PRESSED" << endl
         << endl;

    cout << "Testing invalid argument class" << endl
         << "Waiting for P1 pressed...";
    while (!invalidKey.pressed())
    {
    }
    cout << "PRESSED" << endl;

    return 0;
}
