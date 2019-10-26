#include <stdio.h>

int main(void)
{
    int number;

    printf_s("Enter a number: ");
    scanf_s("%d", &number);
    printf_s("Your number is %s", (number % 2 == 0) ? "EVEN" : "ODD");

    return 0;
}