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
    Class& operator+=(Person& student)
    {
        students.Add(&student);
        return *this;
    }
    Class& operator-=(Person& student)
    {
        students.Remove(&student);
        return *this;
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
