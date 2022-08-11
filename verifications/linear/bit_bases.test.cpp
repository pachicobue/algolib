#define PROBLEM "https://yukicoder.me/problems/no/184"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"
#include "../../src/linear/bit_bases.hpp"

int main()
{
    const auto N = in.val<int>();
    BitBases<64> bases;
    LOOP (N) {
        const auto a = in.val<u64>();
        bases.add(a);
    }
    out.ln(1_u64 << bases.rank());
    return 0;
}
