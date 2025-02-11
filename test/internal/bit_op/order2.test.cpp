// verification-helper: UNITTEST
#include <cassert>
#include "internal/bit_op.hpp"
#include "internal/constant.hpp"
#include "internal/irange.hpp"
#include "internal/type.hpp"
#include "utility/rng.hpp"
inline int check(u64 X) {
    int o = 0;
    while (X % 2 == 0) {
        X /= 2, o++;
    }
    return o;
}
int main() {
    assert(order2(0) == 64);
    for (int d : rep(64)) {
        assert(order2(1_u64 << d) == d);
        u64 X = rng.val<u64>(0_u64, LIMMAX<u64>);
        X = (X / 2) * 2 + 1, X <<= d;
        assert(order2(X) == check(X));
    }
    return 0;
}
