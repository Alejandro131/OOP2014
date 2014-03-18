###Тест 4

####Отбележете и обяснете грешките в програмата. Поправете ги, така че да се получи работеща програма. Намерете резултата от изпълнението й.

```
#include <iostream>
using namespace std;

class fi
{
public:
   fi(int, int = 0);
   void print();
   int f() const;
   int g() const;

private:
   int x, y;
};

fi::fi(int a, int b)
{
  x = a;
  y = b;
}
void fi::print()
{
  cout << x << " " << y << endl;
}
int fi::f() const
{
  return x;
}
int fi::g() const
{
  return y;
}

class se
{
public:
    se(double, fi);
    void print() const;
    double h() const;
    fi p() const;
private:
    fi a;
    double b;
};
se::se(double d, fi e)
{
  b = d;
  a = e;
}
void se::print() const
{
  cout << b << endl;
  a.print();
}
double se::h() const
{
  cout << a.f() << " " << a.g() << endl;
  return b;
}
fi se::p() const
{
  return a;
}

int main()
{
  fi m(1), n;
  m.print();
  cout << n.x << " " << n.y << endl;
  se c(1.5, m);
  c.print();
  return 0;
}
```
