#include<iostream>
#include<cstring>
#include "student.cpp"
using namespace std;

class Group
{
public:
	Group(const student* students, short groupSize)
	{
		for(int i = 0 ; i<groupSize ; i++)
		{
			this->students[i] = students[i];
		}
		this->groupSize = groupSize;
	}


	void sortStudents(); // Sorts the students by the choosen field
	void sortStudByFacNum(); // function for sorting
	void sortStudByMarks();	 // function for sorting
	
  //--- Get Functions ---
	void studHighestGrades() const;
	void studLowestGrades() const;
	void studentByFacNum(unsigned _facNum) const;
	void print() const;
	double averageMarks() const;
	
	short getGroupSize() const { return groupSize; }
	const student* getStudents() const { return students; }
  //--- End Get Functions ---
	
private:
	student students[30];
	short groupSize;
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
	choise == 'f' ? sortStudByFacNum():sortStudByMarks();
}

void Group::sortStudByFacNum()
{
	int j;
	student tempStudent;
	for(int i = 1 ; i < groupSize ; i++)
	{	
		tempStudent = students[i];
		for(j = i ; j>0 && tempStudent.facNum>students[j-1].facNum ; j--)
			students[j] = students[j-1];
		students[j] = tempStudent;
	}
}
  
void Group::sortStudByMarks()
{
	int j;
	student tempStudent;
	for(int i = 1 ; i < groupSize ; i++)
	{	
		tempStudent = students[i];
		for(j = i ; j>0 && tempStudent.marks>students[j-1].marks ; j--)
			students[j] = students[j-1];
		students[j] = tempStudent;
	}
}

