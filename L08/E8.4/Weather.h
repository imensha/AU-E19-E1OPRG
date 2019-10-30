#pragma once

struct dataset
{
    int windDirection;
    double windSpeed;
    double temperature;
    int pressure;
};

void printDataset(struct dataset ds);
void printDatasetPtr(struct dataset* ds);
