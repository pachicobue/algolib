#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/common.hpp"
#include "../../src/util/scanner.hpp"

std::stringstream ss;
Scanner scanner{ss};

class C
{
public:
    C() = default;
    C(int s_) : s{s_} {}
    friend Istream& operator>>(Istream& is, C& cls)
    {
        char c;
        is >> c;
        assert(c == '{');
        is >> cls.s;
        is >> c;
        assert(c == '}');
        return is;
    }
    friend bool operator==(const C& c1, const C& c2) { return c1.s == c2.s; }

private:
    int s;
};

void valTest()
{
    {
        const int v = 100;
        ss << "100";
        const auto rv = scanner.val<int>();
        assert(v == rv);
        ss.clear();
    }
    {
        const char c = 'a';
        ss << "a";
        const auto rc = scanner.val<char>();
        assert(c == rc);
        ss.clear();
    }
    {
        const Str s = "ABCabc012";
        ss << "ABCabc012";
        const auto rs = scanner.val<Str>();
        assert(s == rs);
        ss.clear();
    }
    {
        const C cls{100};
        ss << "{100}";
        const auto rcls = scanner.val<C>();
        assert(cls == rcls);
        ss.clear();
    }
}

void valOffsetTest()
{
    {
        const int v = 100;
        const int offset = 10;
        ss << "100";
        const auto rv = scanner.val<int>(offset);
        assert(v - offset == rv);
        ss.clear();
    }
}

void vecTest()
{
    const int n = 5;
    Vec<int> vs = {1, 2, 3, 4, 5};
    ss << "1 2 3 4 5";
    const auto rvs = scanner.vec<int>(n);
    for (int i : rep(n)) { assert(vs[i] == rvs[i]); }
    ss.clear();
}

void vecOffsetTest()
{
    const int n = 5;
    const int offset = 1;
    Vec<int> vs = {1, 2, 3, 4, 5};
    ss << "1 2 3 4 5";
    const auto rvs = scanner.vec<int>(n, offset);
    for (int i : rep(n)) { assert(vs[i] - offset == rvs[i]); }
    ss.clear();
}

void vvecTest()
{
    const int m = 2;
    const int n = 3;
    Vec<Vec<int>> vss = {{1, 2, 3}, {4, 5, 6}};
    ss << "1 2 3\n"
          "4 5 6";
    const auto rvss = scanner.vvec<int>(m, n);
    for (int i : rep(m)) {
        for (int j : rep(n)) { assert(vss[i][j] == rvss[i][j]); }
    }
    ss.clear();
}

void vvecOffsetTest()
{
    const int m = 2;
    const int n = 3;
    const int offset = 1;
    Vec<Vec<int>> vss = {{1, 2, 3}, {4, 5, 6}};
    ss << "1 2 3\n"
          "4 5 6";
    const auto rvss = scanner.vvec<int>(m, n, offset);
    for (int i : rep(m)) {
        for (int j : rep(n)) { assert(vss[i][j] - offset == rvss[i][j]); }
    }
    ss.clear();
}

void tupTest()
{
    const int v = 100;
    const char c = 'a';
    const Str s = "abcABC012";
    const C cls{100};
    ss << "100 a abcABC012 {100}";
    const auto [rv, rc, rs, rcls] = scanner.tup<int, char, Str, C>();
    assert(v == rv);
    assert(c == rc);
    assert(s == rs);
    assert(cls == rcls);
    ss.clear();
}

void tupOffsetTest()
{
    const int v1 = 100;
    const int v2 = 1000;
    const int offset1 = 10;
    const int offset2 = 100;
    ss << "100 1000";
    const auto [rv1, rv2] = scanner.tup<int, int>(offset1, offset2);
    assert(v1 - offset1 == rv1);
    assert(v2 - offset2 == rv2);
    ss.clear();
}

int main()
{
    valTest();
    valOffsetTest();
    vecTest();
    vecOffsetTest();
    vvecTest();
    vvecOffsetTest();
    tupTest();
    tupOffsetTest();
    std::cout << "Hello World\n";
    return 0;
}
