#ifndef CLASS_HPP_INCLUDED
#define CLASS_HPP_INCLUDED

#include "Person.hpp"
#include "Professor.hpp"
#include "Timetable.hpp"
#include "Diary.hpp"

class Class
{
protected:
    float minimumPoints;
    int grade;
    int number;
    string direction;
    List<Person> students;
    Professor* teacher;
    Timetable* timetable;
    Diary diary;
public:
    Class()
    {
        minimumPoints = 0;
        grade = 1;
        direction = "Nista";
        teacher = null;
        timetable = null;
    }
    Class(float minimumPoints, int number, string direction) : diary(1, number)
    {
        grade = 1;
        this->direction = direction;
        this->number = number;
    }
    Class(Class& copyClass)
    {
        minimumPoints = copyClass.minimumPoints;
        grade = copyClass.grade;
        direction = copyClass.direction;
        students = copyClass.students;
        teacher = copyClass.teacher;
        timetable = copyClass.timetable;
    }
    void SetMinimumPoints(float m)
    {
        minimumPoints = m;
    }
    void SetGrade(int g)
    {
        grade = g;
    }
    void SetNumber(int n)
    {
        number = n;
    }
    void SetDirection(string direction)
    {
        this->direction = direction;
    }
    void SetTimetable(Timetable* timetable)
    {
        this->timetable = timetable;
    }
    Timetable* GetTimetable()
    {
        return timetable;
    }
    void AddStudent(Person& student)
    {
        students.Add(&student);
        StudentDiaryPage* page = (new StudentDiaryPage((Student*)(&student)));
        diary.AddStudentDiaryPage(page);
    }
    void RemoveStudent(Person& student)
    {
        students.Remove(&student);
        diary.RemoveStudentDiaryPage(student.GetFirstName(), student.GetLastName());
    }

    void ChangeTeacher(Professor& professor)
    {
        teacher = &professor;
    }
    Professor* GetTeacher()
    {
        return teacher;
    }
    string GetDirection()
    {
        return direction;
    }
    int GetGrade()
    {
        return grade;
    }
    int GetStudentAmount()
    {
        return students.Length();
    }
    float GetMinimumPoints()
    {
        return minimumPoints;
    }

    Person& operator[](int index)
    {
        return students[index];
    }
    Class& operator+=(Person& student)
    {
        AddStudent(student);
        return *this;
    }
    Class& operator-=(Person& student)
    {
        RemoveStudent(student);
        return *this;
    }
    Diary& GetDiary()
    {
        return diary;
    }

    friend ostream& operator<<(ostream& out, Class& thisClass)
    {
        out << "\nClass " << thisClass.grade << " " << thisClass.number << endl;
        out << "Direction: " << thisClass.direction << endl;
        out << "Teacher: " << thisClass.teacher->GetFirstName() << " " << thisClass.teacher->GetLastName() << endl;
        out << "Students: " << endl;
        for(int i = 0; i < thisClass.students.Length(); i++)
        {
            out << thisClass.students[i];
        }
        return out;
    }
};

#endif // CLASS_HPP_INCLUDED
