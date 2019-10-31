#include <stdio.h>
#include <math.h>

int main(void)
{
    int input;
    char inputValid = 0;

    while (!inputValid)
    {
        printf_s("Enter a number to be squared: ");
        scanf_s("%d", &input);

        if (input < 0)
            printf_s("Cannot calculate square root of negative number!\n");
        else
            inputValid = 1;
    }

    printf_s("%d squared equals %.2lf", input, sqrt(input));
}