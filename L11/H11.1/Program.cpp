#include <iostream>
#include "Kunde.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // Test default
    Kunde k1;
    k1.print();

    // Test constructor with all parameters set
    Kunde k2(1337, "4chan hackers", 10000.37);
    k2.print();
    k2.opdaterSaldo(-10000);
    k2.print();
    k2.setKundeNummer(9001);
    k2.setNavn("OVER 9000!!");
    k2.print();

    // Test constructor with partial parameters set
    Kunde k3(500, "Invalid");
    k3.print();

    return 0;
}
