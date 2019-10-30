#include "Weather.h"
#include <time.h>
#include <stdio.h>

#define NUM_MEASUREMENTS 20

int main(void)
{
    srand(time(0));
    struct dataset entries[NUM_MEASUREMENTS];

    for (int i = 0; i < NUM_MEASUREMENTS; i++)
    {
        entries[i] = { getWindDirection(), getWindSpeed(), getTemperature(), getPressure() };
    }

    for (int i = 0; i < NUM_MEASUREMENTS; i++)
    {
        printf_s("Entry %2d\n", i);
        printDataset(entries[i]);
        printf_s("\n");
    }

    return 0;
}