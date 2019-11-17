#include <iostream>
using namespace std;

#define SIZE 6
#define START 10

int main(int argc, char const *argv[])
{
    double numbers[SIZE];

    for (size_t i = 0; i < SIZE; i++)
    {
        numbers[i] = START + i;
        cout << "Number at index [" << i << "] contains: " << numbers[i] << endl;
    }

    cout << endl
         << "Adding 5 to all numbers..." << endl;

    for (size_t i = 0; i < 6; i++)
    {
        numbers[i] += 5;
        cout << "Number at index [" << i << "] contains: " << numbers[i] << endl;
    }

    return 0;
}
