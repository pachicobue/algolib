// verification-helper: UNITTEST
#include "utility/rng.hpp"

void Test()
{
    const u64 v32_1 = rng();
    const u64 v64_1 = rng64();
    assert(0_u64 <= v32_1 and v32_1 <= 0xFFFFFFFF_u64);
    assert(0_u64 <= v64_1 and v64_1 <= 0xFFFFFFFFFFFFFFFF_u64);
}

void valTest()
{
    int min = 10, max = 20;
    const int v32_1 = rng.val(min, max);
    const int v64_1 = rng64.val(min, max);
    assert(min <= v32_1 and v32_1 <= max);
    assert(min <= v64_1 and v64_1 <= max);
}

void vecTest()
{
    int n   = 10;
    int min = 10, max = 20;
    const auto vs32_1 = rng.vec(n, min, max);
    const auto vs64_1 = rng64.vec(n, min, max);
    for (const auto v : vs32_1) { assert(min <= v and v <= max); }
    for (const auto v : vs64_1) { assert(min <= v and v <= max); }
}

int main()
{
    Test();
    valTest();
    vecTest();
    return 0;
}
