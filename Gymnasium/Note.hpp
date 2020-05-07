#ifndef NOTE_HPP_INCLUDED
#define NOTE_HPP_INCLUDED

class Note
{
protected:
    Professor* professor;
    Student* student;
    string description;
    Date date;
public:
    Note(Professor* professor, Student* student, string description) : date(Date::GetCurrentDate())
    {
        this->professor = professor;
        this->student = student;
        this->description = description;
    }
    void SetStudent(Student* student)
    {
        this->student = student;
    }
    void SetDescription(string d)
    {
        description = d;
    }
    string GetDescription()
    {
        return description;
    }
    void SetDate(Date d)
    {
        date = d;
    }
    Date GetDate()
    {
        return date;
    }
};


#endif // NOTE_HPP_INCLUDED
