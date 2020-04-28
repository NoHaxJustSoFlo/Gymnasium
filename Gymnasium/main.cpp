#include <iostream>
#define null NULL
#include <chrono>
#include <cstring>

using namespace std;

template<typename T>
class List
{
private:
    struct Node
    {
        T* element;
        Node* next;
        Node* previous;
    };
    Node* first;
    Node* last;
    int length;
public:
    List<T>()
    {
        first = null;
        last = null;
        length = 0;
    }

    int Length()const
    {
        return length;
    }

    void Add(T* element)
    {
        Node* node = new Node;
        node->element = element;
        node->next = null;
        node->previous = null;
        if(first == null)
        {
            first = node;
            last = node;
            length = 1;
            return;
        }
        last->next = node;
        node->previous = last;
        last = node;
        length += 1;
    }

    void Add(T element)
    {
        Add(new T(element));
    }

    void Remove(T* element)
    {
        Node* current = first;
        for(int i = 0; i < length; i++)
        {
            if(current->element == element)
            {
                RemoveAt(i);
                break;
            }
            current = current->next;
        }
    }

    void Remove(T element)
    {
        Node* current = first;
        for(int i = 0; i < length; i++)
        {
            if(*(current->element) == element)
            {
                RemoveAt(i);
                break;
            }
            current = current->next;
        }
    }

    void RemoveAt(int index)
    {
        if(index < 0 || index >= length)
            return;
        Node* temp;
        if(index == 0)
        {
            temp = first;
            first = first->next;
            if(length == 1)
            {
                last = null;
            }
        }
        else if(index == length - 1)
        {
            temp = last;
            last = last->previous;
            last->next = null;
        }
        else
        {
            if(index < length / 2)
            {
                temp = first;
                for(int i = 0; i < index; i++)
                {
                    temp = temp->next;
                }
            }
            else
            {
                temp = last;
                for(int i = length - 1; i > index; i--)
                {
                    temp = temp->previous;
                }
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
        }
        length -= 1;
        delete temp;

    }

    T& operator[](int index)
    {
        if(index < 0 || index >= length)
        {
            cout << "\n**************************************\nERROR ACCESING ELEMENT WITH INDEX " << index << "\n**************************************";
        }
        Node* temp;
        if(index < length / 2)
        {
            temp = first;
            for(int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }

        else
        {
            temp = last;
            for(int i = length - 1; i > index; i--)
            {
                temp = temp->previous;
            }
        }
        return *(temp->element);
    }

};

enum SubjectTypes { Mathematics, Art, History, Biology, Chemistry, Programming, Geography, English, Serbian, Music };
enum Gender { Male, Female };

/// Food i sve Food izvedene klase racunam kao jednu klasu
class Food
{
public:
    virtual int Consume() = 0;
};

class Apple : public Food
{
public:
    int Consume() override
    {
        return 2;
    }
};

class Person
{
protected:
    int age;
    Gender gender;
    string firstName;
    string lastName;
    float height;
    float weight;
    int happiness;
    int energy;
    bool ill;
public:

    Person(int age, Gender gender, string firstName, string lastName, float height, float weight)
    {
        this->age = age;
        this->gender = gender;
        this->firstName = firstName;
        this->lastName = lastName;
        this->height = height;
        this->weight = weight;
        happiness = 100;
        energy = 100;
        ill = false;
    }
    void BecomeIll()
    {
        ill = true;
    }
    void Heal()
    {
        ill = false;
    }
    bool IsIll()
    {
        return ill;
    }
    void Eat(Food& food)
    {
        happiness++;
        energy += food.Consume();
    }
    void Sleep(float hours)
    {
        if(hours >= 6)
        {
            happiness++;
            energy++;
        }
        else
        {
            happiness--;
        }
    }
    void Exercise()
    {
        happiness++;
        energy--;
    }
};

const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

class Date
{
protected:
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;
public:
    static char* GetCurrentDate()
    {
            auto start = std::chrono::system_clock::now();
            time_t time = chrono::system_clock::to_time_t(start);
            return ctime(&time);
    }

    Date(char* ctimeDateString)
    {
        char month1[4];
        sscanf(ctimeDateString,"%*s%s%d%d%*c%d%*c%d%d", month1,&day,&hours,&minutes,&seconds,&year);
        /*cout << day << endl;
        cout << hours << endl;
        cout << minutes << endl;
        cout << seconds << endl;
        cout << year << endl;*/
        for(int i = 0; i <= 12; i++)
        {
            if(strcmp(months[i], month1) == 0)
            {
                this->month = i + 1;
                break;
            }
        }
        //cout << month << endl;
    }
};

class Grade
{
protected:
    int grade;
    SubjectTypes subject;
    Date date;
public:
    Grade(int grade, SubjectTypes subject) : date(Date::GetCurrentDate())
    {
        this->grade = grade;
        this->subject = subject;
    }
    SubjectTypes GetSubject()const
    {
        return subject;
    }
};

class MissedClass
{
protected:
    SubjectTypes subject;
    Date dateOfClass;
public:
    MissedClass(SubjectTypes subject) : dateOfClass(Date::GetCurrentDate())
    {
    }
};

class Student : public Person
{
protected:
    List<Grade> grades;
    List<MissedClass> missedClasses;

public:
    Student(int age, Gender gender, string firstName, string lastName, float height, float weight) : Person(age, gender, firstName, lastName, height, weight)
    {
    }
    void MissClass(SubjectTypes subject)
    {
        missedClasses.Add(new MissedClass(subject));
    }

    void AddGrade(Grade& grade)
    {
        grades.Add(&grade);
    }
    List<Grade> GetGrades(SubjectTypes subject)
    {
        List<Grade> subjectGrades;
        for(int i = 0; i < grades.Length(); i++)
        {
            if(grades[i].GetSubject() == subject)
            {
                subjectGrades.Add(&grades[i]);
            }
        }
        return subjectGrades;
    }
};

class Professor : public Person
{
protected:
    SubjectTypes subject;
public:
    Professor(int age, Gender gender, string firstName, string lastName, float height, float weight, SubjectTypes subject) : Person(age, gender, firstName, lastName, height, weight)
    {
        this->subject = subject;
    }

    SubjectTypes GetSubject()const
    {
        return subject;
    }

    void GradeStudent(int grade, Student& student)
    {
        Grade* newGrade = new Grade(grade, subject);
        student.AddGrade(*newGrade);
    }

    void HoldClass(List<Student> students)
    {
        for(int i = 0; i < students.Length(); i++)
        {
            if(students[i].IsIll())
            {
                students[i].MissClass(subject);
            }
        }
        students[rand() % students.Length()].AddGrade(*(new Grade(rand() % 5 + 1, subject))); ///
    }
};

class Subject
{
protected:
    SubjectTypes type;
    Professor* professor;
public:
    Subject(SubjectTypes type, Professor& professor)
    {
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

class Class
{
protected:
    int grade;
    int number;
    string direction;
    List<Student> students;
    Professor* teacher;
    List<Subject> subjects;
public:
    Class(int number, string direction)
    {
        grade = 1;
        this->direction = direction;
        this->number = number;
    }
    void AddStudent(Student& student)
    {
        students.Add(&student);
    }
    void RemoveStudent(Student& student)
    {
        students.Add(&student);
    }
    void ChangeTeacher(Professor& professor)
    {
        teacher = &professor;
    }
    void RemoveSubject(Subject& subject)
    {
        subjects.Remove(&subject);
    }
    void AddSubject(Subject& subject)
    {
        subjects.Add(&subject);
    }
    bool PassGrade()
    {
        return (++grade) == 5;
    }
    string GetDirection()
    {
        return direction;
    }
    int GetGrade()
    {
        return grade;
    }
    int GetStudentAmount()
    {
        return students.Length();
    }
    void TakeClass(SubjectTypes subject)
    {
        for(int i = 0; i < subjects.Length(); i++)
        {
            if(subjects[i].GetType() == subject)
            {
                subjects[i].GetProfessor().HoldClass(students);
            }
        }
    }
    Student& operator[](int index)
    {
        return students[index];
    }
};

class Gymnasium
{
protected:
    string name;
    List<Class> classes;
public:
    void EndYear()
    {
        for(int i = 0; i < classes.Length(); i++)
        {
            if(classes[i].PassGrade());
            {
                classes.RemoveAt(i);
                i--;
            }
        }
    }
    bool Enroll(Student& student, string direction, int grade)
    {
        for(int i = 0; i < classes.Length(); i++)
        {
            Class& currentClass = classes[i];
            if(currentClass.GetDirection() == direction && currentClass.GetGrade() == grade && currentClass.GetStudentAmount() < 20)
            {
                currentClass.AddStudent(student);
                return true;
            }
        }
        return false;
    }

};

int main()
{

}

/*

    auto start = std::chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(start);

    Date date(ctime(&time));
    //cout << date.year << endl;
    //cout << date.month;
    return 0;

List<SubjectTypes> subjects;
    subjects.AddEqual(Mathematics);
    subjects.AddEqual(Biology);
    cout << subjects[0];
    cout << subjects[1];
    subjects.RemoveEqual(Mathematics);
    cout << subjects[0];
}

Int broj1(1);
Int broj2(2);
Int broj3(3);
Int broj4(4);

List<Int> brojevi;

brojevi.Add(broj1);
brojevi.Add(broj2);
brojevi.Add(broj3);

cout << brojevi[0].value << endl;
cout << brojevi[1].value << endl;
cout << brojevi[2].value << endl << endl;

brojevi.RemoveAt(1);

cout << brojevi[0].value << endl;
cout << brojevi[1].value << endl << endl;

brojevi.Remove(broj1);

cout << brojevi[0].value << endl << endl;

brojevi.RemoveAt(0);

brojevi.Add(broj1);
brojevi.Add(broj3);
brojevi.Add(broj4);
brojevi.Add(broj2);

cout << brojevi[0].value << endl;
cout << brojevi[1].value << endl;
cout << brojevi[2].value << endl;
cout << brojevi[3].value << endl << endl;

brojevi.Remove(broj4);

cout << brojevi[0].value << endl;
cout << brojevi[1].value << endl;
cout << brojevi[2].value << endl << endl;

brojevi.RemoveAt(2);

cout << brojevi[0].value << endl;
cout << brojevi[1].value << endl << endl;
*/
