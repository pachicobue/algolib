// verification-helper: PROBLEM https://judge.yosupo.jp/problem/many_aplusb
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main() {
    const auto T = in.val<int>();
    LOOP (T) {
        const auto [A, B] = in.tup<i64, i64>();
        out.ln(A + B);
    }

    return 0;
}
