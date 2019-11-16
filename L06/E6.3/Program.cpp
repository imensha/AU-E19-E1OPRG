#include <stdio.h>
#include "code_functions.h"

int main(int argc, char const *argv[])
{
    char code[CODE_SIZE + 1];
    createCode(code);

    printf_s("Your code is: %s\n", code);
    changeCode(code);
    printf_s("Your code is: %s\n", code);

    return 0;
}
