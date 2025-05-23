// verification-helper: UNITTEST
#include <cassert>
#include "internal/bit_op.hpp"
#include "internal/constant.hpp"
#include "internal/irange.hpp"
#include "internal/type.hpp"
#include "utility/rng.hpp"
inline bool stupid(u64 X, int i) {
    return (X >> i) & (1_u64);
}
int main() {
    LOOP (100) {
        const auto X = rng.val<u64>(1, LIMMAX<u64>);
        for (int i : rep(64)) {
            assert(isBitOn(X, i) == stupid(X, i));
        }
    }
    return 0;
}
