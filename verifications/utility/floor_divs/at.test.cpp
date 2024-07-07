// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/floor_divs.hpp"
void test() {
    for (i64 X : irange(1, 101)) {
        Vec<i64> actual;
        for (i64 i : irange(X, 0, -1)) {
            const i64 y = X / i;
            if (actual.empty() or actual.back() != y) { actual.push_back(y); }
        }
        const auto fds = FloorDivs{X};
        for (int i : rep(actual.size())) { assert(fds.at(i) == actual[i]); }
    }
}
int main() {
    test();
    return 0;
}
