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
    Person()
    {
        age = -1;
        gender = Male;
        firstName = "";
        lastName = "";
    }
    Person(int age, Gender gender, string firstName, string lastName)
    {
        this->age = age;
        this->gender = gender;
        this->firstName = firstName;
        this->lastName = lastName;
    }
    Person(Person& person)
    {
         this->age = person.age;
        this->gender = person.gender;
        this->firstName = person.firstName;
        this->lastName = person.lastName;
    }
    void SetAge(int age)
    {
        this->age = age;
    }
    int GetAge()
    {
        return age;
    }
    Gender GetGender()
    {
        return gender;
    }
    void SetFirstName(string name)
    {
        firstName = name;
    }
    void SetLastName(string lastName)
    {
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
