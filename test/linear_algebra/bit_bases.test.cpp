// verification-helper: PROBLEM https://yukicoder.me/problems/no/184
#include "linear_algebra/bit_bases.hpp"
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main() {
    const auto N = in.val<int>();
    BitBases<64> bases;
    LOOP (N) {
        const auto a = in.val<u64>();
        bases.add(a);
    }
    out.ln(1_u64 << bases.rank());
    return 0;
}
