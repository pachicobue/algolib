// verification-helper: UNITTEST
#include "internal/bit_op.hpp"
#include "internal/irange.hpp"
#include "internal/constant.hpp"
#include "utility/rng.hpp"
inline int check(u64 X)
{
    int i = 0;
    for (i = 0; i < 64; i++) {
        if ((1_u64 << i) > X) { break; }
    }
    return i - 1;
}
int main()
{
    assert(floorLog2(0) == -1);
    for (int d : irange(1, 65)) {
        assert(floorLog2(1_u64 << (d - 1)) == d - 1);
        const u64 min = 1_u64 << (d - 1);
        const u64 max = (d == 63 ? LIMMAX<u64> : (1_u64 << d) - 1);
        const u64 X   = rng.val<u64>(min, max);
        assert(floorLog2(X) == check(X));
    }
    for (int d : irange(1, 65)) {
        const u64 min = 1_u64 << (d - 1);
        const u64 max = (d == 63 ? LIMMAX<u64> : (1_u64 << d) - 1);
        const u64 X   = rng.val<u64>(min, max);
        assert(floorLog2(X) == check(X));
    }
    return 0;
}
