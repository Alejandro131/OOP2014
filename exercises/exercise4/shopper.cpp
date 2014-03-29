#include "shopper.h"
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

Shopper::Shopper(double c)
{
    cash = c;
    list = NULL;
    current = 0;
    capacity = 1;
}

Shopper::Shopper(const Shopper& other)
{
    copy(other);
}

Shopper& Shopper::operator=(const Shopper& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}
Shopper::~Shopper()
{
    del();
}

void Shopper::del()
{
    if(list != NULL)
    {
        delete [] list;
    }
}

void Shopper::copy(const Shopper& other)
{
    if(list != NULL)
    {
        capacity = other.capacity;
        list = new Product[capacity];
        assert(list != NULL);
        current = other.current;
        for(int i = 0; i < current; i++)
        {
            list[i] = other.list[i];
        }
        cash = other.cash;
    }
    else
    {
        capacity = 1;
        current = 0;
        cash = other.cash;
        list = NULL;
    }

}

void Shopper::resizeList()
{
    capacity *= 2;
    Product* buffer = new Product[current];
    assert(buffer != NULL);
    for(int i = 0; i < current; i++)
    {
        buffer[i] = list[i];
    }

    delete [] list;

    list = new Product[capacity];
    assert(list != NULL);

    for(int i = 0; i < current; i++)
    {
        list[i] = buffer[i];
    }

    delete [] buffer;
}

void Shopper::addProduct(const Product& newProduct)
{
    if(list == NULL)
    {
        list = new Product[capacity];
        assert(list != NULL);
    }

    if(current == capacity)
    {
        resizeList();
    }
    list[current] = newProduct;
    current++;

    cout << "Added product with name: " << newProduct.getName() << endl;
}

int Shopper::indexOfProduct(const char* name) const
{
    for(int i = 0; i < current; i++)
    {
        if(strcmp(list[i].getName(), name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void Shopper::removeProduct(const char* name)
{
    int index = indexOfProduct(name);
    if(index >= 0)
    {
        Product* temp = new Product[current];
        int k = 0;
        for(int i = 0; i < current; i++)
        {
            if(i != index)
            {
                temp[k] = list[i];
                k++;
            }
        }

        delete [] list;
        current--;

        list = new Product[capacity];
        assert(list != NULL);
        for(int i = 0; i < current; i++)
        {
            list[i] = temp[i];
        }

        delete [] temp;
    }
    else
    {
        cout << "No product with name " << name << endl;
    }
}

double Shopper::getCash() const
{
    return cash;
}

double Shopper::totalPrice() const
{
    double total = 0.0;
    for(int i = 0; i < current; i++)
    {
        total += list[i].getPrice();
    }
    return total;
}

double Shopper::totalWeight() const
{
    double total = 0.0;
    for(int i = 0; i < current; i++)
    {
        total += list[i].getWeight();
    }
    return total;
}

bool Shopper::hasEnoughCash() const
{
    return totalPrice() <= cash;
}

void Shopper::buyProducts()
{
   if(hasEnoughCash())
   {
       cash -= totalPrice();
       cout << "Successful payment.\n";
   }
   else
   {
       cout << "You don't have enough money!\n";
   }
}

char* Shopper::nameOfHeaviestProduct() const
{
    int max = list[0].getWeight();
    int maxIndex = 0;
    for(int i = 1; i < current; i++)
    {
        if(max < list[i].getWeight())
        {
            max = list[i].getWeight();
            maxIndex = i;
        }
    }

    return list[maxIndex].getName();
}

char* Shopper::nameOfMostExpensiveProduct() const
{
    int max = list[0].getPrice();
    int maxIndex = 0;
    for(int i = 1; i < current; i++)
    {
        if(max < list[i].getPrice())
        {
            max = list[i].getPrice();
            maxIndex = i;
        }
    }

    return list[maxIndex].getName();
}

void Shopper::print() const
{
    if(current > 0)
    {
        cout << "Cash: " << cash << endl;
        cout << "List of products:\n";
        for(int i = 0; i < current; i++)
        {
            list[i].print();
        }
    }
    else
    {
        cout << "There is no product in list.\n";
    }
}
