#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../src/misc/common.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
int main()
{
    const auto T = in.val<int>();
    for (int t = 0; t < T; t++) {
        const auto [A, B] = in.tup<i64, i64>();
        out.ln(A + B);
    }
    return 0;
}
