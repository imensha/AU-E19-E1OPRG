#include <string>

class Inventory
{
private:
    std::string description;
    int balance;

public:
    Inventory(std::string, int);
    void Purchase();
    void Sale();
    int getStock() const;
    std::string getDescription() const;
    void setDescription(std::string);
    void display();
};