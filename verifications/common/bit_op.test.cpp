// verification-helper: UNITTEST
#include "internal/bit_op.hpp"

void std::popcountTest()
{
    assert(std::popcount(0x0123456789ABCDEF) == 32);
    assert(std::popcount(0x0) == 0);
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

void std::bit_widthTest()
{
    assert(std::bit_width(0x0123456789ABCDEF) == 57);
    assert(std::bit_width(0x8000000000000000) == 64);
    assert(std::bit_width(0x0) == 0);
}

void std::bit_ceilTest()
{
    assert(std::bit_ceil(0x0123456789ABCDEF) == 0x0200000000000000);
    assert(std::bit_ceil(0x8000000000000000) == 0x8000000000000000);
    assert(std::bit_ceil(0x0) == 1);
}

void std::bit_floorTest()
{
    assert(std::bit_floor(0x0123456789ABCDEF) == 0x0100000000000000);
    assert(std::bit_floor(0x8000000000000000) == 0x8000000000000000);
    assert(std::bit_floor(0x8000000000000001) == 0x8000000000000000);
    assert(std::bit_floor(0x1) == 1);
    assert(std::bit_floor(0x0) == 0);
}

void std::has_single_bitTest()
{
    assert(std::has_single_bit(0x0123456789ABCDEF) == false);
    assert(std::has_single_bit(0x8000000000000000) == true);
    assert(std::has_single_bit(0x8000000000000001) == false);
    assert(std::has_single_bit(0x1) == true);
    assert(std::has_single_bit(0x0) == false);
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
    std::popcountTest();
    topBitTest();
    lowBitTest();
    std::bit_widthTest();
    std::bit_ceilTest();
    std::bit_floorTest();
    std::has_single_bitTest();
    isBitOnOffTest();
    return 0;
}
