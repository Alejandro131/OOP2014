#include <iostream>
#include <cstring>
using namespace std;


struct robber
{
    char name[51];
    double rate;
    bool inPrison;

    robber(const char* _name = " ", double _rate = 0.0, bool _inPrison = false)
    {
        strcpy (name, _name);
        rate = _rate;
        inPrison = _inPrison;
    }

    void print () const
    {
        cout << "Name: " << name << endl
             << "Rate: " << rate << endl
             << "inPrison: " << boolalpha << inPrison << endl << endl;
    }
};


class BankRobbers
{
    private:
        robber group[10];
        int size;
        double maxLoot;

		// A hidden method used for calculating the maxLoot property
        double getMaxLoot ()
        {
            double loot = 0;
            for (int i = 0; i < size; i ++)
                if (group[i].inPrison == false)
                    loot += group[i].rate * 0.8;
            return loot;
        }

    public:

        BankRobbers ();
        BankRobbers (const BankRobbers &b);
        BankRobbers &operator= (const BankRobbers &b);

	//---- Mutators -------
		void addRobber (const robber &r);	// Adds the given robber to the group if the group isn't full
        void addRobber();					// Adds a newly created roobber to the group if not full


        void setName (char* na, int index) { strcpy(group[index].name,na);  }
        void setRate (double r, int index) { group[index].rate = r; }
        void setInPrison (bool p, int index) { group[index].inPrison = p; }
	//---- End Of Mutators -------


        const char *getName (int index) { return group[index].name; }
        double getRate (int index) const { return group[index].rate; }
        bool getInPrison (int index) const { return group[index].inPrison; }

        void print () const;

};

// --- Constructors ----
BankRobbers::BankRobbers() : size(0), maxLoot(0) {}	// Nekvi shashmi tuka (vijte si uchebnika)

BankRobbers::BankRobbers (const BankRobbers &b) : size(b.size), maxLoot(b.maxLoot)
{
    for(int i = 0; i < size; i++)
    {
		group[i] = b.group[i];
	}
}

BankRobbers& BankRobbers::operator=(const BankRobbers &b)
{
    if (this != &b)
    {
		size = b.size;

		for(int i = 0; i < size; i++)
			group[i] = b.group[i];

		maxLoot = b.maxLoot;
    }
    return *this;
}
// --- End Of Constructors ---


void BankRobbers::addRobber(const robber &r)
{
    if (size < 10)
    {
		group[size] = r;
		size ++;
    }
    else
		cout << "The group is full!" << endl;

    maxLoot = getMaxLoot();
}

void BankRobbers::addRobber()
{
    if (size < 10)
    {
		cout << "Name: ";
		cin.getline(group[size].name,50);

		cout << "Rate: ";
		cin >> group[size].rate;

		char c;
		cout << "Is the " << group[size].name << " in prison : (y/n) ";
		while (c != 'y' && c != 'n')
		{
			cin >>c;
			if (c == 'n')
			group[size].inPrison = false;
			else
			if (c == 'y')
				group[size].inPrison = true;
			else
			cout << "Wrong command!" << endl;
		}
		size ++;
		cin.get();
	}
    else
		cout << "You cant add robber" << endl;

    maxLoot = getMaxLoot();
}

void BankRobbers::print () const
{
    cout << "Max loot: " << maxLoot << endl;

    for (int i =0 ; i < size ; i ++)
    {
		group[i].print();	// Using the print method implemented in the struct
	}
}



int main ()
{
    robber p("Peio",10,false);
    BankRobbers g;
    g.addRobber(p);
    //g.addRobber();

    g.print();
    //cout << endl << endl;

    //BankRobbers g2(g);
    //g2.addRobber();
    //g2.print();


    return 0;
}
