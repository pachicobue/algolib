// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint.hpp"
using mint = modint_dynamic<0>;
constexpr u64 MOD = 1000000007;
void test() {
    assert(mint::mod() == MOD);
}
int main() {
    mint::setMod(MOD);
    test();
    return 0;
}
