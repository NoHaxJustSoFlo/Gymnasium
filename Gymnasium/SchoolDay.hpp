#ifndef SCHOOLDAY_HPP_INCLUDED
#define SCHOOLDAY_HPP_INCLUDED

#include "Subject.hpp"
#include "List.hpp"

enum SchoolDays{ Monday, Tuesday, Wednesday, Thursday, Friday};

class SchoolDay
{
protected:
    SchoolDays day;
    List<Subject> subjects;
public:
    SchoolDay(SchoolDays day)
    {
        this->day = day;
    }
    void ChangeSubjects(List<Subject> subjects)
    {
        this->subjects = subjects;
    }
    SchoolDays GetDay()
    {
        return day;
    }
};


#endif // SCHOOLDAY_HPP_INCLUDED
