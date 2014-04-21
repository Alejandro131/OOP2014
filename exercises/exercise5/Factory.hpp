#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Product.hpp"

class Factory
{
public:
    Factory();
    Factory(const Factory&);
    ~Factory();

    Factory& operator=(const Factory&);

    Product getProduct(int) const;
    unsigned getNumberOfProducts() const;

    void addProduct(const Product&);
    void removeProduct(int);
    void sort();

    void print() const;

private:
    Product* products;
    unsigned size;
    unsigned capacity;

    static int lastBarcode;

    void extend();

    void copy(const Factory&);
    void del();
};

#endif
