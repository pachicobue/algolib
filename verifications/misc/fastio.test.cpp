#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "misc/common.hpp"
#include "misc/fastio/printer.hpp"
#include "misc/fastio/scanner.hpp"
int main()
{
    const auto T = in.val<int>();
    for (int t : rep(T)) {
        const auto [A, B] = in.tup<i64, i64>();
        out.ln(A + B);
    }
    return 0;
}
