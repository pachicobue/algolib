// verification-helper: UNITTEST
#include <cassert>
#include "internal/seq_op.hpp"
#include "internal/type.hpp"
template <typename Vs> void lessTest() {
    const Vs vs{101, 23, 34, 15, 29, 109, 15};
    assert(seqMaxInd(vs) == 5);
}
template <typename Vs> void greaterTest() {
    const Vs vs{101, 23, 34, 15, 29, 109, 15};
    assert(seqMaxInd(vs, Gt<int>{}) == 3);
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
