#include <iostream>
#include <math.h>

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

double perimeter(Triangle t)
{
    double a, b, c;

    a = sqrt((t.a.x - t.b.x) * (t.a.x - t.b.x) + (t.a.y - t.b.y) * (t.a.y - t.b.y));
    b = sqrt((t.c.x - t.b.x) * (t.c.x - t.b.x) + (t.c.y - t.b.y) * (t.c.y - t.b.y));
    c = sqrt((t.a.x - t.c.x) * (t.a.x - t.c.x) + (t.a.y - t.c.y) * (t.a.y - t.c.y));

    return a + b + c;
}

bool equalPerimeters(Triangle t1, Triangle t2)
{
    return fabs(perimeter(t1) - perimeter(t2)) < 0.000001;
}

int main()
{
    Triangle t1, t2;

    t1.read();
    t2.read();

    cout << boolalpha << equalPerimeters(t1, t2) << endl;

    return 0;
}
