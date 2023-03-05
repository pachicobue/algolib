// verification-helper: UNITTEST
#include "utility/nd_rep.hpp"

void Test()
{
    std::vector<std::vector<int>> iss;
    for (auto is : ndRep({2, 3, 4})) {
        assert(0 <= is[0] and is[0] < 2);
        assert(0 <= is[1] and is[1] < 3);
        assert(0 <= is[2] and is[2] < 4);
        iss.push_back(is);
    }
    assert(iss.size() == 2 * 3 * 4);
    assert(std::is_sorted(iss.begin(), iss.end()));
}

int main()
{
    Test();
    return 0;
}
