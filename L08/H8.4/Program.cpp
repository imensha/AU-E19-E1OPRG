#include <stdio.h>

typedef struct {
    char breed[100];
    int age;
    float weight;
} Dog ;

void printDog(Dog);

int main(void)
{
    Dog d1 = { "Corgi", 15, 5.5 };
    Dog d2 = { "Fluffy", 10, 7.4 };
    Dog d3 = { "Poodle", 16, 8.9 };

    printDog(d1);
    printDog(d2);
    printDog(d3);
}

void printDog(Dog d)
{
    printf_s("--- %s ---\nAge: %d\nWeight: %.2f kg\n\n", d.breed, d.age, d.weight);
}