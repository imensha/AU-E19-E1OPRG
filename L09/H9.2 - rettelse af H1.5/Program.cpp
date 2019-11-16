#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int time;
    int hours, minutes, seconds;

    cout << "Enter seconds since an event: " << endl;
    cin >> time;

    hours = time / (60 * 60);
    minutes = (time % (60 * 60)) / 60;
    seconds = time % 60;

    cout << "Time since event: "
        << setfill('0') << setw(2) << hours
        << ":" << setfill('0') << setw(2) << minutes 
        << ":" << setfill('0') << setw(2) << seconds << endl;

    return 0;
}