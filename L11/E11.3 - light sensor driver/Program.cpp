#include <iostream>
#include "LightSensor.h"
using namespace std;

int main(int argc, char const *argv[])
{
    while (1)
    {
        cout << "Current light intensity: " << LightSensor::readIntensity() << endl;
        system("cls");
    }

    return 0;
}
