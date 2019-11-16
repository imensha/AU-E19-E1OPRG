#include <iostream>
using namespace std;

void printRectangle(int, int, char);

int main(int argc, char const *argv[])
{
    printRectangle(10, 2, '#');
    printRectangle(2, 10, '#');
    return 0;
}

void printRectangle(int side1, int side2, char c)
{
    for (size_t x = 0; x < side2; x++)
    {
        for (size_t x = 0; x < side1; x++)
        {
            cout << c;
        }
        cout << endl;
    }
}
