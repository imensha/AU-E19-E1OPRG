#include <iostream>

class Triangle
{
private:
    double a_;
    double b_;
    double c_;
    bool isSidesValid(double a, double b, double c);

public:
    Triangle(double a = 1, double b = 1, double c = 1);
    void setSides(double a = 1, double b = 1, double c = 1);
    double circumference();
    double area();
    void print();
    void setA(double value);
    double getA();
    void setB(double value);
    double getB();
    void setC(double value);
    double getC();
};