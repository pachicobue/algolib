#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"
#include "../../src/utility/int_nthroot.hpp"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"

int main()
{
    const auto T = in.val<int>();
    LOOP (T) {
        const auto [A, K] = in.tup<u64, int>();
        out.ln(intNthRoot(A, K));
    }
}
