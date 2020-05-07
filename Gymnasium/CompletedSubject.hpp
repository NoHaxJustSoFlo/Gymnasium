#ifndef COMPLETEDSUBJECT_HPP_INCLUDED
#define COMPLETEDSUBJECT_HPP_INCLUDED

class CompletedSubject
{
protected:
    SubjectTypes subject;
    List<int> grades;
    float averageGrade;
public:
    CompletedSubject()
    {
        subject = Mathematics;
        averageGrade = -1;
    }
    CompletedSubject(SubjectTypes subject, List<int> grades)
    {
        this->subject = subject;
        this->grades = grades;
        float amount = grades.Length();
        float total = 0;
        for(int i = 0; i < amount; i++)
        {
            total += grades[i];
        }
        averageGrade = total / amount;
    }
    CompletedSubject(CompletedSubject& subjectCom)
    {
        subject = subjectCom.subject;
        grades = subjectCom.grades;
        averageGrade = subjectCom.averageGrade;
    }
    float GetAverageGrade()
    {
        return averageGrade;
    }
};

#endif // COMPLETEDSUBJECT_HPP_INCLUDED
