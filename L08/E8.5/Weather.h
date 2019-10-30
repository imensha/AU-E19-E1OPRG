#pragma once
#include <stdlib.h>

struct dataset
{
    int windDirection;
    double windSpeed;
    double temperature;
    int pressure;
};

void printDataset(struct dataset ds);
void printDatasetPtr(struct dataset* ds);

int getWindDirection();
double getTemperature();
int getPressure();
double getWindSpeed();