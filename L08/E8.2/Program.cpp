#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <RaspberryDLL.h>
#include <Windows.h>
#include <conio.h>
#include "AccessCode.h"
#include "LED.h"

int main()
{
    if (!Open())
    {
        printf_s("Error with connection\n");
        exit(1);
    }

    printf_s("Connected to Raspberry Pi\n");

    blinkGreen(10, 200);

    char userCode[CODE_BUFFER], codeFromKeyboard[CODE_BUFFER];
    int codeOkay;

    createCode(userCode);

    printf_s("\nDin kode er %s\n\nTryk en tast for at aktivere systemet\n", userCode);

    _getch();

    do
    {
        codeOkay = 0;					// Reset codeOkay
        ledOn(6);						// Tænd rød LED
        system("cls");					// Slet skærmen
        printf_s("%s", "LOCKED\n\n");

        printf_s("%s", "Tast din kode for at l\x86se d\x9Bren op - eller tast + for at lukke systemet ned\n\n");

        // Vent så længe der ikke trykkes på PC tastatur og der ikke trykkes på "udknap" (key P1 på RP'en)
        while (!keyPressed(P1) && !_kbhit()) {}

        // Der blev trykket på PC tastaturet
        if (_kbhit())
        {
            codeFromKeyboard[0] = _getch();

            if (codeFromKeyboard[0] != '+')
            {
                printf_s("*");

                for (int i = 0; i < CODE_SIZE - 1; i++)
                {
                    codeFromKeyboard[i + 1] = _getch();
                    printf_s("*");
                }

                codeFromKeyboard[CODE_SIZE] = '\0';

                codeOkay = checkCode(userCode, codeFromKeyboard);
            }
            else
                codeOkay = 1;
        }
        // Der blev trykket på "udknap"
        else
            codeOkay = 1;

        // Den indtastede kode er korrekt eller der blev trykket på "udknap"
        if (codeOkay == 1 || keyPressed(1))
        {
            ledOff(6);
            for (int i = 0; i < 3; i++)
            {
                ledOn(LD1);
                ledOn(LD2);
                ledOn(LD3);
                ledOn(LD4);
                ledOn(LD5);
                Wait(200);
                ledOff(LD1);
                ledOff(LD2);
                ledOff(LD3);
                ledOff(LD4);
                ledOff(LD5);
                Wait(200);
            }
            ledOn(LD1);
            ledOn(LD2);
            ledOn(LD3);
            ledOn(LD4);
            ledOn(LD5);
            Wait(10 * 1000);
        }
        else
        {
            printf_s("Den indtastede kode er forkert!");
            Wait(5 * 1000);
        }

    } while (codeFromKeyboard[0] != '+');

    ledOff(6);

    return 0;
}