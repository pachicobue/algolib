// verification-helper: PROBLEM https://judge.yosupo.jp/problem/enumerate_quotients
#include <cassert>
#include "internal.hpp"
#include "utility/floor_divs.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto X = in.val<i64>();
    FloorDivs fds{X};
    out.ln(fds.quotNum());
    out.ln(fds.divs());
    return 0;
}
