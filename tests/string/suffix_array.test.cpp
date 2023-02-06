#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "../../src/string/suffix_array.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"

int main()
{
    const auto S = in.val<Str>();
    const auto SA = suffixArray(S);
    out.ln(SA);
    return 0;
}
