#ifndef CLEANER_HPP_INCLUDED
#define CLEANER_HPP_INCLUDED

#include "Employee.hpp"

class Cleaner : Employee
{
public:
    Cleaner()
    {

    }
    Cleaner(float elementarySchoolTestPoints, float highSchoolTestPoints, float universityHighTestPoints,List<ReportCard> reportCards, int age, Gender gender, string firstName, string lastName)
    : Employee(elementarySchoolTestPoints, highSchoolTestPoints, universityHighTestPoints, reportCards, age, gender, firstName, lastName)
    {

    }
    Cleaner(Cleaner& cleaner) : Employee(cleaner)
    {

    }

    string GetPosition()
    {
        return "Cleaner";
    }

};

#endif // CLEANER_HPP_INCLUDED
