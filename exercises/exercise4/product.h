#ifndef PRODUCT_H
#define PRODUCT_H

#include "date.h"
#include "label.h"

class Product
{
public:
    Product();
    Product(const char*, double, double, const Date&, const Label&);
    Product(const Product&);
    Product& operator=(const Product&);
    ~Product();

    void setName(const char*);
    void setWeight(double);
    void setPrice(double);
    void setLabel(const Label&);
    void setDate(const Date&);

    char* getName() const;
    double getWeight() const;
    double getPrice() const;
    Date getExpirationDate() const;
    Label getLabel() const;

    void read();
    void print() const;
private:
    char* name;
    double weight;
    double price;
    Date expirationDate;
    Label label;

    void del();
    void copy(const Product&);
};

#endif
