// verification-helper: UNITTEST
#include "utility/nd_vec.hpp"

void Test()
{
    using V = std::vector<int>;
    using VV = std::vector<V>;
    using VVV = std::vector<VV>;
    using VVVV = std::vector<VVV>;
    const auto vss = ndVec<int>({3, 4});
    assert(vss == VV({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}));
    const auto vssss = ndVec({4, 3, 2, 1}, 1);
    assert(vssss
           == VVVV({{{{1}, {1}}, {{1}, {1}}, {{1}, {1}}},
                    {{{1}, {1}}, {{1}, {1}}, {{1}, {1}}},
                    {{{1}, {1}}, {{1}, {1}}, {{1}, {1}}},
                    {{{1}, {1}}, {{1}, {1}}, {{1}, {1}}}}));
}

int main()
{
    Test();
    return 0;
}
