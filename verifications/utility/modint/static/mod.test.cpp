// verification-helper: UNITTEST
#include "utility/modint.hpp"
#include "utility/rng.hpp"
constexpr u64 MOD = 998244353;
using mint        = modint<MOD>;
void test() { assert(mint::mod() == MOD); }
int main()
{
    test();
    return 0;
}
