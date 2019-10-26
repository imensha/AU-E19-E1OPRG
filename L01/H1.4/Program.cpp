#include <stdio.h>

int main(void)
{
    int age;

    printf_s("Enter your age: ");
    scanf_s("%d", &age);

    if (age < 0 || age > 125)
    {
        printf_s("Invalid age! Please enter an age between 0-125");
    }
    else if (age < 13)
    {
        printf_s("This person is a child.");
    }
    else if (age < 20)
    {
        printf_s("This person is a teenager.");
    }
    else if (age < 60)
    {
        printf_s("This person is an adult.");
    }
    else
    {
        printf_s("This person is an elderly.");
    }

    return 0;
}