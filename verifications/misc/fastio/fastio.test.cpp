#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../../src/misc/common.hpp"
#include "../../../src/misc/fastio/printer.hpp"
#include "../../../src/misc/fastio/scanner.hpp"
int main()
{
    const auto T = in.val<int>();
    for (int t : rep(T)) {
        USE(t);
        const auto [A, B] = in.tup<i64, i64>();
        out.ln(A + B);
    }
    return 0;
}
