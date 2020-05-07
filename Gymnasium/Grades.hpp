#ifndef GRADES_HPP_INCLUDED
#define GRADES_HPP_INCLUDED

#include "Grade.hpp"

class Grades
{
protected:
    List<Grade> grades;
    SubjectTypes subject;
public:
    Grades(SubjectTypes subject)
    {
        this->subject = subject;
    }
    void AddGrade(Grade* grade)
    {
        grades.Add(grade);
    }
    SubjectTypes GetSubject()
    {
        return subject;
    }
};




#endif // GRADES_HPP_INCLUDED
