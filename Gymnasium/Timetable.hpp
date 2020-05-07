#ifndef TIMETABLE_HPP_INCLUDED
#define TIMETABLE_HPP_INCLUDED

#include "SchoolDay.hpp"

class Timetable
{
protected:
    List<SchoolDay> days;
public:
    Timetable(List<SchoolDay> days)
    {
        this->days = days;
    }
    void ChangeSchoolDay(SchoolDays day, List<Subject> subjects)
    {
        days.Clear();
        for(int i = 0; i < days.Length(); i++)
        {
            if(days[i].GetDay() == day)
            {
                days[i].ChangeSubjects(subjects);
            }
        }
    }
};
#endif // TIMETABLE_HPP_INCLUDED
