#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Pi_Emulator.h"

#define LD1 1
#define LD2 2
#define LD3 3
#define LD4 4
#define LD5 5
#define LD6 6
#define P1 1
#define P2 2

int switchStatus = 0;

srand(time(void));

int Open()
{
    return 0;
}

void ledOn(int id)
{
    printf_s("[Pi_Emulator][LED %d] Status: ON, Intensity: 100\n", id);
}

void ledOn(int id, int intensity)
{
    printf_s("[Pi_Emulator][LED %d] Status: ON, Intensity : %d\n", id, intensity);
}

void ledOff(int id)
{
    printf_s("[Pi_Emulator][LED %d] Status: OFF\n", id);
}

int keyPressed(int id)
{
    return 0;
}

int switchOn()
{
    return switchStatus;
}

void flipSwitch()
{
    switchStatus ^= 1;
}

double getTemperature()
{
    return rand() % 30;
}

int getIntensity()
{
    return rand() % 100;
}

void Wait(int ms)
{
    printf_s("[Pi_Emulator] Waiting %d ms\n", ms);
}
