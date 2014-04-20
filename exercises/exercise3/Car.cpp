#include <iostream>
#include <cstring>

using namespace std;

class Car
{
public:
    Car():
        year(0), price(0.0)
    {
        strcpy(model," ");
    }

    Car(int _year, const char* _model, double _price):
        year(_year), price(_price)
    {
        strcpy(model, _model);
    }

    void setModel(const char* _model)
    {
        strcpy(model, _model);
    }

    void setYear(int _year)
    {
        year = _year;
    }

    void setPrice(double _price)
    {
        price = _price;
    }

    const char* getModel() const
    {
        return model;
    }

    int getYear() const
    {
        return year;
    }

    double getPrice() const
    {
        return price;
    }

    void print() const
    {
        cout << "Model: " << model << endl
             << "Year: "  << year  << endl
             << "Price: " << price << endl;
    }

private:
    int year;
    char model[51];
    double price;
};

Car mostExpensiveCar (Car* cars, int n)
{
    Car maxPriceCar = cars[0];

    for (int i = 1; i < n; i++)
    {
        if (cars[i].getPrice() > maxPriceCar.getPrice())
        {
            maxPriceCar = cars[i];
        }
    }

    return maxPriceCar;
}

int main ()
{
    Car d(1960,"Trabant",200);
    Car a(1961,"Shkoda", 300);
    Car b(2012,"Trabant 3000", 500);

    Car c[3] = {d, a, b};

    cout << "Most expensive car:\n";
    mostExpensiveCar(c,3).print();
    cout << endl << endl;

    d.print();
    d.setModel("tr");
    d.print();

    return 0;
}
