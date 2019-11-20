#include <string>

#if !defined(PERSON_H)
#define PERSON_H

class Person
{
private:
    std::string navn;
    int alder;

public:
    explicit Person(std::string navn = "NN", int alder = 0);
    void setNavn(std::string navn);
    std::string getNavn();
    void setAlder(int alder);
    int getAlder();
    void print();
};

#endif // PERSON_H
