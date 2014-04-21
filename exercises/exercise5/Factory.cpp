#include <iostream>
#include <algorithm>

#include "Factory.hpp"

using namespace std;

int Factory::lastBarcode = 0;

Factory::Factory():
    size(0), capacity(1)
{
    products = new Product[capacity];
}

Factory::Factory(const Factory& other)
{
    copy(other);
}

Factory::~Factory()
{
    del();
}

Factory& Factory::operator=(const Factory& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

Product Factory::getProduct(int barcode) const
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (products[i].getBarcode() == barcode)
        {
            return products[i];
        }
    }
}

unsigned Factory::getNumberOfProducts() const
{
    return size;
}

void Factory::addProduct(const Product& product)
{
    if (size == capacity)
    {
        extend();
    }

    products[size++] = product;
    products[size - 1].setBarcode(lastBarcode++);
}

void Factory::removeProduct(int barcode)
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (products[i].getBarcode() == barcode)
        {
            for (unsigned j = i + 1; j < size; ++j)
            {
                products[j - 1] = products[j];
            }

            --size;

            return;
        }
    }
}

void Factory::sort()
{
    for (unsigned i = 0; i < size - 1; ++i)
    {
        unsigned min = i;

        for (unsigned j = i + 1; j < size; ++j)
        {
            if (products[j] < products[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(products[min], products[i]);
        }
    }
}

void Factory::print() const
{
    for (unsigned i = 0; i < size; ++i)
    {
        products[i].print();
        cout << endl;
    }
}

void Factory::extend()
{
    Product* oldProducts = products;
    products = new Product[2 * capacity];

    for (unsigned i = 0; i < size; ++i)
    {
        products[i] = oldProducts[i];
    }

    delete[] oldProducts;

    capacity *= 2;
}

void Factory::copy(const Factory& other)
{
    size     = other.size;
    capacity = other.capacity;
    products = new Product[capacity];

    for (unsigned i = 0; i < size; ++i)
    {
        products[i] = other.products[i];
    }
}

void Factory::del()
{
    delete[] products;
}
