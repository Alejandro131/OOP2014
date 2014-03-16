/*
Да се дефинира клас group, който да има масив от студенти (с максимална дължина 30) 
за член данна и реализира операции за:

Намиране на среден успех на групата
Извеждане на студент с максимален/минимален успех
Извеждане на студент по зададен факултетен номер
Сортиране на студентите по факултетни номера
Сортиране на студентите по успех
Извеждане на всички студенти
*/

#include<iostream>
#include<cstring>
#include "student.cpp"
using namespace std;

class Group
{
public:

	void sortStudents(); // Sorts the students by the choosen field
	
  //--- Get Functions ---
	void studHighestGrades() const;
	void studLowestGrades() const;
	void studentByFacNum(unsigned _facNum) const;
	void print() const;
	double averageMarks() const;
  //--- End Get Functions ---
	
private:
	student students[30];
	short groupSize;
	
	void sortStudByField(bool sortChoise); // Hidden function for sorting
};

double Group::averageMarks() const
{
	int result = 0;
	for(int i = 0; i < groupSize ; i++)
	{
		result += students[i].marks;
	}
	
	return result/groupSize;
}

void Group::print() const
{
	cout << "\t--- The group consists of : ---\n\n";
	for(int i = 0 ; i < groupSize ; i++)
	{
		students[i].print();
	}
	cout << endl;
}

void Group::studentByFacNum(unsigned _facNum) const
{
	for(int i = 0 ; i<groupSize ; i++)
	{
		if(students[i].facNum == _facNum)
		{
			students[i].print();
			return; // quits the function
		}
	}
	cout << "Error.Student not found.\n"; // printed if facult number isn't found
}

void Group::studLowestGrades() const
{
	student worstStudent(students[0]);
	for(int i = 0 ; i<groupSize	 ; i++)
	{
		if(worstStudent.marks > students[i].marks)
			worstStudent = students[i];		// NOT SURE IF WORKS
	}
	worstStudent.print();
}

void Group::studHighestGrades() const
{
	student bestStudent(students[0]);
	for(int i = 0 ; i<groupSize	 ; i++)
	{
		if(bestStudent.marks > students[i].marks)
			bestStudent = students[i];		// NOT SURE IF WORKS
	}
	bestStudent.print();
}

void Group::sortStudents()
{
	char choise;
	do
	{
		cout << "Choose sorting field\n"
			 << "1) f - sort by facult number\n"
			 << "2) m - sort by marks";
		cin >> choise;
	}while(choise != 'f' && choise != 'm');
	choise == 'f' ? sortStudByField(1):sortStudByField(0);
}

void Group::sortStudByField(bool choise)
{
	if(choise)
	{
		for(int i = 1 ; i < groupSize ; i++)
			for(int j = i ; i>0 && students[j].facNum>students[j-1].facNum ; j--)
				swap(students[j], students[j-1]);
	}
	else
	{
		for(int i = 1 ; i < groupSize ; i++)
			for(int j = i ; i>0 && students[j].facNum>students[j-1].facNum ; j--)
				swap(students[j], students[j-1]);
	}
}
