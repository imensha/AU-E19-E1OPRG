#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SIZE 7
#define NUM_MIN 1
#define NUM_MAX 36

int main(int argc, char const *argv[])
{
    int numbers[SIZE] = {0};

    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++)
    {
        int numExists = 0;
        // Generate random number
        int num = (rand() % NUM_MAX) + NUM_MIN;

        // Check that number doesn't already exist in the numbers array
        for (size_t j = 0; j < i; j++)
        {
            if (numbers[j] == num)
                numExists = 1;
        }

        if (numExists)
        {
            // Decrement iteration variable to rerun generation
            i--;
        }
        else
        {
            // Add the generated number to the array and print it
            numbers[i] = num;
            cout << numbers[i] << " ";
        }
    }

    cout << endl;

    return 0;
}
