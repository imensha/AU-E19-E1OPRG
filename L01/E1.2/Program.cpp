#include <stdio.h>
#include <math.h>

int main(void)
{
    int kat[2];
    double hypotenuse;

    printf_s("Indtast laengden paa den foerste kateter: ");
    scanf_s("%d", &kat[0]);
    printf_s("Indtast laengden paa den anden kateter: ");
    scanf_s("%d", &kat[1]);

    hypotenuse = sqrt(pow(kat[0], 2) + pow(kat[1], 2));

    printf_s("Laengden af hyp er: %f\n", hypotenuse);

    return 0;
}