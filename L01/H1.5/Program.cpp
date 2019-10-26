#include <stdio.h>

int main(void)
{
    int time;
    int hours, minutes, seconds;

    printf_s("Enter seconds since an event: ");
    scanf_s("%d", &time);

    hours = time / (60 * 60);
    minutes = (time % (60 * 60)) / 60;
    seconds = time % 60;

    printf_s("Time since event: %02d:%02d:%02d", hours, minutes, seconds);

    return 0;
}