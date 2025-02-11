// verification-helper: UNITTEST
#include <cassert>
#include "internal/seq_op.hpp"
#include "internal/type.hpp"
template <typename Vs> void lessTest() {
    const Vs vs{101, 23, 34, 15, 29, 109, 15};
    assert(seqMinInd(vs) == 3);
}
template <typename Vs> void greaterTest() {
    const Vs vs{101, 23, 34, 15, 29, 109, 15};
    assert(seqMinInd(vs, Gt<int>{}) == 5);
}
int main() {
    lessTest<int[7]>();
    lessTest<Vec<int>>();
    lessTest<Deq<int>>();

    greaterTest<int[7]>();
    greaterTest<Vec<int>>();
    greaterTest<Deq<int>>();
    return 0;
}
