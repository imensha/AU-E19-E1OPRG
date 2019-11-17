#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void)
{
    int numbers[SIZE];

    srand(time(NULL));

    // Fill array with random numbers between [1; 100]
    for (size_t i = 0; i < SIZE; i++)
    {
        // Generate a random number using the formula `a + rand() % b`
        numbers[i] = 1 + rand() % 100;
        printf_s("%5d", numbers[i]);
    }
    puts("");

    // Sort the array
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        printf_s("%5d", numbers[i]);
    }
    puts("");
}