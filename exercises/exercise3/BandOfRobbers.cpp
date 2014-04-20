#include <iostream>
#include <cstring>

using namespace std;

struct Robber
{
    char name[51];
    double rate;
    bool inPrison;

    Robber(const char* _name="", double _rate=0.0, bool _inPrison=false):
        rate(_rate), inPrison(_inPrison)
    {
        strcpy (name, _name);
    }

    void print () const
    {
        cout << "Name: "     << name << endl
             << "Rate: "     << rate << endl
             << "inPrison: " << boolalpha << inPrison << endl;
    }
};

class BankRobbers
{
public:
    BankRobbers():
        size(0), maxLoot(0)
    { }

    void addRobber();

    void addRobber(const Robber& robber)
    {
        if (size < 10)
        {
            group[size] = robber;
            size++;
        }

        maxLoot = getMaxLoot();
    }

    void setName(char* name, int index)
    {
        strcpy(group[index].name, name);
    }

    void setRate(double rate, int index)
    {
        group[index].rate = rate;
    }

    void setInPrison(bool inPrison, int index)
    {
        group[index].inPrison = inPrison;
    }

    const char* getName(int index)
    {
        return group[index].name;
    }

    double getRate(int index) const
    {
        return group[index].rate;
    }

    bool getInPrison(int index) const
    {
        return group[index].inPrison;
    }

    void print () const
    {
        cout << "Max loot: " << maxLoot << endl;

        for (int i =0 ; i < size ; i ++)
        {
            group[i].print();
        }
    }

private:
    int size;
    double maxLoot;
    Robber group[10];

    double getMaxLoot ()
    {
        double loot = 0;
        for (int i = 0; i < size; i ++)
            if (group[i].inPrison == false)
                loot += group[i].rate * 0.8;
        return loot;
    }
};

void BankRobbers::addRobber()
{
    if (size < 10)
    {
        cout << "Name: ";
        cin.getline(group[size].name, 50);

        cout << "Rate: ";
        cin >> group[size].rate;

        char c;
        cout << "Is the " << group[size].name << " in prison : (y/n) ";

        while (c != 'y' && c != 'n')
        {
            cin >>c;
            if (c == 'n')
                group[size].inPrison = false;
            else if (c == 'y')
                group[size].inPrison = true;
            else
                cout << "Wrong command!" << endl;
        }

        size ++;
        cin.get();
    }

    maxLoot = getMaxLoot();
}

int main ()
{
    Robber p("Peio", 10, false);
    BankRobbers g;
    g.addRobber(p);

    g.print();

    return 0;
}
