#include <stdio.h>
#include <conio.h>

int sumBiggerThan100(int a, int b);

int main(int argc, char const *argv[])
{
    int a, b;

    printf_s("Enter two numbers: ");
    scanf_s("%d %d", &a, &b);
    printf_s("%s\n", sumBiggerThan100(a, b) ? "Sum bigger than 100" : "Sum less than or equal to 100");

    printf_s("\nHit any key to exit...");
    _getch();
    return 0;
}

int sumBiggerThan100(int a, int b)
{
    if (a + b > 100)
    {
        return 1;
    }

    return 0;
}