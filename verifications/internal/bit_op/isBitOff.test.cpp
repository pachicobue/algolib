// verification-helper: UNITTEST
#include "internal/bit_op.hpp"
#include "utility/rng.hpp"
inline bool stupid(u64 X, int i) { return ((X >> i) & (1_u64)) == 0; }
int main()
{
    LOOP (100) {
        const auto X = rng.val<u64>(1, LIMMAX<u64>);
        for (int i : rep(64)) { assert(isBitOff(X, i) == stupid(X, i)); }
    }
    return 0;
}
