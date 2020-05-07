#ifndef PROFESSOR_HPP_INCLUDED
#define PROFESSOR_HPP_INCLUDED

#include "Employee.hpp"

class Professor : public Employee
{
protected:
    SubjectTypes subject;
public:
    Professor()
    {
        subject = Mathematics;
    }
    Professor(float elementarySchoolTestPoints, float highSchoolTestPoints, float universityHighTestPoints,List<ReportCard> reportCards, int age, Gender gender, string firstName, string lastName, SubjectTypes subject) :
        Employee(elementarySchoolTestPoints,highSchoolTestPoints,  universityHighTestPoints, reportCards, age,gender,firstName,lastName)
    {
        this->subject = subject;
    }
    Professor(Professor& professor)
    {
        reportCards = professor.reportCards;
        age = professor.age;
        gender = professor.gender;
        firstName = professor.firstName;
        lastName = professor.lastName;
        subject = professor.subject;
    }

    SubjectTypes GetSubject()const
    {
        return subject;
    }

    string Position()
    {
        return "Professor";
    }
};

#endif // PROFESSOR_HPP_INCLUDED
