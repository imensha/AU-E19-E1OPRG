#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <conio.h>

void Stepper(void);
void LightSensitive(void);
void ShowTemperature(void);

void SwitchAllOff(void);
void Fill(int);

int main(void)
{
    if (!Open())
    {
        printf("Error with connection\n");
        exit(1);
    }

    printf("Connected to Raspberry Pi\n");

    // To do your code
    while (true)
    {
        if (keyPressed(2) == 1)
        {
            ShowTemperature();
        }
        else if (switchOn() == 1)
        {
            LightSensitive();
        }
        else
        {
            Stepper();
        }
    }

    return 0;
}

void Stepper(void)
{
    for (int i = 1; i < 7; i++)
    {
        ledOn(i);

        if (i > 1)
        {
            ledOff(i - 1);
        }

        Wait(100);
    }

    for (int i = 6; i > 0; i--)
    {
        ledOn(i);

        if (i < 6)
        {
            ledOff(i + 1);
        }

        Wait(100);
    }
}

void LightSensitive(void)
{
    int STEP = 9;
    int MIN = 45;

    SwitchAllOff();

    int ambience = getIntensity();
    
    printf_s("Current ambience: %d\n", ambience);

    if (ambience < MIN + STEP)
    {
        Fill(1);
    }
    else if (ambience < MIN + 2 * STEP)
    {
        Fill(2);
    }
    else if (ambience < MIN + 3 * STEP)
    {
        Fill(3);
    }
    else if (ambience < MIN + 4 * STEP)
    {
        Fill(4);
    }
    else if (ambience < MIN + 5 * STEP)
    {
        Fill(5);
    }
    else if (ambience <= MIN + 6 * STEP)
    {
        Fill(6);
    }
}

void ShowTemperature(void)
{
    double temp = getTemperature();

    SwitchAllOff();

    if (temp > 0 && temp < 6)
    {
        Fill(1);
    }
    else if (temp > 5 && temp < 11)
    {
        Fill(2);
    }
    else if (temp > 10 && temp < 16)
    {
        Fill(3);
    }
    else if (temp > 15 && temp < 21)
    {
        Fill(4);
    }
    else if (temp > 20 && temp < 26)
    {
        Fill(5);
    }
    else if (temp > 25 && temp < 31)
    {
        Fill(6);
    }
}

// Turns off all LEDs
void SwitchAllOff(void)
{
    for (int i = 1; i < 7; i++)
    {
        ledOff(i);
    }
}

// Fills LEDs from left to right up to max
void Fill(int max)
{
    if (max < 0 || max > 6)
    {
        printf_s("max must be between 0-6");
        return;
    }

    for (int i = 0; i < max; i++)
    {
        ledOn(i + 1);
    }
}