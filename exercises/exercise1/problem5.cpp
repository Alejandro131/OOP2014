#include <iostream>

using namespace std;

struct Car
{
    char model[30];
    char registry[10];
    int year;

    void read()
    {
        cout << "Enter car model: ";
        cin >> model;
        cout << "Enter car registry: ";
        cin >> registry;
        cout << "Enter car production year: ";
        cin >> year;
    }

    void print()
    {
        cout << "Model: " << model << endl;
        cout << "Registry: " << registry << endl;
        cout << "Year: " << year << endl;
    }
};

class Garage
{
    public:
        void read();
        void sort();
        void print();
    private:
        Car cars[20];
        int size;
};

void Garage::read()
{
    cout << "How many cars would you like in the garage: ";
    do
    {
        cin >> size;
    }
    while (size < 0 || size > 20);

    for (int i = 0; i < size; i++)
        cars[i].read();
}

void Garage::sort()
{
    Car temp;
    for(int i = 0; i <= size - 1; i++)
        for(int j = 0; j <= size - 1; j++)
            if(cars[j].year > cars[j+1].year)
            {
                temp = cars[j];
                cars[j] = cars[j+1];
                cars[j+1] = temp;
            }
}

void Garage::print()
{
    for (int i = 0; i < size; i++)
        cars[i].print();
}

int main()
{
    Garage g;

    g.read();
    g.sort();
    g.print();

    return 0;
}
