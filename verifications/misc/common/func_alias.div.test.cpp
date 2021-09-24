#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../../src/misc/common/func_alias.hpp"
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
    std::cout << "Hello World\n";
    return 0;
}
