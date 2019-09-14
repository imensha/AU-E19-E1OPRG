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

void GreenToRed(void);
void RedToGreen(void);
void clearLEDs(void);

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");

    while (1)
    {
        RedToGreen();
        Wait(SWITCH_DELAY);
        GreenToRed();
        Wait(SWITCH_DELAY);
    }

	return 0;
}

// Starter et skift fra grønt til rødt lys
void GreenToRed(void)
{
    if (DEBUG)
        printf_s("Skifter fra gr%snt til r%sdt\n", "\x9B");

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
        printf_s("Skifter fra r\x9B dt til gr\x9B nt");

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