#include <climits>
#include "Functions.h"

int maxValue(int* numbers, const int count)
{
    int maxValue = INT_MIN;

    for (int i = 0; i < count; i++)
    {
        int num = numbers[i];
        if (num > maxValue) maxValue = num;
    }

    return maxValue;
}

int minValue(int* numbers, const int count)
{
    int minValue = INT_MAX;

    for (int i = 0; i < count; i++)
    {
        int num = numbers[i];
        if (num < minValue) minValue = num;
    }

    return minValue;
}

double average(int numbers[], const int count)
{
    double total = 0;

    for (int i = 0; i < count; i++)
    {
        total += numbers[i];
    }

    return total / count;
}
