#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Student.hpp"

class University
{
public:
    University();
    University(const University&);
    ~University();

    University& operator=(const University&);

    Student getStudent(unsigned) const;
    unsigned getNumberOfStudents() const;

    void addStudent(const Student&);
    void removeStudent(unsigned);
    void sort();

    void print() const;

private:
    Student* students;
    unsigned size;
    unsigned capacity;

    static unsigned lastFacultyNumber;

    void extend();

    void copy(const University&);
    void del();
};

#endif
