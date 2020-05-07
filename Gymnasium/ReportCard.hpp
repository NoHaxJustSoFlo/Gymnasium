#ifndef REPORTCARD_HPP_INCLUDED
#define REPORTCARD_HPP_INCLUDED


#include "CompletedSubject.hpp"

class ReportCard
{
protected:
    string schoolName;
    EducationLevel educationLevel;
    int grade;
    List<CompletedSubject> completedSubjects;
    float overallGrade;
public:
    ReportCard(string schoolName, EducationLevel educationLevel, int grade, List<CompletedSubject> completedSubjects)
    {
        this->schoolName = schoolName;
        this->educationLevel = educationLevel;
        this->grade = grade;
        this->completedSubjects = completedSubjects;
        float amount = completedSubjects.Length();
        float total = 0;
        for(int i = 0; i < amount; i++)
        {
            total += completedSubjects[i].GetAverageGrade();
        }
        overallGrade = total / amount;
    }
    EducationLevel GetEducationLevel()
    {
        return educationLevel;
    }
    int GetGrade()
    {
        return grade;
    }
    float GetOverallGrade()
    {
        return overallGrade;
    }
};
#endif // REPORTCARD_HPP_INCLUDED
