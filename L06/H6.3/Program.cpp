#include <iostream>
#include <conio.h>
using namespace std;

#define SIZE 7

void bubbleSort(int[], size_t);

int main(int argc, char const *argv[])
{
    int numbers[SIZE] = {0};

    cout << "Enter 7 numbers between 1 and 36" << endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        int inputValid = 1;
        int input;

        scanf_s("%d", &input);

        if (input >= 1 && input <= 36)
        {
            // Check that input is a unique number
            for (size_t j = 0; j < i; j++)
            {
                if (numbers[j] == input)
                    inputValid = 0;
            }

            if (inputValid)
            {
                numbers[i] = input;
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

    bubbleSort(numbers, SIZE);

    for (size_t i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    while (1)
    {
    }

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