#ifndef STUDENT_HPP_INCLUDED
#define STUDENT_HPP_INCLUDED

#include "ReportCard.hpp"
#include "FinalTest.hpp"

class Student : public Person
{
protected:
    List<ReportCard> reportCards;
    List<FinalTest> testPoints;
public:
    Student()
    {

    }
    Student(float elementarySchoolTestPoints, float highSchoolTestPoints, float universityHighTestPoints,List<ReportCard> reportCards, int age, Gender gender, string firstName, string lastName) : Person(age, gender, firstName, lastName)
    {
        if(elementarySchoolTestPoints >= 0)
        {
            testPoints.Add(new FinalTest(elementarySchoolTestPoints, 100, Elementary));
        }
        if(highSchoolTestPoints >= 0)
        {
            testPoints.Add(new FinalTest(highSchoolTestPoints, 100, High));
        }
        if(universityHighTestPoints >= 0)
        {
            testPoints.Add(new FinalTest(universityHighTestPoints, 100, University));
        }
        this->reportCards = reportCards;
    }
    Student(Student& student) : Person(student)
    {
        reportCards = student.reportCards;
        testPoints = student.testPoints;
    }
    void AddReportCard(ReportCard* reportCard)
    {
        reportCards.Add(reportCard);
    }
    List<ReportCard> GetReportCards()
    {
        return reportCards;
    }
    float GetAverageGradeInGrade(EducationLevel education, int grade)
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
    float GetAverageGrade(EducationLevel education)
    {
        float amount = 0;
        float total = 0;
        for(int i = 0; i < reportCards.Length(); i++)
        {
            if(reportCards[i].GetEducationLevel() == education)
            {
                amount++;
                total += reportCards[i].GetOverallGrade();
            }
        }
        if(amount == 0)
        {
            cout << "ERROR: STUDENT DOES NOT HAVE REPORT CARD WITH EDUCATION LEVEL: " << education << "!!!" << endl;
            return -1;
        }
        return total / amount;
    }

    float GetPointsOnFinalTest(EducationLevel educationLevel)
    {
        for(int i = 0; i < testPoints.Length(); i++)
        {
            if(testPoints[i].GetEducationLevel() == educationLevel)
            {
                return testPoints[i].GetPoints();
            }
        }
    }

    friend ostream& operator<<(ostream& out, Student& student)
    {
        out << student.GetFirstName() << " " << student.GetLastName() << endl;
        return out;
    }
};

#endif // STUDENT_HPP_INCLUDED
