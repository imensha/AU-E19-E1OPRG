#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <RaspberryDLL.h>
#include "Functions.h"

#define SECOND 1000
#define MEASURE_DELAY 2
#define MEASURE_TIME 10

typedef struct {
    int min;
    int max;
    double avg;
} Measurement;

void RunMeasurement(double[], int[], size_t n);
void PrintMeasurement(Measurement temp, Measurement intens);

int main(void)
{
    if (!Open())
    {
        printf("Error with connection\n");
        exit(1);
    }

    printf("Connected to Raspberry Pi\n");

    const size_t nMeasurements = MEASURE_TIME / MEASURE_DELAY;
    double temperatures[nMeasurements];
    int intensities[nMeasurements];
    Measurement temp, intens;

    while (1)
    {
        RunMeasurement(temperatures, intensities, nMeasurements);

        temp.min = minValue(temperatures, nMeasurements);
        temp.max = maxValue(temperatures, nMeasurements);
        temp.avg = average(temperatures, nMeasurements);
        intens.min = minValue(intensities, nMeasurements);
        intens.max = maxValue(intensities, nMeasurements);
        intens.avg = average(intensities, nMeasurements);

        PrintMeasurement(temp, intens);
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

void PrintMeasurement(Measurement temp, Measurement intens)
{
    system("cls");
    printf_s("--- Measurement ---\n");

    printf_s("[Temperature]\nMin: %d\nMax: %d\nAvg: %lf\n\n", temp.min, temp.max, temp.avg);
    printf_s("[Intensity]\nMin: %d\nMax: %d\n", intens.min, intens.max);
    // Print light intensity average bar
    char bar[11] = "          ";
    int percentAvg = round(intens.avg / 10);
    for (int i = 0; i < percentAvg; i++)
    {
        bar[i] = '#';
    }
    printf_s("Avg: [%10s] (%lf)", bar, intens.avg);
}


