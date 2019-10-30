#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INPUT_MAX 100

int isValid(char[]);

int main(void)
{
    char input[INPUT_MAX];
    char* remaining;
    unsigned long int postalCode;
    int inputValid = 0;

    printf_s("Enter postal code and city (fx \"8200 Aarhus N\")\n");
    while (!inputValid)
    {
        if (fgets(input, INPUT_MAX, stdin) != NULL)
        {
            if (isValid(input))
            {
                inputValid = 1;
                postalCode = strtoul(input, &remaining, 0);

                printf_s("Postal Code: %lu\nCity: %s", postalCode, ++remaining);
            }
            else
            {
                printf_s("Input format incorrect! Please try again...\n");
            }

            
        }
    }

    return 0;
}

int isValid(char input[])
{

    for (int i = 0; i < 4; i++)
    {
        if (!isdigit(input[i]))
            return 0;
    }

    if (input[0] == '0' || !isspace(input[4]))
        return 0;

    return 1;
}
