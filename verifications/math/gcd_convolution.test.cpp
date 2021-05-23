#define PROBLEM "https://yukicoder.me/problems/no/886"
#include "../../src/math/gcd_convolution.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/misc/fastio/printer.hpp"
#include "../../src/misc/fastio/scanner.hpp"
int main()
{
    using mint = modint_1000000007;
    const auto [H, W] = in.tup<int, int>();
    mint ans = mint(H) * (W - 1) + mint(H - 1) * W;
    Vec<mint> as(H), bs(W);
    for (int i : range(1, H)) {
        as[i] = H - i;
    }
    for (int i : range(1, W)) {
        bs[i] = W - i;
    }
    const auto cs = gcdConvolute(as, bs);
    ans += (cs.size() < 2 ? mint{0} : cs[1]) * 2;
    out.ln(ans.val());
    return 0;
}
