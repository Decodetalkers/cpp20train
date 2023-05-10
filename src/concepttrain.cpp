#include "concepttrain/gamera.hpp"
#include "concepttrain/metatypes.h"

#include <concepts>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
// Declaration of the concept "Hashable", which is satisfied by any type 'T'
// such that for values 'a' of type 'T', the expression std::hash<T>{}(a)
// compiles and its result is convertible to std::size_t
template<typename T>
concept Hashable = requires(T a)
{
    {
        std::hash<T>{}(a)
        } -> std::convertible_to<std::size_t>;
};

struct meow
{
    std::string stringify() { return "beta"; }
};

// Constrained C++20 function template:
template<Hashable T>
void
f(T)
{
}
//
// Alternative ways to apply the same constraint:
// template<typename T>
//     requires Hashable<T>
// void f(T) {}
//
// template<typename T>
// void f(T) requires Hashable<T> {}
//
// void f(Hashable auto /*parameterName*/) {}
template<typename T>
concept Stringable = requires(T a)
{
    {
        a.stringify()
        } -> std::convertible_to<std::string>;
};

template<Stringable T>
void
getstring(T input)
{
    std::cout << input.stringify() << std::endl;
}

template<Countable T>
void
addAndPrint(T input)
{
    std::cout << input.name() << std::endl;
    std::cout << input.count() << std::endl;
    input.addcount();
    std::cout << input.count() << std::endl;
}

struct TestStruct
{
    std::string m_name;
    int m_count;
    void addcount() { m_count += 1; }
    inline std::string name() { return m_name; }
    inline int count() { return m_count; }
};

struct TestStruct2
{
    std::string m_name;
    int m_count;
    void addcount() { m_count += 1; }
    inline std::string name() { return m_name; }
    inline int count() { return m_count; }
};

struct MyStructA
{
    int a = 100;
    friend struct MyStructB;

private:
    int code  = 10;
    int count = 100;
};

struct MyStructB
{
    int code = 0;
    template<Friendable T>
    void iamYourFriend(T input)
    {
        std::cout << input.code << input.count << std::endl;
    }
};

template<typename T>
[[nodiscard]] T
unwrap(T *input)
{
    return *input;
}

int
main()
{
    using std::operator""s;

    f("abc"s); // OK, std::string satisfies Hashable
               // f(meow{}); // Error: meow does not satisfy Hashable
    getstring(meow{});
    struct Gammera a = {.a = 10};
    getstring(a);
    addAndPrint(TestStruct{.m_name = "test"});
    addAndPrint(TestStruct2{.m_name = "test2"});
    struct MyStructA frienda = MyStructA{};
    struct MyStructB friendb = {};
    friendb.iamYourFriend(frienda);
    struct MyStructB *friende = new MyStructB{};
    auto e                    = unwrap(friende);
    e.code                    = 100;
    std::cout << friende->code << std::endl;
    friende->code = 30;
    std::cout << friende->code << std::endl;
    (*friende).code = 90;
    std::cout << friende->code << std::endl;
    auto f = (*friende);
    f.code = 9000;
    std::cout << friende->code << std::endl;
    (*friende).code = 1000;
    std::cout << friende->code << std::endl;
}
