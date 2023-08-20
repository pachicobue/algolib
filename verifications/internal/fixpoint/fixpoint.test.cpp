// verification-helper: UNITTEST
#include "internal/fixpoint.hpp"
void test()
{
    auto fib = Fix([&](auto self, int i) -> int {
        assert(i >= 0);
        return (i == 0 ? 0 : i == 1 ? 1 : self(i - 2) + self(i - 1));
    });
    // 0,1,1,2,3,5,8,13,21,34,55
    assert(fib(10) == 55);
}
int main()
{
    test();
    return 0;
}
