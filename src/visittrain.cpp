#include <iomanip>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

using var_t = std::variant<int, long, double, std::string>;

auto e = std::visit([]() -> int {
    std::cout << "ss" << std::endl;
    return 3;
});

auto m = std::visit([]() -> int {
    std::cout << "beta2" << std::endl;
    return e - 10;
});

template<class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};

// in cpp 20, noneeded again
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

int
main(void)
{
    std::cout << "beta111" << std::endl;
    std::vector<var_t> vec = {10, 15l, 1.5, "hello"};
    auto f                 = [](var_t v) {
        std::visit(overloaded{[](auto arg) { std::cout << arg << std::endl; },
                              [](double arg) { std::cout << std::fixed << arg << ' '; },
                              [](const std::string &arg) { std::cout << std::quoted(arg) << ' '; }},
                   v);
    };
    for (auto &v : vec) {
        f(v);
    }
    std::cout << e << std::endl;
    std::cout << e << std::endl;
    std::cout << m << std::endl;
    std::cout << m << std::endl;
    return 0;
}
