#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/common/bit_op.hpp"

void popcountTest()
{
    assert(popcount(0x0123456789ABCDEF) == 32);
    assert(popcount(0x0) == 0);
}

void log2p1Test()
{
    assert(log2p1(0x0123456789ABCDEF) == 57);
    assert(log2p1(0x8000000000000000) == 64);
    assert(log2p1(0xFFFFFFFFFFFFFFFF) == 64);
    assert(log2p1(0x1) == 1);
    assert(log2p1(0x0) == 0);
}

void lsbp1Test()
{
    assert(lsbp1(0x0123456789ABCDEF) == 1);
    assert(lsbp1(0x8000000000000000) == 64);
    assert(lsbp1(0x0) == 0);
}

void clogTest()
{
    assert(ceillog(0x0123456789ABCDEF) == 57);
    assert(ceillog(0x8000000000000000) == 63);
    assert(ceillog(0x0) == 0);
}

void ceil2Test()
{
    assert(ceil2(0x0123456789ABCDEF) == 0x0200000000000000);
    assert(ceil2(0x8000000000000000) == 0x8000000000000000);
    assert(ceil2(0x0) == 1);
}

void floor2Test()
{
    assert(floor2(0x0123456789ABCDEF) == 0x0100000000000000);
    assert(floor2(0x8000000000000000) == 0x8000000000000000);
    assert(floor2(0x8000000000000001) == 0x8000000000000000);
    assert(floor2(0x1) == 1);
    assert(floor2(0x0) == 0);
}

void ispow2Test()
{
    assert(ispow2(0x0123456789ABCDEF) == false);
    assert(ispow2(0x8000000000000000) == true);
    assert(ispow2(0x8000000000000001) == false);
    assert(ispow2(0x1) == true);
    assert(ispow2(0x0) == false);
}

void btestTest()
{
    const i64 v = 0x3333333333333333;
    for (int i = 0; i < 64; i++) {
        assert(btest(v, i) == ((i % 4) < 2));
    }
}

int main()
{
    popcountTest();
    log2p1Test();
    lsbp1Test();
    clogTest();
    ceil2Test();
    floor2Test();
    ispow2Test();
    btestTest();
    std::cout << "Hello World\n";
    return 0;
}
