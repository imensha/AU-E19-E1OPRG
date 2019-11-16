#include <iostream>
using namespace std;

#define SECONDS_PER_HOUR (60 * 60)
#define SECONDS_PER_MINUTE (60)

int calculateSeconds(int hours, int minutes, int seconds);

int main(int argc, char const *argv[])
{
    cout << "Seconds in 10:43:29: " << calculateSeconds(10, 43, 29);
    return 0;
}

int calculateSeconds(int hours, int minutes, int seconds)
{
    return (hours * SECONDS_PER_HOUR) + (minutes * SECONDS_PER_MINUTE) + seconds;
}
