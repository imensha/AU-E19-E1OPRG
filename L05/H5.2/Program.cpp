#include <iostream>
using namespace std;

#define SIZE 500

int main(int argc, char const *argv[])
{
    int numbers[SIZE];

    for (size_t i = 0; i < SIZE; i++)
    {
        numbers[i] = i + 1;
        cout << numbers[i] << endl;
    }

    return 0;
}
