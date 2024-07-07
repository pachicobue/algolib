// verification-helper: PROBLEM https://judge.yosupo.jp/problem/enumerate_palindromes
#include "string/manacher.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main() {
    auto S = in.val<Str>();
    const int N = S.size();
    Str T;
    for (int i : rep(N)) {
        T.push_back('$');
        T.push_back(S[i]);
    }
    T.push_back('$');
    auto rs = manacher(T);
    Vec<int> ans;
    for (int i : irange(1, 2 * N)) { ans.push_back(rs[i] - 1); }
    out.ln(ans);
    return 0;
}
