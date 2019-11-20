#include <string>
#if !defined(KUNDE_H)
#define KUNDE_H

class Kunde
{
private:
    int kundeNummer_;
    std::string navn_;
    float saldo_;

public:
    explicit Kunde(int kundeNummer = 0, std::string navn = "NN", float saldo = 0);
    void setKundeNummer(int kundeNummer);
    int getKundeNummer();
    void setNavn(std::string navn);
    std::string getNavn();
    void opdaterSaldo(float addToSaldo);
    float getSaldo();
    void print();
};

#endif // KUNDE_H
