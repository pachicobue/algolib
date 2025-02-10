// verification-helper: UNITTEST
#include "linear_algebra/int_bases.hpp"
#include <cassert>
#include "internal.hpp"
#include "linear_algebra/int_bases.hpp"
void Test() {
    Vec<u64> vs{3, 1, 2, 5};
    IntBases bases;
    for (u64 v : vs) {
        bases.add(v);
    }
    assert(bases.rank() == 3); // 011,101,001
    const auto origBases = bases.origBases();
    assert(origBases == (Vec<u64>{3, 1, 5}));
    assert(bases.decomp(2));
    assert(bases.decomp(2).value() == 3);
}

int main() {
    Test();
    return 0;
}
