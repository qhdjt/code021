#include <iostream>
using namespace std;

struct Student
{
    std::string name;
    int age;
    double finalGrade;

    std::string toString() const;
};

ostream &operator<<(ostream &os, const Student &s)
{
    return (os << "Name:" << s.name << "Age:" << s.age << "Final Grade:" << s.finalGrade << std::endl);
}

int main()
{

    Student stud{"john baker", 25, 1.2};
    std::cout << "stud directly:" << stud << endl;
    std::string studStr = stud.toString();
    std::cout << "stud toString:" << studStr << endl;
}