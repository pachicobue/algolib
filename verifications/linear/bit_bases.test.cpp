#define PROBLEM "https://yukicoder.me/problems/no/184"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
#include "../../src/linear/bit_bases.hpp"

int main()
{
    const auto N = in.val<int>();
    BitBases<64> bases;
    for (int i : rep(N)) {
        USE(i);
        const auto a = in.val<u64>();
        bases.add(a);
    }
    out.ln(1_u64 << bases.rank());
    return 0;
}
