#ifndef PRODUCT_HPP
#define PRODUCT_HPP

class Product
{
public:
    Product();
    Product(const char*, double, double, int);
    Product(const Product&);
    ~Product();

    Product& operator=(const Product&);

    const char* getName() const;
    double getWeight() const;
    double getPrice() const;
    int getBarcode() const;

    void setName(const char*);
    void setWeight(double);
    void setPrice(double);
    void setBarcode(int);

    void print() const;

    bool operator<(const Product&) const;

private:
    char* name;
    double weight;
    double price;
    int barcode;

    void copy(const Product&);
    void del();
};

#endif
