#include <stdio.h>
#include <Windows.h>

int factorial(int);

int main(void)
{
    unsigned int n = 0;

    printf_s("Enter a number: ");
    scanf_s("%d", &n);
    printf_s("%d! = %d", n, factorial(n));

    return 0;
}

int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}