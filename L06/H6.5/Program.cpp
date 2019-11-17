#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Lotto.h"
using namespace std;

#define SIZE 7

void printLotto(int[], size_t);

int main(int argc, char const *argv[])
{
    int user[SIZE] = {0};
    int lotto[SIZE] = {0};

    brugerLotto(user, SIZE);
    printLotto(user, SIZE);
    tipsLotto(lotto, SIZE);
    printLotto(lotto, SIZE);

    system("pause");

    return 0;
}

// Print sorted arrray
void printLotto(int arr[], size_t n)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
