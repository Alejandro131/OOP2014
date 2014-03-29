#include <iostream>
#include <cstring>
#include "product.h"

using namespace std;

int main()
{
    Product product1;
    cout << "product1:\n";
    product1.print();
    product1.read();
    cout << "\nproduct1:\n";
    product1.print();

    Product product2 = product1;
    cout << "\nproduct2:\n";
    product2.print();

    Label someLabel("This is content of label of product3", 7845441);
    Date someDate(5, 5, 2005);
    Product product3("PRODUCT 3", 420, 2.22, someDate, someLabel);
    cout << "\nproduct3:\n";
    product3.print();

    Product product4;
    cout << "\nproduct4:\n";
    product4.print();
    product4 = product3;
    cout << "\nproduct4:\n";
    product4.print();

    cout << "\nLabel of product4:\n";
    product4.getLabel().print();

    return 0;
}
