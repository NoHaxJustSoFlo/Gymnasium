#ifndef DIRECTOR_HPP_INCLUDED
#define DIRECTOR_HPP_INCLUDED

class Director : Employee
{
public:
    Director(float elementarySchoolTestPoints, float highSchoolTestPoints, float universityHighTestPoints,List<ReportCard> reportCards, int age, Gender gender, string firstName, string lastName)
    : Employee(elementarySchoolTestPoints, highSchoolTestPoints, universityHighTestPoints, reportCards, age, gender, firstName, lastName)
    {

    }

    string GetPosition()
    {
        return "Director";
    }

};


#endif // DIRECTOR_HPP_INCLUDED
