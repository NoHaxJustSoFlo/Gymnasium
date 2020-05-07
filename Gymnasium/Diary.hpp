#ifndef DIARY_HPP_INCLUDED
#define DIARY_HPP_INCLUDED

#include "StudentDiaryPage.hpp"
#include "Note.hpp"

class Diary
{
protected:
    int grade;
    int number;
    List<StudentDiaryPage> pages;
    List<Note> notes;
public:
    Diary()
    {
        grade = 0;
        number = 0;
    }
    Diary(int grade, int number)
    {
        this->grade = grade;
        this->number = number;
    }
    Diary(Diary& diary)
    {
        grade = diary.grade;
        number = diary.number;
        pages = diary.pages;
        notes = diary.notes;
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
    void AddNote(Note* note)
    {
        notes.Add(note);
    }
    void AddStudentDiaryPage(StudentDiaryPage* studentDiaryPage)
    {
        pages.Add(studentDiaryPage);
    }
    void RemoveStudentDiaryPage(string firstName, string lastName)
    {
        StudentDiaryPage* sdp = GetStudentDiaryPage(firstName, lastName);
        pages.Remove(sdp);
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
