#include <string>
#include <iostream>
#include "code_functions.h";
using namespace std;

int main(int argc, char const *argv[])
{
    string code = "";
    createCode(code);

    cout << "Your code is: " << code << endl;
    changeCode(code);
    cout << "Your code is: " << code << endl;

    return 0;
}