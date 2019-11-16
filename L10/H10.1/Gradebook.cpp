#include <iostream>
#include "Gradebook.h"
using namespace std;

Gradebook::Gradebook(string name, string instructor) : courseName(name), instructorName(instructor)
{
}

void Gradebook::setCourseName(string name)
{
    courseName = name;
}

string Gradebook::getCourseName() const
{
    return courseName;
}

void Gradebook::displayMessage() const
{
    cout << "Welcome to the grade book for\n"
         << getCourseName() << "!\n"
         << "This course is presented by: " << instructorName << endl;
}