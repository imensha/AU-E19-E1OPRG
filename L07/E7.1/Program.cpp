#include <stdio.h>
#include "Functions.h"

int main(void)
{
    int numbers[] = { -5, 6, 2, 10, 17, 5, -14, -1, 0, 3 };
    int size = sizeof(numbers) / sizeof(int);

    printf_s("The largest number among the provided is: %d\n", maxValue(numbers, size));
    printf_s("The smallest number among the provided is: %d\n", minValue(numbers, size));
    printf_s("The average of all the numbers is: %lf", average(numbers, size));

    return 0;
}