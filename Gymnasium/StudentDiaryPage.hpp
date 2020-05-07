#ifndef STUDENTDIARYPAGE_HPP_INCLUDED
#define STUDENTDIARYPAGE_HPP_INCLUDED


#include "Grades.hpp"

class StudentDiaryPage
{
protected:
    Student* student;
    List<Grades> subjects;
public:
    StudentDiaryPage(Student* student)
    {
        this->student = student;
    }
    Student* GetStudent()
    {
        return student;
    }
    void AddGrade(SubjectTypes subject, Grade* grade)
    {
        for(int i = 0; i < subjects.Length(); i++)
        {
            if(subjects[i].GetSubject() == subject)
            {
                subjects[i].AddGrade(grade);
            }
        }
    }
    void RemoveGrade(SubjectTypes subject, Grade* grade)
    {
        for(int i = 0; i < subjects.Length(); i++)
        {
            if(subjects[i].GetSubject() == subject)
            {
                subjects.RemoveAt(i);
            }
        }
    }
};

#endif // STUDENTDIARYPAGE_HPP_INCLUDED
