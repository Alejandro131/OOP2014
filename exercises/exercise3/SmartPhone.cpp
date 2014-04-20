#include <iostream>
#include <cstring>

using namespace std;

class Smartphone
{
public:
    Smartphone(const char* _model="",
               double _price=0.0,
               const char* _os="symbian"):
        price(_price)
    {
        strcpy(model, _model);
        strcpy(os, _os);
    }

    void setModel(char* _model)
    {
        strcpy(model, _model);
    }
    void setPrice(double _price)
    {
        price = _price;
    }

    void setOs(char* _os)
    {
        strcpy(os, _os);
    }

    const char* getModel() const
    {
        return model;
    }
    double getPrice() const
    {
        return price;
    }

    const char* getOs() const
    {
        return os;
    }

    void print() const
    {
         cout << "Model: " << model << endl
              << "Price: " << price << endl
              << "OS: "    << os    << endl;
    }

private:
    double price;
    char model[21];
    char os[21];
};

void sortByPrice (Smartphone* s, int n)
{
    for (int i = 0; i < n - 1; i ++)
    {
        int min = s[i].getPrice();
        int index = i;

        for (int j = i + 1; j < n; j++)
            if (s[j].getPrice() < min)
            {
                index = j;
                min = s[j].getPrice();
            }

        if (index != i)
        {
            Smartphone temp = s[i];
            s[i] = s[index];
            s[index] = temp;
        }
    }
}
int main ()
{
    Smartphone n("Nokia",650,"windows");
    Smartphone s("Samsung", 500, "Android");
    Smartphone i("iPhone",700,"iOS");

    Smartphone t[3] = {n,s,i};

    sortByPrice(t,3);

    cout << "After sort" << endl;



    for (int k = 0; k < 3; k++)
        t[k].print();

    return 0;
}
