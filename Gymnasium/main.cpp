#include <iostream>
#define null NULL
#include <chrono>
#include <cstring>
#include "Gymnasium.hpp"
#include "Class.hpp"
#include "Timetable.hpp"
#include "SchoolDay.hpp"
#include "Diary.hpp"
#include "Note.hpp"
#include "StudentDiaryPage.hpp"
#include "Grades.hpp"
#include "Subject.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "ReportCard.hpp"
#include "CompletedSubject.hpp"
#include "Grade.hpp"
#include "Date.hpp"
#include "Person.hpp"
#include "List.hpp"
#include "Enums.hpp"
#include "Director.hpp"
#include "Employee.hpp"
#include "Cleaner.hpp"

using namespace std;

int main()
{
    List<Class> classes;
    Class newClass(94.4, 5, "Ucenici sa posebnim sposobnostima za racunarstvo i informatiku");
    Person person(16, Male, "Toni", "Skrijelj");
    newClass.AddStudent(person);
    classes.Add(&newClass);
    List<Employee> employees;
    List<ReportCard> professorsReportCards;
    List<CompletedSubject> completedSubjects;
    List<int> grades;
    grades.Add(new int{10});
    grades.Add(new int{10});
    grades.Add(new int{10});
    grades.Add(new int{10});
    CompletedSubject subject(Programming, grades);
    completedSubjects.Add(&subject);
    ReportCard reportCard("DMI", University, 4, completedSubjects);
    professorsReportCards.Add(&reportCard);
    Professor professor(100, 100, 100, professorsReportCards, 25, Male, "Milan", "Stankovic", Programming);
    employees.Add(&professor);
    newClass.ChangeTeacher(professor);
    Gymnasium gymnasium("Gimnazija ""Jovan Jovanovic Zmaj""",classes, employees);

    cout << gymnasium;

    List<int> grades1;
    List<CompletedSubject> completedSubjects1;
    grades1.Add(new int{9});
    grades1.Add(new int{10});
    grades1.Add(new int{10});
    CompletedSubject subject1(Mathematics, grades1);
    List<ReportCard> professorsReportCards1;
    completedSubjects1.Add(&subject1);
    ReportCard reportCard1("DMI", University, 4, completedSubjects1);
    professorsReportCards1.Add(&reportCard1);

    Professor professor1(100, 100, 100, professorsReportCards1, 30, Female, "Natasa", "Kovac", Mathematics);
    employees.Add(&professor1);
    List<Subject> subjects;
    Subject subject2(1, 24, Mathematics, professor);
    subjects.Add(&subject2);
    List<SchoolDay> schoolDays;
    SchoolDay schoolDay(Monday);
    schoolDay.ChangeSubjects(subjects);
    schoolDays.Add(&schoolDay);

    Timetable timetable(schoolDays);

    Grade grade(5, "sef");
    newClass.GetDiary().GetStudentDiaryPage("Toni", "Skrijelj")->AddGrade(Programming, &grade);

    Note note(&professor1, (Student*)(&person), "boze me sacuvaj");
    newClass.GetDiary().AddNote(&note);
    return 0;
}

