#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Lotto.h"
using namespace std;

void bubbleSort(int[], size_t);

void tipsLotto(int arr[], const size_t n)
{
    srand(time(NULL));

    // Generate random numbers for the numbers[] array
    for (size_t i = 0; i < n; i++)
    {
        int numExists = 0;
        // Generate random number
        int num = (rand() % NUM_MAX) + NUM_MIN;

        // Check that number doesn't already exist in the numbers array
        for (size_t j = 0; j < i; j++)
        {
            if (arr[j] == num)
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
            arr[i] = num;
        }
    }

    // Sort array of numbers
    bubbleSort(arr, n);
}

void brugerLotto(int arr[], const size_t n)
{
    // Retrieve 7 unique random numbers from the user
    cout << "Enter 7 numbers between 1 and 36" << endl;
    for (size_t i = 0; i < n; i++)
    {
        int inputValid = 1;
        int input;

        scanf_s("%d", &input);

        if (input >= NUM_MIN && input <= NUM_MAX)
        {
            // Check that input is a unique number
            for (size_t j = 0; j < i; j++)
            {
                if (arr[j] == input)
                    inputValid = 0;
            }

            if (inputValid)
            {
                arr[i] = input;
            }
            else
            {
                i--;
                cout << "Please enter unique numbers!" << endl;
            }
        }
        else
        {
            i--;
            cout << "Number must be between 1 and 36" << endl;
        }
    }

    bubbleSort(arr, n);
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