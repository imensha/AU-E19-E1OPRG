#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "AccessCode.h"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    char userCode[CODE_BUFFER], codeFromKeyboard[CODE_BUFFER];
    int compareResult;

    // Test code generation
    createCode(userCode);
    printf_s("Your code is: %s\n\n", userCode);

    // Test code validation
    printf_s("Please enter your code: ");
    scanf_s("%8s", codeFromKeyboard, CODE_BUFFER);
    compareResult = checkCode(userCode, codeFromKeyboard);

    if (compareResult)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf_s("Congratulations, you typed the code correctly!");
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf_s("Sorry, that does not appear to be the correct code.");
    }
    printf_s("\n\n");
    /* Restore original attributes */
    SetConsoleTextAttribute(hConsole, saved_attributes);

    // Test code change
    int codeChangeResult = changeCode(userCode);
    if (codeChangeResult)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf_s("Congratulations, you changed the code correctly!");
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf_s("Sorry, it seems you could not change the code.");
    }
    printf_s("\n\n");
    /* Restore original attributes */
    SetConsoleTextAttribute(hConsole, saved_attributes);

    // Verify new code
    printf_s("Please enter your code: ");
    scanf_s("%8s", codeFromKeyboard, CODE_BUFFER);
    compareResult = checkCode(userCode, codeFromKeyboard);

    if (compareResult)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf_s("Congratulations, you typed the code correctly!");
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf_s("Sorry, that does not appear to be the correct code.");
    }
    printf_s("\n\n");
    /* Restore original attributes */
    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}