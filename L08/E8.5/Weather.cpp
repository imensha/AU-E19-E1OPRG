#include <stdio.h>
#include "Weather.h"

void printDataset(struct dataset ds)
{
    printf_s("Wind Direction: %d\n", ds.windDirection);
    printf_s("Wind Speed: %.2lf\n", ds.windSpeed);
    printf_s("Temperature: %.2lf\n", ds.temperature);
    printf_s("Pressure: %d\n", ds.pressure);
}

void printDatasetPtr(struct dataset* ds)
{
    printf_s("Wind Direction: %d\n", ds->windDirection);
    printf_s("Wind Speed: %.2lf\n", ds->windSpeed);
    printf_s("Temperature: %.2lf\n", ds->temperature);
    printf_s("Pressure: %d\n", ds->pressure);
}

int getWindDirection()
{
    return rand() % 360;
}


double getTemperature()
{
    return ((rand() % 1200) - 600) / 9.99;
}


int getPressure()
{
    return (rand() % 100) + 900;
}


double getWindSpeed()
{
    return (rand() % 3333) / 41.2;
}