#include <iostream>
#include <cstring>

#include "Product.hpp"

using namespace std;

Product::Product():
    weight(0), price(0), barcode(0)
{
    name = new char[1];
    name[0] = '\0';
}

Product::Product(const char* _name,
                 double _weight,
                 double _price,
                 int _barcode):
    weight(_weight), price(_price), barcode(_barcode)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

Product::Product(const Product& other)
{
    copy(other);
}

Product::~Product()
{
    del();
}

Product& Product::operator=(const Product& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

const char* Product::getName() const
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

int Product::getBarcode() const
{
    return barcode;
}

void Product::setName(const char* _name)
{
    delete[] name;

    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

void Product::setWeight(double _weight)
{
    weight = _weight;
}

void Product::setPrice(double _price)
{
    price = _price;
}

void Product::setBarcode(int _barcode)
{
    barcode = _barcode;
}

void Product::print() const
{
    cout << "Name: "    << name    << endl
         << "Weight: "  << weight  << endl
         << "Price: "   << price   << endl
         << "Barcode: " << barcode << endl;
}

bool Product::operator<(const Product& other) const
{
    return price < other.price;
}

void Product::copy(const Product& other)
{
    weight  = other.weight;
    price   = other.price;
    barcode = other.barcode;

    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void Product::del()
{
    delete[] name;
}
