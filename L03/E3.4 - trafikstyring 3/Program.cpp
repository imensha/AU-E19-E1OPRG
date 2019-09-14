#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <conio.h>

#define DEBUG 1

#define GREEN_LIGHT 4
#define YELLOW_LIGHT 5
#define RED_LIGHT 6
#define SWITCH_DELAY 5000
#define LIGHT_DELAY 1500
#define SENSOR_THRESHOLD 75

void GreenToRed(void);
void RedToGreen(void);
void clearLEDs(void);
int IsCarPresent(void);

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");

    // Start på grønt lys
    clearLEDs();
    ledOn(GREEN_LIGHT);

    while (1)
    {
        // Vent på tryk på fodgængerknappen eller at der kommer en bil
        while (keyPressed(P2) != 1 && !IsCarPresent()) {}

        GreenToRed();
        Wait(SWITCH_DELAY);
        RedToGreen();
    }

	return 0;
}

// Starter et skift fra grønt til rødt lys
void GreenToRed(void)
{
    if (DEBUG)
        printf_s("Skifter fra gr%snt til r%sdt\n", "\x9B", "\x9B");

    clearLEDs();

    // tænd grøn lampe
    ledOn(GREEN_LIGHT);
    Wait(LIGHT_DELAY);

    // sluk grøn lampe og tænd gul lampe
    ledOff(GREEN_LIGHT);
    ledOn(YELLOW_LIGHT);
    Wait(LIGHT_DELAY);
    
    // sluk gul lampe og tænd rød lampe
    ledOff(YELLOW_LIGHT);
    ledOn(RED_LIGHT);
}

// Starter et skift fra rødt til grønt lys
void RedToGreen(void)
{
    if (DEBUG)
        printf_s("Skifter fra r%sdt til gr%snt\n", "\x9B", "\x9B");

    clearLEDs();

    ledOn(RED_LIGHT);
    Wait(LIGHT_DELAY);
    
    ledOn(YELLOW_LIGHT);
    Wait(LIGHT_DELAY);

    clearLEDs();
    ledOn(GREEN_LIGHT);
}

// Slukker alle LED'er
void clearLEDs(void)
{
    for (int i = 1; i < 7; i++)
    {
        ledOff(i);
    }
}

int IsCarPresent(void)
{
    int intensity = getIntensity();

    return (intensity < SENSOR_THRESHOLD) ? 1 : 0;
}