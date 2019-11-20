#include <iomanip>
#include <iostream>
#include "Person.h"
using namespace std;

namespace
{
const size_t MAX_NUM = 10;
const size_t BUFFER_SIZE = 1024;
} // namespace

int findNuller(char *);

int main(int argc, char const *argv[])
{
    // Opgave 1
    for (size_t i = 1; i <= 99; i += 2)
    {
        cout << i << endl;
    }

    // Opgave 2
    double nums[MAX_NUM];
    for (size_t i = 0; i < 10; i++)
    {
        nums[i] = 5.0;
    }
    for (size_t i = 0; i < 10; i++)
    {
        cout << nums[i] << endl;
    }

    // Opgave 3 + 4
    Person p("Bo Hald", 25);
    p.print();

    // Opgave 5
    char tekst[BUFFER_SIZE];
    cin >> setw(BUFFER_SIZE) >> tekst;
    cout << "Nuller i streng: " << findNuller(tekst) << endl;

    system("pause");

    return 0;
}

int findNuller(char *str)
{
    unsigned int count = 0;

    while (*str != '\0')
    {
        if (*str == '0')
            count++;

        str++;
    }

    return count;
}
