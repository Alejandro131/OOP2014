#include<iostream>
#include<cstring>
using namespace std;

struct student
{
	unsigned facNum;
	char name[41];
	double marks;

	student& operator=(const student& other) 
		// A bit cheeting
	{
		if(this != &other)
		{
			facNum = other.facNum;
			marks = other.marks;
			strcpy(name, other.name);
		}
		return *this;
	}
	
	void set_name(const char* _name){  strcpy(name, _name);  }
	void set_marks(double _marks)
	{
		if(_marks < 2 || _marks > 6)
		{
			cout << "Marks given incorrect. Setting default value - 2.\n";
			marks = 2;
		}
		else
		{
			marks = _marks;  
		}
	}
	void set_facNum(unsigned _facNum){  facNum = _facNum;  }

	void read()
		// Reads the information for the student from the prompt
	{
		cout << "Enter the name of the student : ";
		cin.getline(name, 41);
		
		do
		{
			cout << "Enter the facult number of the student : ";
			cin >> facNum;
		}while(facNum < 0);

		do
		{
			cout << "Enter the average marks of the student : ";
			cin >> marks;
		}while(marks < 2 || marks > 6);
		
		cin.get(); //Cleans the buffer from the cin function
	}
	
	void print() const
		// Prints the information for the student
	{
		cout << "Name : " << name << endl
			 << "Facult number : " << facNum << endl
			 << "Marks : " << marks << "\n\n";
	}
};
