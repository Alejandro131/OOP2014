#ifndef SHOPPER_H
#define SHOPPER_H

#include "product.h"

using namespace std;

class Shopper
{
public:
    Shopper(double = 20);
    Shopper(const Shopper&);
    Shopper& operator=(const Shopper&);
    ~Shopper();

    void addProduct(const Product&);
    void removeProduct(const char*);
    void buyProducts();

    double getCash() const;
    double totalWeight() const;
    double totalPrice() const;
    bool hasEnoughCash() const;
    void print() const;
    char* nameOfHeaviestProduct() const;
    char* nameOfMostExpensiveProduct() const;

private:
    Product* list;
    int current;
    int capacity;
    double cash;

    void resizeList();
    void del();
    void copy(const Shopper&);
    int indexOfProduct(const char*) const;
};

#endif
