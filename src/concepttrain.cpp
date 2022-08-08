#include "concepttrain/gamera.hpp"

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
int
main()
{
    using std::operator""s;

    f("abc"s); // OK, std::string satisfies Hashable
               // f(meow{}); // Error: meow does not satisfy Hashable
    getstring(meow{});
	struct Gammera a = {.a=10};
	getstring(a);
}
