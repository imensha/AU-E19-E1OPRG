#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void)
{
    printf_s("Kvadratrodder:\n");
    printf_s("Kvadratroden af 9 er: %d\n", (int)sqrt(9));
    printf_s("Kvadratroden af 16 er: %d\n", (int)sqrt(16));

    printf_s("\nTrig funktioner:\n");
    printf_s("Cosinus af pi er: %f\n", cos(PI));
    printf_s("Sinus af pi er: %f\n", sin(PI));

    return 0;
}