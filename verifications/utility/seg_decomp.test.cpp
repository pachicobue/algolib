#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/utility/seg_decomp.hpp"
void Test()
{
    const int N = 6;
    SegDecomp segs(N);
    assert(segs[1] == std::make_pair(0, 8));
    assert(segs[2] == std::make_pair(0, 4));
    assert(segs[3] == std::make_pair(4, 8));
    assert(segs[4] == std::make_pair(0, 2));
    assert(segs[5] == std::make_pair(2, 4));
    assert(segs[6] == std::make_pair(4, 6));
    assert(segs[7] == std::make_pair(6, 8));
    assert(segs[8] == std::make_pair(0, 1));
    assert(segs[9] == std::make_pair(1, 2));
    assert(segs[10] == std::make_pair(2, 3));
    assert(segs[11] == std::make_pair(3, 4));
    assert(segs[12] == std::make_pair(4, 5));
    assert(segs[13] == std::make_pair(5, 6));
    assert(segs[14] == std::make_pair(6, 7));
    assert(segs[15] == std::make_pair(7, 8));
    assert(segs.under(1, 7) == Vec<int>({9, 5, 6, 14}));
    assert(segs.over(3) == Vec<int>({1, 2, 5, 11}));
    assert(segs.size() == 16);
}

int main()
{
    Test();
    std::cout << "Hello World\n";
    return 0;
}
