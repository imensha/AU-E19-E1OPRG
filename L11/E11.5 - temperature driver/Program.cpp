#include <iostream>
#include "TemperatureSensor.h"
using namespace std;

int main(int argc, char const *argv[])
{
    while (1)
    {
        cout << "Current temperature: " << TemperatureSensor::readTemperature() << endl;
        system("cls");
    }

    return 0;
}
