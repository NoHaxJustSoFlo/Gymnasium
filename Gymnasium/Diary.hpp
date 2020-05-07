#ifndef DIARY_HPP_INCLUDED
#define DIARY_HPP_INCLUDED

#include "StudentDiaryPage.hpp"

class Diary
{
protected:
    int grade;
    int number;
    List<StudentDiaryPage> pages;
public:
    Diary(int grade, int number)
    {
        this->grade = grade;
        this->number = number;
    }
    StudentDiaryPage* GetStudentDiaryPage(string firstName, string lastName)
    {
        for(int i = 0; i < pages.Length(); i++)
        {
            Student* student = pages[i].GetStudent();
            if(student->GetFirstName() == firstName && student->GetLastName() == lastName)
            {
                return &pages[i];
            }
        }
        return null;
    }
    StudentDiaryPage* operator[](Student* student)
    {
        for(int i = 0; i < pages.Length(); i++)
        {
            if(pages[i].GetStudent() == student)
            {
                return &pages[i];
            }
        }
        return null;
    }
    StudentDiaryPage* operator[](int page)
    {
        return &pages[page - 1];
    }
};


#endif // DIARY_HPP_INCLUDED
