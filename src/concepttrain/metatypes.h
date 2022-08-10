#include <string>
template<typename T>
concept Countable = requires(T a)
{
    {
        a.name()
        } -> std::convertible_to<std::string>;
    {
        a.count()
        } -> std::convertible_to<int>;
    {a.addcount()};
};
template<typename T>
concept Friendable = requires(T a)
{
    {
        a.code
        } -> std::convertible_to<int>;
    {
        a.count
        } -> std::convertible_to<int>;
};
