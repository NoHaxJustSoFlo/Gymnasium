#ifndef CLASS_HPP_INCLUDED
#define CLASS_HPP_INCLUDED

#include "Person.hpp"
#include "Professor.hpp"
#include "Timetable.hpp"

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
public:
    Class(float minimumPoints, int number, string direction)
    {
        grade = 1;
        this->direction = direction;
        this->number = number;
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
    }
    void RemoveStudent(Person& student)
    {
        students.Remove(&student);
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
};

#endif // CLASS_HPP_INCLUDED
