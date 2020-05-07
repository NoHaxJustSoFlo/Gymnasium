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
    Grade() : date(Date::GetCurrentDate())
    {
        grade = -1;
        description = "";
    }
    Grade(int grade, string description) : date(Date::GetCurrentDate())
    {
        this->description = description;
        this->grade = grade;
    }
    void SetGrade(int grade)
    {
        this->grade = grade;
    }
    void SetDescription(string description)
    {
        this->description = description;
    }
    int GetGrade()
    {
        return grade;
    }
    Date GetDate()
    {
        return date;
    }
    string GetDescription()
    {
        return description;
    }
};


#endif // GRADE_HPP_INCLUDED
