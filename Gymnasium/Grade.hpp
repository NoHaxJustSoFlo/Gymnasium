#ifndef GRADE_HPP_INCLUDED
#define GRADE_HPP_INCLUDED

#include "Date.hpp"

class Grade
{
protected:
    int grade;
    Date date;
    string description;
public:
    Grade(int grade, string description) : date(Date::GetCurrentDate())
    {
        this->description = description;
        this->grade = grade;
    }
};


#endif // GRADE_HPP_INCLUDED
