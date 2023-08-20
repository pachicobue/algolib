// verification-helper: UNITTEST
#include "internal/seq_op.hpp"
template<typename Vs> void test()
{
    Vs vs{101, 23, 34, 15, 29, 109, 15};
    const Vs ans{15, 109, 29, 15, 34, 23, 101};
    seqReverse(vs);
    assert(std::ranges::equal(vs, ans));
}
int main()
{
    test<int[7]>();
    test<Vec<int>>();
    test<Deq<int>>();
    return 0;
}
