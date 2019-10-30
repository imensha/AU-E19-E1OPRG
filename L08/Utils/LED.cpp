#pragma comment(lib, "RaspberryPI.lib")
#include <RaspberryDLL.h>
#include "LED.h"

#define NUM_GREEN 5
#define NUM_RED 1

const int GREEN_LED[] = { 1, 2, 3, 4, 5 };
const int RED_LED[] = { 6 };

void allLedOn()
{
    for (int i = 0; i < 7; i++)
    {
        ledOn(i);
    }
}

void allLedOff()
{
}

void blinkAll(int led, int blinks, int delay)
{
    ledOff(led);

    for (int i = 0; i < blinks; i++)
    {
        ledOn(led);
        Wait(delay);
        ledOff(led);
        Wait(delay);
    }
}

void blinkGreen(int blinks, int delay)
{
    for (int i = 0; i < NUM_GREEN; i++)
    {
        ledOff(GREEN_LED[i]);
    }

    for (int i = 0; i < blinks; i++)
    {
        // Turn LEDs on
        for (int j = 0; j < NUM_GREEN; j++)
        {
            ledOn(GREEN_LED[j]);
        }
        Wait(delay);

        // Turn LEDs off
        for (int j = 0; j < NUM_GREEN; j++)
        {
            ledOff(RED_LED[j]);
        }
        Wait(delay);
    }
}