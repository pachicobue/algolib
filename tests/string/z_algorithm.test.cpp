#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../src/string/z_algorithm.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"

int main()
{
    auto S = in.val<Str>();
    out.ln(z_algorithm(S));
    return 0;
}
