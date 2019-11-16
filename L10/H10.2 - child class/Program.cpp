#include <iostream>
#include "Child.h"
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    Child testDefault;
    Child testValid("Foo", 10);
    Child testInvalid("Bar", 20);

    cout << "Testing default:" << endl;
    testDefault.print();
    testDefault.setName("Foobar");
    testDefault.setAge(5);
    testDefault.print();

    cout << "Testing valid:" << endl;
    testValid.print();
    testValid.setName("Baz");
    testValid.setAge(15);
    testValid.print();

    cout << "Testing invalid:" << endl;
    testInvalid.print();
    testInvalid.setName("Qux");
    testInvalid.setAge(10);
    testInvalid.print();

    return 0;
}
