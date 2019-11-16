#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

#define SECOND 1000
#define MEASURE_DELAY 5
#define MEASURE_TIME 60

void RunMeasurement(double[], int[], size_t n);
void PrintMeasurement(double[], int[], size_t n);

int main(void)
{
    if (!Open())
    {
        printf("Error with connection\n");
        exit(1);
    }

    printf("Connected to Raspberry Pi\n");

    const int nMeasurements = MEASURE_TIME / MEASURE_DELAY;
    double temperatures[nMeasurements];
    int intensities[nMeasurements];

    while(1)
    {
        RunMeasurement(temperatures, intensities);
        PrintMeasurement(temperatures, intensities);
    }

    return 0;
}

void RunMeasurement(double temps[], int intens[], size_t n)
{
    for (int i = 0; i < n; i++)
    {
        Wait(MEASURE_DELAY * SECOND);
        temps[i] = getTemperature();
        intens[i] = getIntensity();
    }
}

void PrintMeasurement(double temps[], int intens[], size_t n)
{
    printf_s("# MEASUREMENTS #\n");

    // Print temperatures
    printf_s("Measured temperatures\n");
    for (int i = 0; i < n; i++)
    {
        printf_s("%lf ", temps[i]);
    }

    // Print light intensities
    printf_s("Measured intensities\n");
    for (int i = 0; i < n; i++)
    {
        printf_s("%d ", intens[i]);
    }
}
