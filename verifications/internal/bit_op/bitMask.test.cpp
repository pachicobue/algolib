// verification-helper: UNITTEST
#include <cassert>
#include "internal/bit_op.hpp"
#include "internal/irange.hpp"
#include "internal/type.hpp"
inline bool check(u64 X, int i) { return (X >> i) & 1_u64; }
int main() {
    for (int w : rep(65)) {
        const u64 X = bitMask(w);
        for (int i : rep(64)) { assert(check(X, i) == (i < w)); }
    }
    for (int s : rep(64)) {
        for (int t : irange(s, 65)) {
            const u64 X = bitMask(s, t);
            for (int i : rep(64)) { assert(check(X, i) == (s <= i and i < t)); }
        }
    }
    return 0;
}
