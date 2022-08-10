#define PROBLEM "https://yukicoder.me/problems/no/184"
#include "../../src/utility/printer.hpp"
#include "../../src/utility/scanner.hpp"
#include "../../src/linear/int_bases.hpp"

int main()
{
    const auto N = in.val<int>();
    IntBases bases;
    LOOP (N) {
        const auto a = in.val<u64>();
        bases.add(a);
    }
    out.ln(1_u64 << bases.rank());
    return 0;
}
