// verification-helper: UNITTEST
#include "internal/irange.hpp"
void upTest()
{
    int S = -11, E = 45, D = 7;
    const int is[] = {-11, -4, 3, 10, 17, 24, 31, 38};
    int cnt        = 0;
    for (int i : irange(S, E, D)) {
        assert(i == is[cnt]);
        cnt++;
    }
}
void downTest()
{
    int S = 45, E = -11, D = -7;
    const int is[] = {45, 38, 31, 24, 17, 10, 3, -4};
    int cnt        = 0;
    for (int i : irange(S, E, D)) {
        assert(i == is[cnt]);
        cnt++;
    }
}
int main()
{
    upTest();
    downTest();
    return 0;
}
