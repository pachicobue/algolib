// verification-helper: UNITTEST
#include <algorithm>
#include <cassert>
#include "internal/seq_op.hpp"
#include "internal/type.hpp"
template <typename Vs> void lessTest() {
    Vs vs{101, 23, 34, 15, 29, 109, 15};
    const Vs ans{15, 15, 23, 29, 34, 101, 109};
    seqSort(vs);
    assert(std::ranges::equal(vs, ans));
}
template <typename Vs> void greaterTest() {
    Vs vs{101, 23, 34, 15, 29, 109, 15};
    const Vs ans{109, 101, 34, 29, 23, 15, 15};
    seqSort(vs, Gt<int>{});
    assert(std::ranges::equal(vs, ans));
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
