// verification-helper: UNITTEST
#include "../../src/common/int_div.hpp"
void fdivTest()
{
    auto f = [&](auto x, auto y) {
        auto a = (decltype(x))std::floor((f80)x / y);
        assert(floorDiv(x, y) == a);
    };
    for (int x = -100; x <= 100; x++) {
        for (int y = -100; y <= 100; y++) {
            if (y == 0) { continue; }
            f(x, y);
        }
    }
}

void cdivTest()
{
    auto c = [&](auto x, auto y) {
        auto a = (decltype(x))std::ceil((f80)x / y);
        assert(ceilDiv(x, y) == a);
    };
    for (int x = -100; x <= 100; x++) {
        for (int y = -100; y <= 100; y++) {
            if (y == 0) { continue; }
            c(x, y);
        }
    }
}

int main()
{
    fdivTest();
    cdivTest();
    return 0;
}
