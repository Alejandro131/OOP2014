#include <iostream>
#include <cstring>
using namespace std;

class Smartphone
{
    private:
        char model[21];
        double price;
        char os[21];
        
    public:
    //---- Constructors ---------
        Smartphone(const char* m = " ", double p = 0.0,const char* o = "symbian");
        Smartphone(const Smartphone &s);
        Smartphone& operator=(const Smartphone &s);

	//---- End of Constructors ----------
	
	//---- Mutators --------
        void setModel(char *m)
        {
            strcpy(model,m);
        }
        void setPrice(double p)
        {
            price = p;
        }

        void setOs (char *o)
        {
            strcpy (os,o);
        }
	//---- End Of Mutators --------
	
	//---- Get functions --------
        const char* getModel() const
        {
            return model;
        }
        double getPrice () const
        {
            return price;
        }

        const char* getOs () const
        {
            return os;
        }
	//---- End of Get functions
	
        void print () const;
};

Smartphone :: Smartphone (const char *m, double p,const char *o)
{
    strcpy (model,m);
    price = p;
    strcpy (os, o);
}

Smartphone :: Smartphone (const Smartphone &s)
{
    strcpy (model,s.model);
    price = s.price;
    strcpy (os, s.os);
}

Smartphone &Smartphone:: operator= (const Smartphone &s)
{
    if (this != &s)
    {
        strcpy (model,s.model);
        price = s.price;
        strcpy (os, s.os);
    }
    return *this;
}

void Smartphone:: print () const
{
     cout << "Model: " << model << endl
          << "Price: " << price << endl
          << "OS: " << os << endl << endl;
}


void sortByPrice (Smartphone *s, int n)
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
            Smartphone temp;
            temp = s[i];
            s[i] = s[index];
            s[index] = temp;
        }
    }
}
int main ()
{
    Smartphone n("Nokia",650,"windows"), s("Samsung", 500, "Android"), i("iPhone",700,"iOS");
    Smartphone t[3] = {n,s,i};

    sortByPrice(t,3);

    cout << "After sort" << endl;



    for (int k = 0; k < 3; k++)
        t[k].print();
    return 0;
}
