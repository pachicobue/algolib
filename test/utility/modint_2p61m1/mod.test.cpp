// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint_2p61m1.hpp"
using mint = modint_2p61m1;
constexpr u64 MOD = (1_u64 << 61) - 1;
void test() {
    assert(mint::mod() == MOD);
}
int main() {
    test();
    return 0;
}
