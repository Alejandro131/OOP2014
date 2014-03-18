###Тест 3

####Разгледайте следващия клас. Посочете неговите конструктори, мутатори и член-функции за достъп.
```
class example
{
public:
    example();
    example(int);
    void f();
    void g();
    int h() const;
    void k() const;

private:
    int a;
};

example::example()
{
  a = 5;
}
example::example(int x)
{
  a = x+2;
}
void example::f()
{
  a++;
}
void example::g()
{
  f();
  a = 2*a;
  f();
}
int example::h() const
{
  return a+1;
}
void example::k() const
{
  cout << a+3 << endl;
}
```


####Какво ще изведе следващата главна функция?
```
int main()
{
  example x;
  example y(5);
  example z = y;
  example t = example (3);
  x.f(); y.g(); z.f(); t.g();
  t.k();
  example p(x.h()+y.h()+z.h());
  p.k();
  return 0;
}
```
####Добавете към класа example член-функция c(), която дели a на 5, ако то е кратно на 5, и го заменя с 3.a+1, ако не е кратно на 5. Дефинирайте и член-функция e(example b), която връща истина, ако соченият от неявния параметър обект е равен на явния параметър b. Тези две член-функции на класа example да се дефинирани като вградени.

