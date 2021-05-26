#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../../src/misc/common/xoshiro.hpp"

void Test()
{
    Xoshiro32 xo32;
    Xoshiro64 xo64;
    u64 v32 = 0;
    u64 v64 = 0;
    for (int i = 0; i < 100; i++) {
        v32 = std::max(v32, (u64)xo32());
        v64 = std::max(v64, xo64());
    }
    assert(0xEFFFFFFF_u64 <= v32 and v32 <= 0xFFFFFFFF_u64);
    assert(0xEFFFFFFFFFFFFFFF_u64 <= v64 and v64 <= 0xFFFFFFFFFFFFFFFF_u64);
}

int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}
