// verification-helper: UNITTEST
#include "internal/seq_op.hpp"
#include "internal/irange.hpp"
#include "utility/rng.hpp"
template<typename Vs> int check(const Vs& vs, int v)
{
    int i = 0;
    for (; i < std::ssize(vs); i++) {
        if (v <= vs[i]) { break; }
    }
    return i;
}
template<typename Vs> void test()
{
    const Vs vs = {0, 0, 1, 2, 3, 3, 3, 100, 100, 101};
    assert(std::ranges::is_sorted(vs));
    LOOP (100) {
        const int v = rng.val(-1, 110);
        assert(sortedLbInd(vs, v) == check(vs, v));
    }
}
int main()
{
    test<int[10]>();
    test<Vec<int>>();
    test<Deq<int>>();
    return 0;
}
