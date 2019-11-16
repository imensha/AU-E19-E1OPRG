#include <string>

class Child
{
private:
    std::string name_;
    unsigned int age_;

public:
    Child(std::string name = "Ukendt navn", unsigned int age = 0);
    std::string getName();
    void setName(std::string name);
    unsigned int getAge();
    void setAge(unsigned int age);
    void print();
};
