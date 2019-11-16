#include <iostream>
#include "code_functions.h"
using namespace std;

void createCode(string &codeRef)
{
	int ascii;

	srand(time(0));

	for (size_t index = 0; index < CODE_SIZE; index++)
	{
		ascii = (rand() % 75 + 48);

		// if ascii number is NOT a letter or digit (check ASCII table)
        if (57 < ascii && ascii < 65 || 90 < ascii && ascii < 97)
            index--;
        else
            codeRef[index] = ascii;
	}

	codeRef[CODE_SIZE] = '\0';
}

int checkCode(const string &code1, const string &code2)
{
    return code1 == code2;
}

int changeCode(string &currentCode)
{
    string input;
    cout << "Enter old code: ";
    cin >> input;

    if (checkCode(currentCode, input))
    {
        string newCodeA, newCodeB;

        cout << "Enter new code: ";
        cin >> newCodeA;
        cout << "Repeat new code: ";
        cin >> newCodeB;

        if (checkCode(newCodeA, newCodeB))
        {
            currentCode = newCodeA;
            return 1;
        }
    }

	return 0;
}