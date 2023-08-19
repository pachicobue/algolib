// verification-helper: UNITTEST
#include "utility/md_rep.hpp"

void Test()
{
    std::vector<std::vector<i64>> iss;
    for (auto is : mdRep({
             {0, 1},
             {2, 3, 4},
             {5, 6, 7, 8}
    })) {
        SHOW(is);
        assert(0 <= is[0] and is[0] <= 1);
        assert(2 <= is[1] and is[1] <= 4);
        assert(5 <= is[2] and is[2] <= 8);
        iss.push_back(is);
    }
    assert(iss.size() == 2 * 3 * 4);
}

int main()
{
    Test();
    return 0;
}
