#include <iostream>
#include <string>
#include "Child.h"
using namespace std;

const unsigned int MIN_AGE = 0;
const unsigned int MAX_AGE = 14;

Child::Child(string name, unsigned int age) : name_("Ukendt navn"), age_(0)
{
    setName(name);
    if (age >= MIN_AGE && age <= MAX_AGE)
        setAge(age);
    else
        age_ = 99;
}

string Child::getName()
{
    return name_;
}

void Child::setName(string name)
{
    name_ = name;
}

unsigned int Child::getAge()
{
    return age_;
}

void Child::setAge(unsigned int age)
{
    // Only set age if argument is within age range and greater than current age
    if ((age >= MIN_AGE && age <= MAX_AGE) && age > age_)
    {
        age_ = age;
    }
}

void Child::print()
{
    cout << name_ << ", " << age_ << endl;
}