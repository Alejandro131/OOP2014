#include <iostream>

using namespace std;

struct Point2D
{
    double x, y;

    void read()
    {
        cin >> x >> y;
    }

    void print()
    {
        cout << "(" << x << ", " << y << ")\n";
    }
};

struct Triangle
{
    Point2D a, b, c;

    void read()
    {
        a.read();
        b.read();
        c.read();
    }

    void print()
    {
        a.print();
        b.print();
        c.print();
    }
};

int main()
{
    Triangle t;

    t.read();
    t.print();

    return 0;
}
