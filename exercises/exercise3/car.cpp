#include<iostream>
#include<cstring>
using namespace std;

class Car
{
    private:
        int year;
        char model[51];
        double price;
        
    public:
    
    //---- Constructros -----
        Car()
        {
            year = 0;
            strcpy(model," ");
            price = 0.0;
        }
        Car (int y, const char *m, double p)
        {
            year = y;
            strcpy(model, m);
            price = p;
        }
        Car(const Car &c)
        {
            year = c.year;
            strcpy(model, c.model);
            price = c.price;
        }
	//---- End Of Constructors ------
	
	//---- Mutators -------
        void setModel (const char *m)
        {
            strcpy(model, m);
        }
        void setYear (int y)
        {
            year = y;
        }
        void setPrice (double p)
        {
            price = p;
        }
	//---- End Of Mutators ------
	
	//---- Get methods ----
        const char* getModel () const
        {
            return model;
        }
        int getYear () const
        {
            return year;
        }
        double getPrice() const
        {
            return price;
        }
	//---- End Of Get methods
	
        void print () const;

};//END OF class Car

void Car:: print () const
{
    cout << "Model: " << model << endl
         << "Year: " << year << endl
         << "Price: " << price << endl << endl;
}


double mostExpensiveCar (Car *c,int n)
	// Outer function for finding the price of the most expensive car
{
    double maxPrice = c[0].getPrice();
    for (int i = 1; i < n; i++)
        if (c[i].getPrice() > maxPrice)
            maxPrice = c[i].getPrice();

    return maxPrice;
}



int main ()
{
    //Car c;
    //c.print();
    Car d(1960,"Trabant",200);
    Car a(1961,"Shkoda", 300);
    Car b(2012,"Trabant 3000", 500);

    //d.print();

    Car c[3] = {d,a,b};
    cout <<"Most expensive car ,costs : " << mostExpensiveCar(c,3) << endl << endl;

    d.print();
    d.setModel("tr");
    d.print();
    return 0;
}
