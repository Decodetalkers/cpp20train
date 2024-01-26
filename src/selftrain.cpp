#include <array>
#include <iostream>
#include <type_traits>

template<class RandomAccessIterator, typename Func>
void
my_sort(RandomAccessIterator begin, RandomAccessIterator end, Func func)
{
    using type = std::remove_cvref_t<decltype(*begin)>;
    static_assert(std::is_invocable_r_v<bool, Func, type, type>);
    while (true) {
        RandomAccessIterator beginBack = begin;
        RandomAccessIterator beginNext = begin + 1;
        bool has_swap                  = false;
        while (beginNext != end) {
            if (func(*beginBack, *beginNext)) {
                has_swap = true;
                std::swap(*beginBack, *beginNext);
            }
            ++beginBack;
            ++beginNext;
        }
        if (!has_swap) {
            break;
        }
    }
}
template<class RandomAccessIterator, typename Func>
void
my_for_each(RandomAccessIterator begin, RandomAccessIterator end, Func func)
{
    using type = std::remove_cv_t<decltype(*begin)>;
    static_assert(std::is_invocable_r_v<void, Func, type>);
    RandomAccessIterator beginBack = begin;
    while (beginBack != end) {
        func(*beginBack);
        ++beginBack;
    }
}
int
main()
{
    std::array<int, 7> a1{3, 1, 5, 8, 99, 88, -1};

    std::cout << "my sort" << std::endl;
    my_sort(a1.begin(), a1.end(), [](int a, int b) { return a > b; });
    for (auto i : a1) {
        std::cout << i << std::endl;
    }
    my_for_each(a1.begin(), a1.end(), [](int &a) { a += 1; });

    std::cout << "for each" << std::endl;
    for (auto i : a1) {
        std::cout << i << std::endl;
    }
    return 0;
}
