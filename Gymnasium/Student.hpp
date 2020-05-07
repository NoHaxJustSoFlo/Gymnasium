#ifndef STUDENT_HPP_INCLUDED
#define STUDENT_HPP_INCLUDED

#include "ReportCard.hpp"

class Student : public Person
{
protected:
    List<ReportCard> reportCards;
    float elementarySchoolTestPoints;
    float highSchoolTestPoints;
public:
    Student(float elementarySchoolTestPoints, float highSchoolTestPoints, List<ReportCard> reportCards, int age, Gender gender, string firstName, string lastName) : Person(age, gender, firstName, lastName)
    {
        this->elementarySchoolTestPoints = elementarySchoolTestPoints;
        this->highSchoolTestPoints = highSchoolTestPoints;
        this->reportCards = reportCards;
    }
    void AddReportCard(ReportCard* reportCard)
    {
        reportCards.Add(reportCard);
    }
    List<ReportCard> GetReportCards()
    {
        return reportCards;
    }
    float GetAverageGrade(EducationLevel education, int grade)
    {
        for(int i = 0; i < reportCards.Length(); i++)
        {

            if(reportCards[i].GetEducationLevel() == education && reportCards[i].GetGrade() == grade)
            {
                return reportCards[i].GetOverallGrade();
            }
        }
        cout << "ERROR: STUDENT DOES NOT HAVE REPORT CARD WITH EDUCATION LEVEL: " << education << " , GRADE: " << grade << "!!!" << endl;
        return -1;
    }
    int GetElementarySchoolTestPoints()
    {
        return elementarySchoolTestPoints;
    }
};

#endif // STUDENT_HPP_INCLUDED
