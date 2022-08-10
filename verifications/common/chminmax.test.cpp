#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/common/chminmax.hpp"

struct C
{
    C() = default;
    C(int v_) : v{v_} {}
    friend bool operator<(const C& c1, const C& c2)
    {
        return c1.v < c2.v;
    }
    friend bool operator>(const C& c1, const C& c2)
    {
        return c1.v > c2.v;
    }
    int v = 0;
};

void chminTest()
{
    int v = 10;
    for (int i = 100; i >= 0; i--) {
        assert(chmin(v, i) == (i < 10));
        assert(v == std::min(i, 10));
    }

    C cls{10};
    for (int i = 100; i >= 0; i--) {
        assert(chmin(cls, C{i}) == (i < 10));
        assert(cls.v == std::min(i, 10));
    }
}

void chmaxTest()
{
    int v = 10;
    for (int i = 0; i < 100; i++) {
        assert(chmax(v, i) == (i > 10));
        assert(v == std::max(i, 10));
    }

    C cls{10};
    for (int i = 0; i < 100; i++) {
        assert(chmax(cls, C{i}) == (i > 10));
        assert(cls.v == std::max(i, 10));
    }
}

int main()
{
    chminTest();
    chmaxTest();
    std::cout << "Hello World\n";
    return 0;
}
