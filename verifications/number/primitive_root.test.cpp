// verification-helper: PROBLEM https://judge.yosupo.jp/problem/primitive_root
#include "number/primitive_root.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main()
{
    const auto Q = in.val<int>();
    LOOP (Q) {
        const auto P = in.val<u64>();
        out.ln(primitiveRoot(P));
    }
    return 0;
}
