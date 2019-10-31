#include <stdio.h>

int main(void)
{
    float left = 0;
    float right = 0;
    float result = 0;
    char op = 0;

    // Ask user to enter a calculation using the available operators
    printf_s("Enter a calculation (+, -, * or /): ");
    scanf_s("%f %c %f", &left, &op, 1, &right);

    // Compute the result based on the input
    switch (op)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        result = left / right;
        break;
    }

    // Print the result
    printf_s("= %.2f", result);

    return 0;
}
