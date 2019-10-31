#include <stdio.h>
#include <math.h>

int main(void)
{
    int power = 1;
    while (1)
    {
        printf_s("%lf\n", pow(3, power));
        power++;
    }

    return 0;
}