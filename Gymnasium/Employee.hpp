#ifndef EMPLOYEE_HPP_INCLUDED
#define EMPLOYEE_HPP_INCLUDED

#include "Student.hpp"

class Employee : public Student
{
public:
    Employee()
    {

    }
    Employee(float elementarySchoolTestPoints, float highSchoolTestPoints, float universityHighTestPoints,List<ReportCard> reportCards, int age, Gender gender, string firstName, string lastName) :
        Student(elementarySchoolTestPoints, highSchoolTestPoints, universityHighTestPoints, reportCards, age, gender, firstName, lastName)
    {

    }

    virtual string Position() = 0;

    friend ostream& operator<<(ostream& out, Employee& employee)
    {
        cout << employee.GetFirstName() << " " << employee.GetLastName() << ": " << employee.Position() << endl;
        return out;
    }
};


#endif // EMPLOYEE_HPP_INCLUDED
