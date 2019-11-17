#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Lotto.h"
using namespace std;

#define SIZE 7

int main(int argc, char const *argv[])
{
    int numbers[SIZE] = {0};

    tipsLotto(numbers, SIZE);

    // Print sorted arrray
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}
