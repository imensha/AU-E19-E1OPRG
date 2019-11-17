#pragma comment(lib, "RaspberryPI.lib")
#include <RaspberryDLL.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define DIE_MIN 1
#define DIE_MAX 6

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    for (size_t i = 0; i < 6; i++)
    {
        ledOff(i + 1);
    }

    while (1)
    {
        int previousThrow = DIE_MIN;

        // Roll die until key P1 is pressed
        while (!keyPressed(1))
        {
            int currentThrow = rand() % (DIE_MAX + DIE_MIN);
            ledOff(previousThrow);
            Wait(10);
            ledOn(currentThrow);

            previousThrow = currentThrow;
        }

        // Wait for key P1 to be pressed again to reroll die
        while (!keyPressed(1))
        {
        }
    }

    return 0;
}
