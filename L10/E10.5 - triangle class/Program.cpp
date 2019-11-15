#include <iostream>
#include "Triangle.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Triangle unit;
    Triangle valid(2, 3, 4);

    cout << "Testing unit triangle" << endl;
    unit.print();
    unit.setSides(4, 3, 2);
    unit.print();

    cout << endl;

    cout << "Testing valid triangle" << endl;
    valid.print();
    valid.setSides(1, 3, 1);
    valid.print();

    return 0;
}
