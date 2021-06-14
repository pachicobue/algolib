#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../src/string/z_algorithm.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"

int main()
{
    auto S = in.val<Str>();
    out.ln(z_algorithm(S.begin(), S.end()));
    return 0;
}
