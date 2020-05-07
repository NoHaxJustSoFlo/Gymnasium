#ifndef PERSON_HPP_INCLUDED
#define PERSON_HPP_INCLUDED

#include "Enums.hpp"

class Person
{
protected:
    int age;
    Gender gender;
    string firstName;
    string lastName;
public:

    Person(int age, Gender gender, string firstName, string lastName)
    {
        this->age = age;
        this->gender = gender;
        this->firstName = firstName;
        this->lastName = lastName;
    }
    string GetFirstName()
    {
        return firstName;
    }
    string GetLastName()
    {
        return lastName;
    }
    friend ostream& operator<<(ostream& out, Person& person)
    {
        cout << person.firstName << " " << person.lastName << endl;
        return out;
    }
};



#endif // PERSON_HPP_INCLUDED
