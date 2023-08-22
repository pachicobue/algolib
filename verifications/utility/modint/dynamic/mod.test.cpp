// verification-helper: UNITTEST
#include "utility/modint.hpp"
#include "utility/rng.hpp"
using mint        = modint_dynamic<0>;
constexpr u64 MOD = 1000000007;
void test() { assert(mint::mod() == MOD); }
int main()
{
    mint::setMod(MOD);
    test();
    return 0;
}
