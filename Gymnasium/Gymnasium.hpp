#ifndef GYMNASIUM_HPP_INCLUDED
#define GYMNASIUM_HPP_INCLUDED

#include "List.hpp"
#include "Class.hpp"
#include "Student.hpp"

using namespace std;

class Gymnasium
{
protected:
    string name;
    List<Class> classes;
public:
    void AddClass(Class* newClass)
    {
        classes.Add(newClass);
    }
    bool Enroll(Student& student, string direction, int grade)
    {
        for(int i = 0; i < classes.Length(); i++)
        {
            Class& currentClass = classes[i];
            if(currentClass.GetDirection() == direction && currentClass.GetGrade() == grade && currentClass.GetStudentAmount() < 20)
            {
                float minimumPoints = currentClass.GetMinimumPoints();
                float total = student.GetAverageGrade(Elementary, 6);
                total += student.GetAverageGrade(Elementary, 7);
                total += student.GetAverageGrade(Elementary, 8);
                if(total * 2 + student.GetElementarySchoolTestPoints() > minimumPoints)
                {
                    currentClass.AddStudent(student);
                    return true;
                }
            }
        }
        return false;
    }
    string GetName()
    {
        return name;
    }
    void SetName(string _name)
    {
        name = _name;
    }
    List<Class> GetClasses()
    {
        return classes;
    }
    void SetClasses(List<Class> _classes)
    {
        classes = _classes;
    }
};

#endif // GYMNASIUM_HPP_INCLUDED
