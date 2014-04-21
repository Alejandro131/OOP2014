#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student
{
public:
    Student();
    Student(const char*, double, unsigned);
    Student(const Student&);
    ~Student();

    Student& operator=(const Student&);

    const char* getName() const;
    double getAverageGrades() const;
    unsigned getFacultyNumber() const;

    void setName(const char*);
    void setAverageGrades(double);
    void setFacultyNumber(unsigned);

    void print() const;

private:
    char* name;
    double averageGrades;
    unsigned facultyNumber;

    void copy(const Student&);
    void del();
};

#endif
