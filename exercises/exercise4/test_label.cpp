#include "label.h"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    //using default constructor to create new object
    Label label1;
    cout << "\nlabel1:\n";
    label1.print();
    //reading content and barcode from standart input
    label1.read();
    cout << "\nlabel1:\n";
    label1.print();

    //using copy constructor to create new object
    Label label2 = label1; //Label label2(label1);
    cout << "\nlabel2:\n";
    label2.print();

    //using default constructor to create new object
    Label label3;
    cout << "\nlabel3:\n";
    label3.print();

    //using operator= to change content and barcode of label3
    label3 = label2;
    cout << "\nlabel3:\n";
    label3.print();

    //using set functions to change content and barcode of label3
    label3.setContent("Some content.");
    label3.setBarcode(4587774);

    cout << "\nlabel3:\n";
    label3.print();

    //using common purpose constructor to create new object
    Label label4("This is content of label4.", 482154);
    cout << "\nlabel4:\n";
    label4.print();

    //using get functions to print content and barcode of label4
    cout << "Content of label4: " << label4.getContent() << endl;
    cout << "Barcode of label4: " << label4.getBarcode() << endl;


    int n;
    cout << "Enter numbers of objects you want to create: ";
    cin >> n;

    //create dynamic array of objects
    Label* labels = new Label[n];
    assert(labels != NULL);
    for(int i = 0; i < n; i++)
    {
        labels[i].read();
    }

    cout << "\nArray of Labels:\n";
    for(int i = 0; i < n; i++)
    {
        labels[i].print();
    }

    //delete dynamic array
    delete [] labels;

    return 0;
}
