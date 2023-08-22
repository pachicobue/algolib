// verification-helper: UNITTEST
#include "utility/floor_divs.hpp"
#include "utility/rng.hpp"
void test()
{
    for (i64 X : irange(1, 101)) {
        Vec<i64> actual;
        for (i64 i : irange(X, 0, -1)) {
            const i64 y = X / i;
            if (actual.empty() or actual.back() != y) { actual.push_back(y); }
        }
        const auto fds = FloorDivs{X};
        for (int i : rep(actual.size())) { assert(fds.pos(actual[i]) == i); }
    }
}
int main()
{
    test();
    return 0;
}
