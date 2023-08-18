#include <concepts>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
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

template<int N>
consteval int
test()
{
    if constexpr (N > 100) {
        return 99;
    }
    return N + 1;
}

struct S
{
    template<typename Callable>
    void operator<<(Callable f)
    {
        f();
    }
    int operator[](int i) { return i + 100; }
    std::string operator[](std::string_view i) { return std::format("{}ss", i); }
};

struct E
{
    int test() { return 100; }
};

struct F
{
    int test() { return 101; }
};

template<typename T>
int
hasFunc(T a)
{
    return a.test();
}

int
main()
{
    auto e = new Derived;
    e->interface();
    auto f = new BaseSecond<Derived>;
    f->interface();
    constexpr auto plusone = test<101>();
    std::cout << plusone << std::endl;
    auto caller = S{};
    caller << [] { std::cout << "ss"; };
    std::cout << caller[100] << std::endl;
    std::cout << caller["beta"] << std::endl;
    std::cout << hasFunc(E{}) << std::endl;
    std::cout << hasFunc(F{}) << std::endl;
    return 0;
}
