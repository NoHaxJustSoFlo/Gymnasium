#ifndef PROFESSOR_HPP_INCLUDED
#define PROFESSOR_HPP_INCLUDED



class Professor : public Person
{
protected:
    SubjectTypes subject;
public:
    Professor(int age, Gender gender, string firstName, string lastName, SubjectTypes subject) : Person(age, gender, firstName, lastName)
    {
        this->subject = subject;
    }

    SubjectTypes GetSubject()const
    {
        return subject;
    }
};

#endif // PROFESSOR_HPP_INCLUDED
