#include <array>
#include <iostream>
#include <type_traits>

template<class RandomAccessIterator, typename Func>
void
mysort(RandomAccessIterator begin, RandomAccessIterator end, Func func)
{
    using type = std::remove_cvref_t<decltype(*begin)>;
    static_assert(std::is_invocable_r_v<bool, Func, type, type>);
    while (true) {
        RandomAccessIterator beginBack = begin;
        RandomAccessIterator beginNext = begin;
        ++beginNext;
        bool has_swap = false;
        while (beginNext != end) {
            if (func(*beginBack, *beginNext)) {
                has_swap   = true;
                type tmp   = *beginBack;
                *beginBack = *beginNext;
                *beginNext = tmp;
            }
            ++beginBack;
            ++beginNext;
        }
        if (!has_swap) {
            break;
        }
    }
}

int
main()
{
    std::array<int, 7> a1{3, 1, 5, 8, 99, 88, -1};

    mysort(a1.begin(), a1.end(), [](int a, int b) { return a > b; });
    for (auto i : a1) {
        std::cout << i << std::endl;
    }
    return 0;
}
