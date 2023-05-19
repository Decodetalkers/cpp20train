#include <iostream>
class A
{
public:
    A();
    A(A &&)                 = default;
    A(const A &)            = default;
    A &operator=(A &&)      = default;
    A &operator=(const A &) = default;
    ~A();
    friend class B;

private:
    int b;

private:
};

A::A()
  : b(10)
{
}

A::~A()
{
}
class B
{
public:
    B();
    B(B &&)                 = default;
    B(const B &)            = default;
    B &operator=(B &&)      = default;
    B &operator=(const B &) = default;
    ~B();
    void display(A &a);

private:
};

B::B()
{
}

B::~B()
{
}

void
B::display(A &a)
{
    std::cout << a.b << std::endl;
}

int
main()
{
    A a;
    B b;
    b.display(a);
    return 0;
}
