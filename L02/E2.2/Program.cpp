#include <stdio.h>
#include <math.h>

int Discriminant(int A, int B, int C);
double *Roots(int A, int B, int d);

int main(void)
{
    int A, B, C;

    // Header and coefficient A
    printf_s("%s", "Andengradsligning formen ax^2 + bx + c = 0\n\nIndtast koefficienten A: ");
    scanf_s("%d", &A);

    // Coefficient B
    printf_s("%s", "Indtast koefficienten B: ");
    scanf_s("%d", &B);

    // Coefficient C
    printf_s("%s", "Indtast koefficienten C: ");
    scanf_s("%d", &C);

    // Print coefficients
    printf_s("\nPolynomiet er: %dx^2 + %dx + %d = 0\n", A, B, C);
    
    int d = Discriminant(A, B, C);
    double *roots = Roots(A, B, d);

    if (d < 0)
    {
        printf_s("Der er 0 rødder!\n");
    }
    else if (d == 0)
    {
        printf_s("Der er en rod, den er: %.3lf\n", roots[0]);
    }
    else
    {
        printf_s("Der er 2 roedder, de er: %.3lf og %.3lf\n", roots[0], roots[1]);
    }
    printf_s("Diskriminanten er: %d\n", Discriminant(A, B, C));
    

    return 0;
}

// Compute the discriminant for a polynomial
int Discriminant(int A, int B, int C)
{
    double result = pow(B, 2) - (double)4 * A * C;

    return result;
}

double *Roots(int A, int B, int d)
{
    static double roots[2];

    if (d >= 0)
    {
        roots[0] = (-B - sqrt(d)) / (2 * A);
        roots[1] = (-B + sqrt(d)) / (2 * A);

        return roots;
    }

    return nullptr;
}