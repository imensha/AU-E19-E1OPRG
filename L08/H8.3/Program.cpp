#include <stdio.h>

typedef struct {
    int age;
    int height;
    float weight;
} Person ;

int main(void)
{
    Person kid = { 10, 145, 35.5 };
    Person adult = { 25, 180, 77.4 };
    Person elderly = { 80, 166, 48.9 };

    printf_s("--- Kid ---\nAge: %d\nHeight: \%d cm\nWeight: %.2f kg\n\n", kid.age, kid.height, kid.weight);
    printf_s("--- Adult ---\nAge: %d\nHeight: \%d cm\nWeight: %.2f kg\n\n", adult.age, adult.height, adult.weight);
    printf_s("--- Elderly ---\nAge: %d\nHeight: \%d cm\nWeight: %.2f kg\n\n", elderly.age, elderly.height, elderly.weight);
}