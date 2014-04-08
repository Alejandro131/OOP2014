Тест 4
- - -

####Намерете резултата от изпълнението на програмата


```
include <iostream>
using namespace std;

class A
{ public:
    A(int = 1, int = 2);
	   A(const A&);
    void print() const;
    int get_x() const;
    int get_y() const;
  private:
    int x, y;
};
A::A(int a, int b)
{ cout << "A(" << a << ", " << b << ")\n";
  x = a;
  y = b;
}
A::A(const A& p)
{ cout << "A(const&)\n";
  x = p.x+1;
  y = p.y+2;
}
void A::print() const
{ cout << x << " " << y << endl;
}
int A::get_x() const
{ return x;
}
int A::get_y() const
{ return y;
}

class B
{ public:
    B(double, const A&, A);
    B(const B&);
    void print() const;
    double get_x() const;
    A get_a1() const;
    A get_a2() const;
  private:
    A a1, a2;
    double x;
};
B::B(double d, const A& e1, A e2) : a2(e2)
{ cout << "B(" << d << ", " << e1.get_x() << ", "
       << e1.get_y() << ", " << e2.get_x() << ", "
       << e2.get_y()<< ")\n";
  x = d;
  a1 = A(e1);
}
B::B(const B& b) : a1(b.a1), a2(b.a2)
{ cout << "B(const B&)\n";
  x = b.x;
}
void B::print() const
{ cout << x << endl;
  a1.print();
  a2.print();
}
double B::get_x() const
{ return x;
}
A B::get_a1() const
{ return a1;
}
A B::get_a2() const
{ return a2;
}

int main()
{ A p(7), q(p);
  q.print();
  B b(2.3, p, q), c = b;
  c.print();
  return 0;
}
```
