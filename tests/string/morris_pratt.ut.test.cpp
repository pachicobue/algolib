// verification-helper: UNITTEST
#include "string/morris_pratt.hpp"

void Test()
{
    Str s = "aabaabaaa";
    const auto rs = morrisPratt(s);
    assert(rs == (Vec<int>{-1, 0, 1, 0, 1, 2, 3, 4, 5, 2}));
}

int main()
{
    Test();
    return 0;
}
