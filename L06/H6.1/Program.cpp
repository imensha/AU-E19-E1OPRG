#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SIZE 7
#define NUM_MIN 1
#define NUM_MAX 36

void bubbleSort(int[], size_t);

int main(int argc, char const *argv[])
{
    int numbers[SIZE] = {0};

    srand(time(NULL));

    // Generate random numbers for the numbers[] array
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
            // Add the generated number to the array
            numbers[i] = num;
        }
    }

    // Sort array of numbers
    bubbleSort(numbers, SIZE);

    // Print sorted arrray
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}

void bubbleSort(int nums[], size_t n)
{
    for (size_t pass = 1; pass < n; pass++)
    {
        for (size_t i = 0; i < n - 1; i++)
        {
            // Swap elements if i is bigger than i+1
            if (nums[i] > nums[i + 1])
            {
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
            }
        }
    }
}
