// verification-helper: UNITTEST
#include "internal/seq_op.hpp"
void test()
{
    const auto vs = iotaVec(5, 10);
    const Vec<int> ans{10, 11, 12, 13, 14};
    assert(std::ranges::equal(vs, ans));
}
int main()
{
    test();
    return 0;
}
