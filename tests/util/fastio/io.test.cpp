#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../../src/common.hpp"
#include "../../../src/util/fastio/printer.hpp"
#include "../../../src/util/fastio/scanner.hpp"

int main()
{
    const auto T = in.val<int>();
    LOOP (T) {
        const auto [A, B] = in.tup<i64, i64>();
        out.ln(A + B);
    }

    return 0;
}
