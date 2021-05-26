#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../../src/misc/common/rng.hpp"

void Test()
{
    const u64 v32_1 = rng();
    const u64 v32_2 = rng_xo();
    const u64 v64_1 = rng64();
    const u64 v64_2 = rng_xo64();
    assert(0_u64 <= v32_1 and v32_1 <= 0xFFFFFFFF_u64);
    assert(0_u64 <= v32_2 and v32_2 <= 0xFFFFFFFF_u64);
    assert(0_u64 <= v64_1 and v64_1 <= 0xFFFFFFFFFFFFFFFF_u64);
    assert(0_u64 <= v64_2 and v64_2 <= 0xFFFFFFFFFFFFFFFF_u64);
}

void valTest()
{
    int min = 10, max = 20;
    const u64 v32_1 = rng.val(min, max);
    const u64 v32_2 = rng_xo.val(min, max);
    const u64 v64_1 = rng64.val(min, max);
    const u64 v64_2 = rng_xo64.val(min, max);
    assert(min <= v32_1 and v32_1 <= max);
    assert(min <= v32_2 and v32_2 <= max);
    assert(min <= v64_1 and v64_1 <= max);
    assert(min <= v64_2 and v64_2 <= max);
}

void pairTest()
{
    int min = 10, max = 20;

    const auto [l32_1, r32_1] = rng.pair(min, max);
    const auto [l32_2, r32_2] = rng_xo.pair(min, max);
    const auto [l64_1, r64_1] = rng64.pair(min, max);
    const auto [l64_2, r64_2] = rng_xo64.pair(min, max);
    assert(min <= l32_1 and l32_1 <= r32_1 and r32_1 <= max);
    assert(min <= l32_2 and l32_2 <= r32_2 and r32_2 <= max);
    assert(min <= l64_1 and l64_1 <= r64_1 and r64_1 <= max);
    assert(min <= l64_2 and l64_2 <= r64_2 and r64_2 <= max);
}

void vecTest()
{
    int n = 10;
    int min = 10, max = 20;
    const auto vs32_1 = rng.vec(n, min, max);
    const auto vs32_2 = rng_xo.vec(n, min, max);
    const auto vs64_1 = rng64.vec(n, min, max);
    const auto vs64_2 = rng_xo64.vec(n, min, max);
    for (const auto v : vs32_1) {
        assert(min <= v and v <= max);
    }
    for (const auto v : vs32_2) {
        assert(min <= v and v <= max);
    }
    for (const auto v : vs64_1) {
        assert(min <= v and v <= max);
    }
    for (const auto v : vs64_2) {
        assert(min <= v and v <= max);
    }
}

void vvecTest()
{
    int m = 3, n = 4;
    int min = 10, max = 20;
    const auto vss32_1 = rng.vvec(m, n, min, max);
    const auto vss32_2 = rng_xo.vvec(m, n, min, max);
    const auto vss64_1 = rng64.vvec(m, n, min, max);
    const auto vss64_2 = rng_xo64.vvec(m, n, min, max);
    for (const auto vs : vss32_1) {
        for (auto v : vs) {
            assert(min <= v and v <= max);
        }
    }
    for (const auto vs : vss32_2) {
        for (auto v : vs) {
            assert(min <= v and v <= max);
        }
    }
    for (const auto vs : vss64_1) {
        for (auto v : vs) {
            assert(min <= v and v <= max);
        }
    }
    for (const auto vs : vss64_2) {
        for (auto v : vs) {
            assert(min <= v and v <= max);
        }
    }
}

int main()
{
    Test();
    valTest();
    pairTest();
    vecTest();
    vvecTest();
    std::cout << "Hello World\n";
    return 0;
}
