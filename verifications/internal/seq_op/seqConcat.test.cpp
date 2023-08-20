// verification-helper: UNITTEST
#include "internal/seq_op.hpp"
template<typename Vs> void test()
{
    Vs as{1, 2, 3, 4, 5};
    const Vs bs{6, 7, 8, 9, 10};
    seqConcat(as, bs);
    const Vs ans{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(std::ranges::equal(as, ans));
}
int main()
{
    test<Vec<int>>();
    test<Deq<int>>();
    return 0;
}
