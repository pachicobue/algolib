#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../src/string/z_algorithm.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"

int main()
{
    auto S = in.val<Str>();
    out.ln(z_algorithm(S));
    return 0;
}
