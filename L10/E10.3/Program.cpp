#include <iostream>
#include "Led.h"
using namespace std;

#define TESTING_DELAY 1000

int main(int argc, char const *argv[])
{
    // Create Led with valid arg
    Led valid(LD3);
    // Create Led with valid arg for Led 6
    Led valid6(LD6);
    // Create Led with invalid arg, defaults to Led 1
    Led invalid(10);

    // Testing instance with LD3
    cout << "Testing LED3 on/off" << endl;
    valid.on();
    Wait(TESTING_DELAY);
    valid.off();
    cout << "Testing LED3 on/off with intensity" << endl;
    valid.on(60);
    Wait(TESTING_DELAY);
    valid.off();
    Wait(TESTING_DELAY);

    // Testing instance with LD6
    cout << "Testing LED6 on/off" << endl;
    valid6.on();
    Wait(TESTING_DELAY);
    valid6.off();
    Wait(TESTING_DELAY);
    cout << "Testing LED6 on/off with intensity" << endl;
    valid6.on(75);
    Wait(TESTING_DELAY);
    cout << "Testing LED6 on/off with invalid intensity <60" << endl;
    valid6.on(10);
    Wait(TESTING_DELAY);
    valid6.off();
    cout << "Testing LED6 on/off with invalid intensity >100" << endl;
    valid6.on(150);
    Wait(TESTING_DELAY);
    valid6.off();
    Wait(TESTING_DELAY);

    // Testing instance with invalid arg, defaulting to LD1
    cout << "Testing LED1 on/off";
    invalid.on();
    Wait(TESTING_DELAY);
    invalid.off();
    cout << "Testing LED4 on/off with intensity" << endl;
    invalid.on(60);
    Wait(TESTING_DELAY);
    invalid.off();
    Wait(TESTING_DELAY);

    return 0;
}
