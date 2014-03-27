#include "product.h"

#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

Product::Product() : expirationDate(), label()
{
    name = new char[1];
    assert(name != NULL);
    name[0] = '\0';

    weight = 0;
    price = 0;
}

Product::Product(const char* n, double w, double pr, const Date& d, const Label& l) : expirationDate(d), label(l)
{
    if(n != NULL && strcmp(n, "") > 0)
    {
        name = new char[strlen(n) + 1];
        assert(name != NULL);
        strcpy(name, n);
    }
    else
    {
        name = new char[1];
        assert(name != NULL);
        name[0] = '\0';
    }

    weight = w > 0 ? w : 0;
    price = pr > 0 ? pr : 0;
}

Product::Product(const Product& other) : expirationDate(other.expirationDate), label(other.label)
{
    name = new char[strlen(other.name) + 1];
    assert(name != NULL);
    strcpy(name, other.name);

    weight = other.weight;
    price = other.price;
}

Product& Product::operator=(const Product& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}

Product::~Product()
{
    del();
}

void Product::del()
{
    if(name != NULL)
    {
        delete [] name;
    }
}

void Product::copy(const Product& other)
{
    name = new char[strlen(other.name) + 1];
    assert(name != NULL);
    strcpy(name, other.name);

    weight = other.weight;
    price = other.price;

    expirationDate = other.expirationDate;
    label = other.label;
}

void Product::setName(const char* other)
{
    if(other != NULL && strcmp(other, "") > 0)
    {
        del();
        name = new char[strlen(other) + 1];
        assert(name != NULL);
        strcpy(name, other);
    }
    else
    {
        del();
        name = new char[1];
        assert(name != NULL);
        strcpy(name, other);
    }
}

void Product::setDate(const Date& other)
{
    expirationDate = other;
}

void Product::setLabel(const Label& other)
{
    label = other;
}

void Product::setWeight(double other)
{
    weight = other > 0 ? other : 0;
}

void Product::setPrice(double other)
{
    price = other > 0 ? other : 0;
}

char* Product::getName() const
{
    return name;
}

double Product::getWeight() const
{
    return weight;
}

double Product::getPrice() const
{
    return price;
}

Label Product::getLabel() const
{
    //make copy of label and then return that copy
    return label;
}

Date Product::getExpirationDate() const
{
    //make copy of expirationDate and return that copy
    return expirationDate;
}

void Product::read()
{
    char buffer[200];
    cout << "Enter name of product: ";
    cin.getline(buffer, 200);
    setName(buffer);

    double buf;
    cout << "Enter weight of product: ";
    cin >> buf;
    setWeight(buf);

    cout << "Enter price of product: ";
    cin >> buf;
    setPrice(buf);

    cout << "Enter expiration date:\n";
    expirationDate.read();

    cout << "Enter label information:\n";
    label.read();
}

void Product::print() const
{
    cout << "\n-------------Product--------------\n";
    cout << "Name: " << name << endl;
    cout << "Weight: " << weight << endl;
    cout << "Price: " << price << endl;
    cout << "Expiration date: "; expirationDate.print();
    label.print();
    cout << "----------------------------------\n";
}
