#include <iostream>

#define MAX_NUMBERS 3

int main(void)
{
    int number, total = 0;
    double average;

    std::cout << "Enter " << MAX_NUMBERS << " numbers: " << std::endl;

    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        std::cin >> number;

        total += number;
    }

    average = (double)total / MAX_NUMBERS;

    std::cout << "The average of the " << MAX_NUMBERS << " you entered is: " << average;

    return 0;
}