#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include "Kunde.h"
using namespace std;

Kunde::Kunde(int kundeNummer, string navn, float saldo)
{
    try
    {
        setKundeNummer(kundeNummer);
    }
    catch (invalid_argument &e)
    {
        cout << "Fejl i kundenr! Kundenr er sat til 0." << endl;
    }

    setNavn(navn);
    opdaterSaldo(saldo);
}

void Kunde::setKundeNummer(int kundeNummer)
{
    if (kundeNummer == 0 || (kundeNummer >= 1000 && kundeNummer <= 9999))
    {
        kundeNummer_ = kundeNummer;
    }
    else
    {
        kundeNummer_ = 0;
        throw invalid_argument("Argument 'kundeNummer' must be 0 or between 1000-9999 (inclusive).");
    }
}

int Kunde::getKundeNummer()
{
    return kundeNummer_;
}

void Kunde::setNavn(string navn)
{
    navn_ = navn;
}

string Kunde::getNavn()
{
    return navn_;
}

void Kunde::opdaterSaldo(float addToSaldo)
{
    saldo_ += addToSaldo;
}

float Kunde::getSaldo()
{
    return saldo_;
}

void Kunde::print()
{
    cout << setw(20) << left << "Kundenummer:" << kundeNummer_ << endl;
    cout << setw(20) << "Navn:" << navn_ << endl;
    cout << setw(20) << "Saldo:" << fixed << setprecision(2) << saldo_ << endl;
}
