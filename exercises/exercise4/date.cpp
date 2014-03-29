#include "date.h"
#include <iostream>

using namespace std;

Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}
Date::Date(int d, int m, int y)
{
    setDate(d, m, y);
}

Date::Date(const Date& date)
{
    setDate(date.day, date.month, date.year);
}

void Date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::print() const
{
    cout << day << "." << month << "." <<year << endl;
}

void Date::read()
{
    cout << "Enter day: ";
    cin >> day;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter year: ";
    cin >> year;
}
