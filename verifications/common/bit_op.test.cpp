// verification-helper: UNITTEST
#include "internal/bit_op.hpp"

void floorLog2Test()
{
    assert(floorLog2(0x0123456789ABCDEF) == 56);
    assert(floorLog2(0x8000000000000000) == 63);
    assert(floorLog2(0xFFFFFFFFFFFFFFFF) == 63);
    assert(floorLog2(0x1) == 0);
    assert(floorLog2(0x0) == -1);
}

void order2Test()
{
    assert(order2(0x0123456789ABCDEF) == 0);
    assert(order2(0x8000000000000000) == 63);
    assert(order2(0x0) == 64);
}

void isBitOnOffTest()
{
    const i64 v = 0x3333333333333333;
    for (int i = 0; i < 64; i++) {
        assert(isBitOn(v, i) == ((i % 4) < 2));
        assert(isBitOff(v, i) == not((i % 4) < 2));
    }
}

int main()
{
    floorLog2Test();
    order2Test();
    isBitOnOffTest();
    return 0;
}
