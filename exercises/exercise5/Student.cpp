#include <iostream>
#include <cstring>

#include "Student.hpp"

using namespace std;

Student::Student():
    averageGrades(0), facultyNumber(0)
{
    name = new char[1];
    name[0] = '\0';
}

Student::Student(const char* _name,
                 double _averageGrades,
                 unsigned _facultyNumber):
    averageGrades(_averageGrades), facultyNumber(_facultyNumber)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

Student::Student(const Student& other)
{
    copy(other);
}

Student::~Student()
{
    del();
}

Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

const char* Student::getName() const
{
    return name;
}

double Student::getAverageGrades() const
{
    return averageGrades;
}

unsigned Student::getFacultyNumber() const
{
    return facultyNumber;
}

void Student::setName(const char* _name)
{
    delete[] name;

    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

void Student::setAverageGrades(double _averageGrades)
{
    averageGrades = _averageGrades;
}

void Student::setFacultyNumber(unsigned _facultyNumber)
{
    facultyNumber = _facultyNumber;
}

void Student::print() const
{
    cout << "Name: "           << name          << endl
         << "Average grades: " << averageGrades << endl
         << "Faculty number: " << facultyNumber << endl;
}

void Student::copy(const Student& other)
{
    averageGrades = other.averageGrades;
    facultyNumber = other.facultyNumber;

    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void Student::del()
{
    delete[] name;
}
