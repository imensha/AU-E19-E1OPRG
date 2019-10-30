#include <stdio.h>

struct dataset
{
    int windDirection;
    double windSpeed;
    double temperature;
    int pressure;
};

int main(int argc, char const *argv[])
{
    struct dataset entry = { 67, 3.4, 18.7, 50 };

    printf_s("Wind Direction: %d\n", entry.windDirection);
    printf_s("Wind Speed: %.2lf\n", entry.windSpeed);
    printf_s("Temperature: %.2lf\n", entry.temperature);
    printf_s("Pressure: %d\n", entry.pressure);

    return 0;
}
