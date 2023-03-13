// verification-helper: UNITTEST
#include "internal/bit_op.hpp"

void popCountTest()
{
    assert(popCount(0x0123456789ABCDEF) == 32);
    assert(popCount(0x0) == 0);
}

void topBitTest()
{
    assert(topBit(0x0123456789ABCDEF) == 56);
    assert(topBit(0x8000000000000000) == 63);
    assert(topBit(0xFFFFFFFFFFFFFFFF) == 63);
    assert(topBit(0x1) == 0);
    assert(topBit(0x0) == -1);
}

void lowBitTest()
{
    assert(lowBit(0x0123456789ABCDEF) == 0);
    assert(lowBit(0x8000000000000000) == 63);
    assert(lowBit(0x0) == 64);
}

void bitWidthTest()
{
    assert(bitWidth(0x0123456789ABCDEF) == 57);
    assert(bitWidth(0x8000000000000000) == 64);
    assert(bitWidth(0x0) == 0);
}

void bitCeilTest()
{
    assert(bitCeil(0x0123456789ABCDEF) == 0x0200000000000000);
    assert(bitCeil(0x8000000000000000) == 0x8000000000000000);
    assert(bitCeil(0x0) == 1);
}

void bitFloorTest()
{
    assert(bitFloor(0x0123456789ABCDEF) == 0x0100000000000000);
    assert(bitFloor(0x8000000000000000) == 0x8000000000000000);
    assert(bitFloor(0x8000000000000001) == 0x8000000000000000);
    assert(bitFloor(0x1) == 1);
    assert(bitFloor(0x0) == 0);
}

void hasSingleBitTest()
{
    assert(hasSingleBit(0x0123456789ABCDEF) == false);
    assert(hasSingleBit(0x8000000000000000) == true);
    assert(hasSingleBit(0x8000000000000001) == false);
    assert(hasSingleBit(0x1) == true);
    assert(hasSingleBit(0x0) == false);
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
    popCountTest();
    topBitTest();
    lowBitTest();
    bitWidthTest();
    bitCeilTest();
    bitFloorTest();
    hasSingleBitTest();
    isBitOnOffTest();
    return 0;
}
