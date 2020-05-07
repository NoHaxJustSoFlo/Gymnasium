#ifndef FINALTEST_HPP_INCLUDED
#define FINALTEST_HPP_INCLUDED

class FinalTest
{
protected:
    float points;
    float maximumPoints = 100;
    EducationLevel educationLevel;
public:
    FinalTest(float points, float maximumPoints, EducationLevel educationLevel)
    {
        this->points = points;
        this->maximumPoints = maximumPoints;
        this->educationLevel = educationLevel;
    }

    float GetPoints()
    {
        return points;
    }
    void SetPoints(float points)
    {
        this->points = points;
    }
    EducationLevel GetEducationLevel()
    {
        return educationLevel;

    }
    void SetEducationLevle(EducationLevel educationLevel)
    {
        this->educationLevel = educationLevel;
    }

    float GetMaximumPoints()
    {
        return maximumPoints;
    }

    void SetMaximumPoints(float maximumPoints)
    {
        this->maximumPoints = maximumPoints;
    }

    float GetPercentage()
    {
        return points / maximumPoints;
    }
};

#endif // FINALTEST_HPP_INCLUDED
