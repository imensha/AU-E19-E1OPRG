#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <conio.h>

#define GREEN_LIGHT 1
#define YELLOW_LIGHT 2
#define RED_LIGHT 3
#define SWITCH_DELAY 5000
#define LIGHT_DELAY 1500
#define SENSOR_THRESHOLD 70

void DayMode(void);
void NightMode(void);

void InitializeLight(void);
void SwitchLight(void);
void ClearLEDs(void);
int IsCarPresent(void);

static int currentLight = 0;

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");

    // State controls which mode the program runs in
    // 1: Day Mode
    // 2: Night Mode
    // q: Quits the program
    char state = '1';
    InitializeLight();

    // Program runs until user hits 'q'
    while (state != 'q')
    {
        // Run one of the modes based on the ´state´ variable
        switch (state)
        {
            case '1':
                DayMode();
                break;
            case '2':
                NightMode();
                break;
        }

        if (_kbhit())
        {
            // Change state based on user input
            char input = _getch();
            if (input == '1' || input == '2' || input == 'q')
                state = input;

            switch (input)
            {
                case '1':
                    printf_s("%s", "Skifter til dagstilstand\n");
                    break;
                case '2':
                    printf_s("%s", "Skifter til nat-/weekendtilstand\n");
                    break;
                case 'q':
                    printf_s("%s", "Lukker programmet...");
                    break;
            }
        }
    }

	return 0;
}

// Initializes the light by clearing all LEDs and setting Green as the current light
void InitializeLight(void)
{
    ClearLEDs();
    ledOn(GREEN_LIGHT);
    currentLight = GREEN_LIGHT;
}

// Changes light depending on the status of global `currentLight` variable
// If currentLight is Green, then the light changes to Red
// If currentLight is Red, then the light changes to Green
void SwitchLight(void)
{
    // If the current light is Green, we switch to Red
    if (currentLight == GREEN_LIGHT)
    {
        // Switch Green -> Yellow
        ClearLEDs();
        ledOn(YELLOW_LIGHT);
        Wait(LIGHT_DELAY);

        // Switch Yellow -> Red
        ClearLEDs();
        ledOn(RED_LIGHT);

        currentLight = RED_LIGHT;
    }
    // Otherwise if light is Red, we switch to Green
    // NOTE: this check is 
    else if (currentLight == RED_LIGHT)
    {
        // Switch Red -> Yellow
        ledOn(YELLOW_LIGHT);
        Wait(LIGHT_DELAY);

        // Switch Yellow -> Green
        ClearLEDs();
        ledOn(GREEN_LIGHT);

        currentLight = GREEN_LIGHT;
    }
}

// Runs a cycle of Day Mode
// Day Mode switches between Green and Red at regular intervals
void DayMode(void)
{
    Wait(SWITCH_DELAY);
    SwitchLight();
}

// Runs a cycle of Night Mode
// Night Mode remains Green, unless the pedestrian button is pressed or a car comes
void NightMode(void)
{
    if (currentLight != GREEN_LIGHT)
        SwitchLight();

    // If pedestrian button is pressed or a car is present, switch to Red light
    if (keyPressed(P2) == 1 || IsCarPresent())
    {
        // Switch the light to Red, then back to Green
        SwitchLight();
        Wait(SWITCH_DELAY);
        SwitchLight();
    }
}

// Loops through all LEDs and turns them off
void ClearLEDs(void)
{
    for (int i = 1; i < 7; i++)
        ledOff(i);
}

// Checks if a car is present at the side road
int IsCarPresent(void)
{
    // Get light intensity from sensor
    int intensity = getIntensity();

    // If intensity is below the threshold, a car is present
    return (intensity < SENSOR_THRESHOLD) ? 1 : 0;
}