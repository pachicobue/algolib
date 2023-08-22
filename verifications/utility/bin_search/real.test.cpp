// verification-helper: UNITTEST
#include "utility/bin_search.hpp"
#include "utility/rng.hpp"
void test()
{
    const auto X = (f80)rng.val<i64>(2, 1000000000);
    const auto R = binSearch(
        X, 0, [&](f80 i) { return i * i <= X; }, 100);
    const auto Actual = std::sqrt(X);
    assert(std::abs(Actual - R) <= 1e-9);
}
int main()
{
    test();
    return 0;
}
