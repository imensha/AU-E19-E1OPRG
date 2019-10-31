#include <stdio.h>

int main(void)
{
    int sides[3];

    for (int i = 0; i < 3; i++)
    {
        printf_s("Enter length of side %c: ", i + 65);
        scanf_s("%d", &sides[i]);
    }

    if (sides[0] + sides[1] > sides[2] && sides[1] + sides[2] > sides[0] && sides[0] + sides[2] > sides[1])
    {
        printf_s("These lengths form a triangle!");
    }
    else
    {
        printf_s("These lengths DO NOT form a triangle!");
    }

    return 0;
}