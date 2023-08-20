// verification-helper: UNITTEST
#include "internal/seq_op.hpp"
template<typename Vs> void test()
{
    const Vs vs                   = {3, 3, 4, 5, 1, 1, 1, 1, 2, 10, 10, 10, 10};
    const Vec<Pair<int, int>> ans = {
        {3,  2},
        {4,  1},
        {5,  1},
        {1,  4},
        {2,  1},
        {10, 4}
    };
    assert(std::ranges::equal(seqRleVec(vs), ans));
}
int main()
{
    test<Vec<int>>();
    test<Deq<int>>();
    return 0;
}
