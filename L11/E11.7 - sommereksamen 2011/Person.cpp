#include <iostream>
#include <string>
#include <stdexcept>
#include "Person.h"
using namespace std;

Person::Person(string navn, int alder)
{
    setNavn(navn);
    setAlder(alder);
}

void Person::setNavn(string navn)
{
    Person::navn = navn;
}

string Person::getNavn()
{
    return navn;
}

void Person::setAlder(int alder)
{
    if (alder >= 0 && alder <= 100)
    {
        Person::alder = alder;
    }
    else
    {
        throw invalid_argument("Argument 'alder' must be between 0-100 (inclusive)");
    }
}

int Person::getAlder()
{
    return alder;
}

void Person::print()
{
    cout << navn << " " << alder << " aar" << endl;
}