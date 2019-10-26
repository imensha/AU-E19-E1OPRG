#include <stdio.h>

#define MAX_NUMBERS 3

int main(void)
{
    int numbers[MAX_NUMBERS];
    int total = 0;
    double average;

    printf_s("Enter three integers: ");
    scanf_s("%d %d %d", &numbers[0], &numbers[1], &numbers[2]);

    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        total += numbers[i];
    }
    average = (double)total / MAX_NUMBERS;

    printf_s("The average of the three numbers you entered is: %lf", average);

    return 0;
}