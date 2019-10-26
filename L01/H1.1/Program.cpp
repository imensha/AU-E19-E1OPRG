#include <stdio.h>

int main(void)
{
    double exchangeRate = 7.4701;
    double euroValue;

    printf_s("Enter a value in EUR to convert: ");
    scanf_s("%lf", &euroValue);
    printf_s("Converting EUR %.2lf to DKK (exchange rate %.2lf): %.2lf", euroValue, exchangeRate, euroValue * exchangeRate);

    return 0;
}