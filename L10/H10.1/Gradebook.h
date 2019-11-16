#include <string>

class Gradebook
{
public:
    explicit Gradebook(std::string name, std::string instructor);
    void setCourseName(std::string);
    std::string getCourseName() const;
    void setInstructorName(std::string);
    std::string getInstructorName() const;
    void displayMessage() const;

private:
    std::string courseName;
    std::string instructorName;
};