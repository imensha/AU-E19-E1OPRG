#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define INPUT_MAX 11

int isValid(char input[]);

enum MONTH { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
const char* months[] = { "", "januar", "februar", "marts", "april", "maj", "juni", "juli", "august", "september", "oktober", "november", "december" };

int main(void)
{
    char input[INPUT_MAX];
    char* cursor = input;
    unsigned long date[3];

    printf_s("Enter a date with the format dd/mm/yyyy:\n");
    if (fgets(input, INPUT_MAX, stdin) != NULL)
    {
        if (isValid(input))
        {
            date[0] = strtoul(input, &cursor, 0);
            cursor++;
            date[1] = strtoul(cursor, &cursor, 0);
            cursor++;
            date[2] = strtoul(cursor, &cursor, 0);

            printf_s("You entered the date:\n%2lu. %s, %4lu", date[0], months[date[1]], date[2]);
        }
        else
        {
            printf_s("Incorrect format!");
        }
    }

}

int isValid(char input[])
{
    for (int i = 0; i < INPUT_MAX - 1; i++)
    {
        if (i == 2 || i == 5)
        {
            if (input[i] != '/')
                return 0;
        }
        else if (!isdigit(input[i]))
        {
            return 0;
        }
    }
    
    return 1;
}