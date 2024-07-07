// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/dynamic_bitset.hpp"
#include "utility/rng.hpp"
void emptyTest() {
    DynamicBitset bs;
    assert(bs.size() == 0);
}
void intTest() {
    const auto N = 1000;
    DynamicBitset bs{N};
    assert(bs.size() == N);
    for (int i : rep(N)) { assert(not bs.test(i)); }
}
void strTest() {
    const auto N = 1000;
    Str S(N, '0');
    for (int i : rep(N)) { S[i] = '0' + rng.val(0, 1); }
    DynamicBitset bs{S};
    assert(bs.size() == N);
    for (int i : rep(N)) { assert(bs.test(i) == (S[N - i - 1] - '0')); }
}
int main() {
    emptyTest();
    intTest();
    strTest();
    return 0;
}
