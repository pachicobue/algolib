// verification-helper: UNITTEST
#include "internal/irange.hpp"
void test()
{
    int cnt = 0;
    for (int i : per(100)) {
        assert(i == 99 - cnt);
        cnt++;
    }
}
int main()
{
    test();
    return 0;
}
