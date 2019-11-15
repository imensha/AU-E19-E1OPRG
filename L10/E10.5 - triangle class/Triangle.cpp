#include <cmath>
#include "Triangle.h"

bool Triangle::isSidesValid(double a, double b, double c)
{
    return (a > 0 && b > 0 && c > 0) &&
           (a + b > c) &&
           (b + c > a) &&
           (c + a > b);
}

Triangle::Triangle(double a, double b, double c)
{
    setSides(a, b, c);
}

void Triangle::setSides(double a, double b, double c)
{
    if (isSidesValid(a, b, c))
    {
        setA(a);
        setB(b);
        setC(c);
    }
    else
    {
        setA(1);
        setB(1);
        setC(1);
    }
}

double Triangle::circumference()
{
    return getA() + getB() + getC();
}

double Triangle::area()
{
    double s = circumference() / 2;
    return std::sqrt(s * (s - getA()) * (s - getB()) * (s - getC()));
}

void Triangle::print()
{
    std::cout << "Triangle sides:" << std::endl
              << "A = " << getA()
              << ", B = " << getB()
              << ", C = " << getC() << std::endl
              << "Triangle circumference: " << circumference() << std::endl;
}

void Triangle::setA(double value)
{
    a_ = value;
}
double Triangle::getA()
{
    return a_;
}

void Triangle::setB(double value)
{
    b_ = value;
}
double Triangle::getB()
{
    return b_;
}

void Triangle::setC(double value)
{
    c_ = value;
}
double Triangle::getC()
{
    return c_;
}