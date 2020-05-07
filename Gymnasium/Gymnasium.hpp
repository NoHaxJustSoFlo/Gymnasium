#ifndef GYMNASIUM_HPP_INCLUDED
#define GYMNASIUM_HPP_INCLUDED

#include "List.hpp"
#include "Class.hpp"
#include "Student.hpp"
#include "Employee.hpp"

using namespace std;

class Gymnasium
{
protected:
    string name;
    List<Class> classes;
    List<Employee> employees;
public:
    Gymnasium(){}
    Gymnasium(string name, List<Class> classes, List<Employee> employees)
    {
        this->name = name;
        this->classes = classes;
        this->employees = employees;
    }
    Gymnasium(Gymnasium& gymnasium)
    {
        this->name = name;
        this->classes = classes;
        this->employees = employees;
    }
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
                float total = student.GetAverageGradeInGrade(Elementary, 6);
                total += student.GetAverageGradeInGrade(Elementary, 7);
                total += student.GetAverageGradeInGrade(Elementary, 8);
                if(total * 2 + student.GetPointsOnFinalTest(Elementary) > minimumPoints)
                {
                    currentClass.AddStudent(student);
                    return true;
                }
            }
        }
        return false;
    }
    void AddEmployee(Employee* employee)
    {
        employees.Add(employee);
    }
    void RemoveEmployee(Employee* employee)
    {
        employees.Remove(employee);
    }

    List<Employee> GetEmployees(string position)
    {
        List<Employee> specificEmployees;
        for(int i = 0; i < employees.Length(); i++)
        {
            if(employees[i].Position() == position)
            {
                specificEmployees.Add(&employees[i]);
            }
        }
        return specificEmployees;
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

    friend ostream& operator<<(ostream& out, Gymnasium& gymnasium)
    {
        out << "\tGYMNASIUM: " << gymnasium.name << endl;
        out << "Employees:\n";
        for(int i = 0; i < gymnasium.employees.Length(); i++)
        {
            out << gymnasium.employees[i] << endl;
        }
        out << gymnasium.classes.Length();
        for(int i = 0; i < gymnasium.classes.Length(); i++)
        {
            out << gymnasium.classes[i] << endl;
        }
        return out;
    }
    Gymnasium& operator+=(Employee& employee)
    {
        employees.Add(&employee);
        return *this;
    }
    Gymnasium& operator-=(Employee& employee)
    {
        employees.Remove(&employee);
        return *this;
    }

};

#endif // GYMNASIUM_HPP_INCLUDED
