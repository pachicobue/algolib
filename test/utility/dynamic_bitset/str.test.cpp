// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/dynamic_bitset.hpp"
#include "utility/rng.hpp"
void test() {
    const auto N = 1000;
    Str S(N, '0');
    for (int i : rep(N)) {
        S[i] = '0' + rng.val(0, 1);
    }
    DynamicBitset bs{S};
    assert(bs.str() == S);
}
int main() {
    test();
    return 0;
}
