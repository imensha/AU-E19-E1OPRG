#include <stdio.h>

int main(void)
{
    for (int i = 50; i > 0; i--)
    {
        if (i % 2 == 0)
            printf_s("%d\n", i);
    }

    return 0;
}