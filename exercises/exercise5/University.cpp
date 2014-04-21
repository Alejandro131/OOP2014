#include <iostream>
#include <algorithm>

#include "University.hpp"

using namespace std;

unsigned University::lastFacultyNumber = 0;

University::University():
    size(0), capacity(1)
{
    students = new Student[capacity];
}

University::University(const University& other)
{
    copy(other);
}

University::~University()
{
    del();
}

University& University::operator=(const University& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

Student University::getStudent(unsigned facultyNumber) const
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (students[i].getFacultyNumber() == facultyNumber)
        {
            return students[i];
        }
    }
}

unsigned University::getNumberOfStudents() const
{
    return size;
}

void University::addStudent(const Student& student)
{
    if (size == capacity)
    {
        extend();
    }

    students[size++] = student;
    students[size - 1].setFacultyNumber(lastFacultyNumber++);
}

void University::removeStudent(unsigned facultyNumber)
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (students[i].getFacultyNumber() == facultyNumber)
        {
            for (unsigned j = i + 1; j < size; ++j)
            {
                students[j - 1] = students[j];
            }

            --size;

            return;
        }
    }
}

void University::sort()
{
    for (unsigned i = 0; i < size - 1; ++i)
    {
        unsigned max = i;

        for (unsigned j = i + 1; j < size; ++j)
        {
            if (students[max].getAverageGrades() < students[j].getAverageGrades())
            {
                max = j;
            }
        }

        if (max != i)
        {
            swap(students[max], students[i]);
        }
    }
}

void University::print() const
{
    for (unsigned i = 0; i < size; ++i)
    {
        students[i].print();
        cout << endl;
    }
}

void University::extend()
{
    Student* oldStudents = students;
    students = new Student[2 * capacity];

    for (unsigned i = 0; i < size; ++i)
    {
        students[i] = oldStudents[i];
    }

    delete[] oldStudents;

    capacity *= 2;
}

void University::copy(const University& other)
{
    size     = other.size;
    capacity = other.capacity;
    students = new Student[capacity];

    for (unsigned i = 0; i < size; ++i)
    {
        students[i] = other.students[i];
    }
}

void University::del()
{
    delete[] students;
}
