#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SIZE 7
#define NUM_MIN 1
#define NUM_MAX 36

int main(int argc, char const *argv[])
{
    int numbers[SIZE];

    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++)
    {
        numbers[i] = (rand() % NUM_MAX) + NUM_MIN;
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
