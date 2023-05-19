#include <concepts>
#include <string>
template<typename T>
concept BaseType = requires(T a)
{
    {
        a.action()
        } -> std::convertible_to<void>;
    {T::func()};
};

template<typename T>
class Base
{
public:
    void interface() { static_cast<T *>(this)->action(); }

    static void func() { T::func(); }
};

template<BaseType T>
class BaseSecond
{
public:
    void interface() { T::func(); }
};

class Derived : public Base<Derived>
{
public:
    void action() {}

    static void func() {}
};

int
main()
{
    auto e = new Derived;
    e->interface();
    auto f = new BaseSecond<Derived>;
    f->interface();
    return 0;
}
