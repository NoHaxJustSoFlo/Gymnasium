#ifndef SUBJECT_HPP_INCLUDED
#define SUBJECT_HPP_INCLUDED

class Subject
{
protected:
    int index;
    SubjectTypes type;
    Professor* professor;
    int classroomNumber;
public:
    Subject(int index, int classroomNumber, SubjectTypes type, Professor& professor)
    {
        this->index = index;
        this->classroomNumber = classroomNumber;
        this->type = type;
        this->professor = &professor;
    }
    void ChangeProfessor(Professor& professor)
    {
        this->professor = &professor;
    }
    SubjectTypes GetType()const
    {
        return type;
    }
    Professor& GetProfessor()
    {
        return *professor;
    }
};


#endif // SUBJECT_HPP_INCLUDED
