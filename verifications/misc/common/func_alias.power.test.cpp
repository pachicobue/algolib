#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "../../../src/misc/common.hpp"
#include "../../../src/misc/printer.hpp"
#include "../../../src/misc/scanner.hpp"

constexpr i64 mod = 1000000007;
struct mint
{
    mint() = default;
    mint(i64 v_) : v{v_} {}
    friend mint operator+(const mint& m1, const mint& m2)
    {
        return mint(m1.v + m2.v);
    }
    friend mint operator*(const mint& m1, const mint& m2)
    {
        return mint(m1.v * m2.v % mod);
    }
    friend mint& operator+=(mint& m1, const mint& m2)
    {
        m1 = m1 + m2;
        return m1;
    }
    friend mint& operator*=(mint& m1, const mint& m2)
    {
        m1 = m1 * m2;
        return m1;
    }
    i64 v = 0;
};

int main()
{
    const auto [m, n] = in.tup<i64, i64>();
    mint M{m};
    const mint ans = power(M, n);
    out.ln(ans.v);
    return 0;
}
