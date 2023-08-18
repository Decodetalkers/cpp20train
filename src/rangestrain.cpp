#include <iostream>
#include <optional>
#include <ranges>
#include <vector>

template<std::ranges::range R>
auto
to_vector(R &&r)
{
    auto r_common = r | std::views::common;
    return std::vector(r_common.begin(), r_common.end());
}

struct ABC {
    std::optional<int> a;
    std::optional<int> b;
};

int
main()
{
    auto const ints = {0, 1, 2, 3, 4, 5};
    auto even       = [](int i) { return 0 == i % 2; };
    auto square     = [](int i) { return i * i; };

    for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    for (int i : std::views::transform(std::views::filter(ints, even), square))
        std::cout << i << ' ';

    std::vector<int> e = to_vector(ints | std::views::filter(even));
    for (int a : e) {
        std::cout << a << std::endl;
    }
    auto eee = ABC{};
    eee.a.value_or(3);
    return 0;
}
