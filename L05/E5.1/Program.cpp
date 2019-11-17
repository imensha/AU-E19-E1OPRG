#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main(void)
{
    int numbers[SIZE];
    int numNegative = 0;

    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++)
    {
        // Generate a random number using the formula `a + rand() % b`
        int num = -50 + rand() % 101;
        
        if (num < 0) numNegative++;
        numbers[i] = num;
    }

    printf_s("Der blev genereret %d negative tal\n", numNegative);
}