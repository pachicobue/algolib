// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/dynamic_bitset.hpp"
#include "utility/rng.hpp"
void andEqTest() {
    const auto N = 1000;
    Vec<int> vs1(N), vs2(N);
    DynamicBitset bs1{N}, bs2{N};
    for (int i : rep(N)) {
        vs1[i] = rng.val(0, 1), vs2[i] = rng.val(0, 1);
        bs1.set(i, vs1[i]), bs2.set(i, vs2[i]);
    }
    bs1 &= bs2;
    for (int i : rep(N)) { assert(bs1.test(i) == (vs1[i] && vs2[i])); }
}
void orEqTest() {
    const auto N = 1000;
    Vec<int> vs1(N), vs2(N);
    DynamicBitset bs1{N}, bs2{N};
    for (int i : rep(N)) {
        vs1[i] = rng.val(0, 1), vs2[i] = rng.val(0, 1);
        bs1.set(i, vs1[i]), bs2.set(i, vs2[i]);
    }
    bs1 |= bs2;
    for (int i : rep(N)) { assert(bs1.test(i) == (vs1[i] || vs2[i])); }
}
void xorEqTest() {
    const auto N = 1000;
    Vec<int> vs1(N), vs2(N);
    DynamicBitset bs1{N}, bs2{N};
    for (int i : rep(N)) {
        vs1[i] = rng.val(0, 1), vs2[i] = rng.val(0, 1);
        bs1.set(i, vs1[i]), bs2.set(i, vs2[i]);
    }
    bs1 ^= bs2;
    for (int i : rep(N)) { assert(bs1.test(i) == (vs1[i] ^ vs2[i])); }
}
void andTest() {
    const auto N = 1000;
    DynamicBitset bs1{N}, bs2{N};
    for (int i : rep(N)) { bs1.set(i, rng.val(0, 1)), bs2.set(i, rng.val(0, 1)); }
    const auto ans = bs1 & bs2;
    for (int i : rep(N)) { assert(ans.test(i) == (bs1.test(i) && bs2.test(i))); }
}
void orTest() {
    const auto N = 1000;
    DynamicBitset bs1{N}, bs2{N};
    for (int i : rep(N)) { bs1.set(i, rng.val(0, 1)), bs2.set(i, rng.val(0, 1)); }
    const auto ans = bs1 | bs2;
    for (int i : rep(N)) { assert(ans.test(i) == (bs1.test(i) || bs2.test(i))); }
}
void xorTest() {
    const auto N = 1000;
    DynamicBitset bs1{N}, bs2{N};
    for (int i : rep(N)) { bs1.set(i, rng.val(0, 1)), bs2.set(i, rng.val(0, 1)); }
    const auto ans = bs1 ^ bs2;
    for (int i : rep(N)) { assert(ans.test(i) == (bs1.test(i) ^ bs2.test(i))); }
}
void lshiftEqTest() {
    const auto N = 1000;
    LOOP (100) {
        Vec<int> vs(N);
        DynamicBitset bs{N};
        for (int i : rep(N)) { vs[i] = rng.val(0, 1), bs.set(i, vs[i]); }
        const auto s = rng.val(0, N * 2);
        bs <<= s;
        for (int i : rep(N)) {
            if (i >= s) {
                assert(bs.test(i) == vs[i - s]);
            } else {
                assert(not bs.test(i));
            }
        }
    }
}
void rshiftEqTest() {
    const auto N = 1000;
    LOOP (100) {
        Vec<int> vs(N);
        DynamicBitset bs{N};
        for (int i : rep(N)) { vs[i] = rng.val(0, 1), bs.set(i, vs[i]); }
        const auto s = rng.val(0, N * 2);
        bs >>= s;
        for (int i : rep(N)) {
            if (i + s < N) {
                assert(bs.test(i) == vs[i + s]);
            } else {
                assert(not bs.test(i));
            }
        }
    }
}
void lshiftTest() {
    const auto N = 1000;
    LOOP (100) {
        Vec<int> vs(N);
        DynamicBitset bs{N};
        for (int i : rep(N)) { bs.set(i, vs[i]); }
        const auto s = rng.val(0, N * 2);
        const auto ans = bs << s;
        for (int i : rep(N)) {
            if (i >= s) {
                assert(ans.test(i) == bs.test(i - s));
            } else {
                assert(not ans.test(i));
            }
        }
    }
}
void rshiftTest() {
    const auto N = 1000;
    LOOP (100) {
        Vec<int> vs(N);
        DynamicBitset bs{N};
        for (int i : rep(N)) { bs.set(i, vs[i]); }
        const auto s = rng.val(0, N * 2);
        const auto ans = bs >> s;
        for (int i : rep(N)) {
            if (i + s < N) {
                assert(ans.test(i) == bs.test(i + s));
            } else {
                assert(not ans.test(i));
            }
        }
    }
}
void compTest() {
    const auto N = 1000;
    LOOP (100) {
        Vec<int> vs1(N), vs2(N);
        DynamicBitset bs1{N}, bs2{N};
        for (int i : rep(N)) {
            vs1[i] = rng.val(0, 1), vs2[i] = rng.val(0, 1);
            bs1.set(i, vs1[i]), bs2.set(i, vs2[i]);
        }
        if (rng.val(0, 5) == 0) { vs2 = vs1, bs2 = bs1; }
        seqReverse(vs1), seqReverse(vs2);
        assert((bs1 < bs2) == (vs1 < vs2));
        assert((bs1 > bs2) == (vs1 > vs2));
        assert((bs1 <= bs2) == (vs1 <= vs2));
        assert((bs1 >= bs2) == (vs1 >= vs2));
        assert((bs1 == bs2) == (vs1 == vs2));
        assert((bs1 != bs2) == (vs1 != vs2));
    }
}
void notTest() {
    const auto N = 1000;
    DynamicBitset bs{N};
    for (int i : rep(N)) { bs.set(i, rng.val(0, 1)); }
    const auto ans = ~bs;
    for (int i : rep(N)) { assert(ans.test(i) == not bs.test(i)); }
}
int main() {
    andEqTest();
    orEqTest();
    xorEqTest();
    andTest();
    orTest();
    xorTest();

    lshiftEqTest();
    rshiftEqTest();
    lshiftTest();
    rshiftTest();

    compTest();

    notTest();
    return 0;
}
