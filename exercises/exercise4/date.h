#ifndef DATE_H
#define DATE_H

class Date
{
public:
    Date();
    Date(int, int, int);
    Date(const Date&);

    void setDate(int, int, int);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void print() const;
    void read();
private:
    int day;
    int month;
    int year;
};

#endif
