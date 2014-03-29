#include <iostream>
#include <cstring>
#include <cassert>

#include "shopper.h"

using namespace std;

int main()
{
    Shopper shopper(100);
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    cin.get();

    for(int i = 0; i < n; i++)
    {
        Product p;
        p.read();
        shopper.addProduct(p);
        cout << endl;
    }

    double maxWeight;
    cout << "Enter max weight: ";
    cin >> maxWeight;

    while(shopper.totalWeight() > maxWeight)
    {
        char* nameOfHeaviestProduct = shopper.nameOfHeaviestProduct();
        shopper.removeProduct(nameOfHeaviestProduct);
    }

    shopper.print();
    shopper.buyProducts();

    cout << "Now your cash is " << shopper.getCash() << "\n";

    return 0;
}
