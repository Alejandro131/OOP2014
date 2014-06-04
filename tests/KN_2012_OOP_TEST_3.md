###Тест 3

####Дефинирайте конструкторите thi(fi, se) и thi(const thi&) на класа thi. Намерете резултата от изпълнението на главната функция.

```
#include <iostream>
using namespace std;

class fi
{ public:
   fi(int, int = 0);
   fi(const fi&);
   void print() const;
   int f() const;
   int g() const;
 private:
   int x, y;
};
fi::fi(int a, int b)
{ cout << "fi(" << a << ","
       << b << ")\n";
  x = a;
  y = b;
}
fi::fi(const fi& r)
{ cout << "fi(const fi& r)\n";
  x = r.x;
  y = r.y;
}
void fi::print() const
{ cout << x << " " << y
       << endl;
}
int fi::f() const
{ return x;
}
int fi::g() const
{ return y;
}


 class se
{ public:
    se(double, double);
    se(const se&);
    void print() const;
    double f() const;
    double g() const;
  private:
    double x, y;
};

se::se(double a, double b)
{ cout << "se(" << a << ","
       << b << ")\n";
  x = a;
  y = b;
}
se::se(const se& r)
{ cout << "se(const se& r)\n";
  x = r.x;
  y = r.y;
}
void se::print() const
{ cout << x << " "
       << y << endl;
}
double se::f() const
{ return x;
}
double se::g() const
{ return y;
}

class thi
{ public:
    thi(fi, se);
    thi(const thi&);
    void print() const;
    fi f() const;
    se g() const;
  private:
    fi x;
    se y;
};

// дефиниция на thi(fi, se);








// дефиниция на thi(const&)






void thi::print() const
{ x.print();
  y.print();
}
fi thi::f() const
{ return x;
}
se thi::g() const
{ return y;
}

int main()
{ fi a(1, 1);
  se b(2.5, 2.5);
  thi c(a, b);
  c.print();
  thi d = c;
  d.f().print();
  d.g().print();
  return 0;
}

Резултат от изпълнението:

```
