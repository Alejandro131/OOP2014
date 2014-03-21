#include "label.h"
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

Label::Label()
{
    content = new char[1];
    assert(content != NULL);
    content[0] = '\0';

    barcode = 0;
}

Label::Label(const char* c, int b)
{
    if(c != NULL && strcmp(c, "") > 0)
    {
        content = new char[strlen(c) + 1];
        assert(content != NULL);
        strcpy(content, c);
    }
    else
    {
        content = new char[1];
        assert(content != NULL);
        content[0] = '\0';
    }

    barcode = b > 0 ? b : 0;
}

Label::Label(const Label& other)
{
   copy(other);
}

Label& Label::operator=(const Label& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}

Label::~Label()
{
    del();
}

void Label::setContent(const char* c)
{
    if(c != NULL && strcmp(c, "") > 0)
    {
        del();
        content = new char[strlen(c) + 1];
        assert(content != NULL);
        strcpy(content, c);
    }
    else
    {
        del();
        content = new char[1];
        assert(content != NULL);
        content[0] = '\0';
    }
}

void Label::setBarcode(int b)
{
    barcode = b > 0 ? b : 0;
}

char* Label::getContent() const
{
    return content;
}

int Label::getBarcode() const
{
    return barcode;
}

void Label::print() const
{
    cout << "\n-------------Label--------------\n";
    cout << "Content: " << content << endl;
    cout << "Barcode: " << barcode << endl;
    cout << "--------------------------------\n";
}

void Label::read()
{
    int bCode;
    cout << "Enter barcode of label: ";
    cin >> bCode;
    setBarcode(bCode);

    cin.get();

    char buffer[100];
    cout << "Enter content of label: ";
    cin.getline(buffer, 100);
    setContent(buffer);
}

void Label::del()
{
    if(content != NULL)
    {
        delete [] content;
    }
}

void Label::copy(const Label& other)
{
    content = new char[strlen(other.content) + 1];
    assert(content != NULL);
    strcpy(content, other.content);

    barcode = other.barcode;
}