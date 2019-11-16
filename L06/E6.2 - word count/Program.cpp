#include <ctype.h>
#include <stdio.h>

#define INPUT_MAX 1024

int countWords(const char *);

int main(void)
{
    char input[INPUT_MAX];

    printf_s("Enter a character string:\n");
    gets_s(input, INPUT_MAX);
    printf_s("You entered %d words", countWords(input));

    return 0;
}

int countWords(const char *input)
{
    int count = 0;
    int countNext = 1;

    for (; *input != '\0'; input++)
    {
        int isCharBlank = isblank(*input);
        if (!isCharBlank && countNext)
        {
            count++;
            countNext = 0;
        }
        else if (isCharBlank)
        {
            countNext = 1;
        }
    }

    return count;
}