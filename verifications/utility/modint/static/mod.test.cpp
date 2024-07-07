// verification-helper: UNITTEST
#include <cassert>
#include "internal.hpp"
#include "utility/modint.hpp"
constexpr u64 MOD = 998244353;
using mint = modint<MOD>;
void test() { assert(mint::mod() == MOD); }
int main() {
    test();
    return 0;
}
