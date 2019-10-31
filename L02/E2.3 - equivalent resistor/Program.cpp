#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

void main(void)
{
    unsigned int r1, r2;
    double equivSerial, equivParallel;
    char input = 'n';

    printf_s("%s", "Calculating equivalent resistors:\n\n");

    do
    {
        printf_s("Select calculation method: (1) serial\t(2) parallel\n");
        input = _getch();

        if (input == '1' || input == '2')
        {
            // Get resistance from user input
            printf_s("R_1 value: ");
            scanf_s("%d", &r1);

            printf_s("R_2 value: ");
            scanf_s("%d", &r2);

            // Calculate equivalent resistors
            equivSerial = r1 + r2;
            equivParallel = pow(pow(r1, -1) + pow(r2, -1), -1);

            // Print the equivalent resistor values
            printf_s("\nR_eq: %.2lf\n", input == '1' ? equivSerial : equivParallel);

            // Ask user if they want to do another calculation
            printf_s("Do another calculation? (y/n)");
            input = _getch();
            system("cls");
        }
        else
        {
            printf_s("Please press 1 or 2 to select a calculation method!\n");
        }


    } while (input != 'n');
}