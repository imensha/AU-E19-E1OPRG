#include <iostream>
#include <conio.h>
using namespace std;

int inputValid(const char c);
void ledOn(int);
void ledOff(int);

void ledOn(int led)
{
    cout << "LED " << led << " = ON" << endl;
}
void ledOff(int led)
{
    cout << "LED " << led << " = OFF" << endl;
}

int main(int argc, char const *argv[])
{
    char input = '\0';
    // Store LED status as integer in array
    int ledStatus[] = {0, 0, 0, 0, 0, 0, 0};

    // Initialize all LEDs off to match the initialized status array
    for (size_t i = 0; i < 6; i++)
    {
        ledOff(i);
    }

    while (input != '0')
    {
        input = _getch();
        if (inputValid(input))
        {
            // Convert char to the represented digit value
            int led = input - '0';
            if (ledStatus[led])
            {
                ledStatus[led] = 0;
                ledOff(led);
            }
            else
            {
                ledStatus[led] = 1;
                ledOn(led);
            }
        }
    }

    return 0;
}

int inputValid(const char c)
{
    int valid = 0;
    // Check if char matches valid LED input
    for (char i = '1'; i <= '6'; i++)
    {
        if (c == i)
            valid = 1;
    }

    return valid;
}