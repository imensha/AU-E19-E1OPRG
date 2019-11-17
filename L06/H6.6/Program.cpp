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
    cout << "Your selected the numbers: ";
    printLotto(user, SIZE);

    tipsLotto(lotto, SIZE);
    cout << "Lotto numbers were: ";
    printLotto(lotto, SIZE);

    // Count correct numbers
    int correct = 0;
    for (size_t user_i = 0; user_i < SIZE; user_i++)
    {
        for (size_t lotto_i = 0; lotto_i < SIZE; lotto_i++)
        {
            if (user[user_i] == lotto[lotto_i])
                correct++;
        }
    }
    cout << "You got " << correct << " numbers correct!" << endl;

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
