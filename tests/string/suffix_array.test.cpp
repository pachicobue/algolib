// verification-helper: PROBLEM https://judge.yosupo.jp/problem/suffixarray
#include "string/suffix_array.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main()
{
    const auto S = in.val<Str>();
    const auto SA = suffixArray(S);
    out.ln(SA);
    return 0;
}
