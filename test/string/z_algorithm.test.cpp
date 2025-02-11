// verification-helper: PROBLEM https://judge.yosupo.jp/problem/zalgorithm
#include "string/z_algorithm.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main() {
    auto S = in.val<Str>();
    out.ln(z_algorithm(S));
    return 0;
}
