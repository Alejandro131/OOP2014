
#include "group.cpp"

int main()
{
	char choise;
	
	do
	{
	cout << "Select test:\n"
		 << "s - for tests for student\n"
		 << "g - for tests for group\n >> ";
	cin >> choise;
	}while(choise != 's' && choise != 'g');
	cin.get(); // Clearing the buffer
	
	//Used in both tests
	student students[3];
		
	students[0].set_name("Gosho");
	students[0].set_facNum(53452);
	students[0].set_marks(5);
	
	students[1].set_name("Ivan");
	students[1].set_facNum(53453);
	students[1].set_marks(5.6);
	
	students[2].set_name("Dragan");
	students[2].set_facNum(53454);
	students[2].set_marks(3);
	
	// Chosen test
	if(choise == 's')
	{	 
		
		students[0].print();
		
		students[0].set_marks(5.3);
		students[0].print();
		
		students[0] = students[1];
		students[0].print();
		
		students[1].read();
		students[1].print();
		students[1].set_marks(5.6);
		
		students[2].read();
		students[2].print();
	}
	else
	{
		Group group(students, 3);
		group.print();
		cin.get(); // Pauses
		
		group.studHighestGrades();
		group.studLowestGrades();
		group.studentByFacNum(53453);
		
		cout << "Avarage marks : " << group.averageMarks() << endl;
		group.sortStudByFacNum();
		group.print();
		group.sortStudByMarks();
		group.print();
	}
	
	return 0;
}
