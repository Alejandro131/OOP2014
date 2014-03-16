#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double x1, x2, x3, y1, y2, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    double a, b, c;
    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    cout << boolalpha << ((a + b > c) && (b + c > a) && (a + c > b)) << endl;

    return 0;
}
