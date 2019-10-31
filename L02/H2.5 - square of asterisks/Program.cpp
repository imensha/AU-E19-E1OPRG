#include <stdio.h>
#include <Windows.h>

int main(void)
{
    int sideLength = 0;

    while (sideLength < 1 || sideLength > 20)
    {
        system("cls");
        printf_s("Enter side length of the desired square, between 1-20: ");
        scanf_s("%d", &sideLength);
    }

    for (int x = 0; x < sideLength; x++)
    {
        for (int y = 0; y < sideLength; y++)
        {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}