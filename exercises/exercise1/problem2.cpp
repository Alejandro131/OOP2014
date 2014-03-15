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

int main()
{
    Point2D a;

    a.read();
    a.print();

    return 0;
}
