#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
#include "../../src/util/nd_vec.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/linear/matrix.hpp"

int main()
{
    using mint = modint_998244353;
    const auto [N, M, K] = in.tup<int, int, int>();
    Mat<mint> A(N, M);
    for (int i : rep(N)) {
        for (int j : rep(M)) { A[i][j] = in.val<mint>(); }
    }
    Mat<mint> B(M, K);
    for (int i : rep(M)) {
        for (int j : rep(K)) { B[i][j] = in.val<mint>(); }
    }
    const auto C = A * B;
    auto ans = ndVec<mint>({N, K});
    for (int i : rep(N)) {
        for (int k : rep(K)) { ans[i][k] = C[i][k]; }
    }
    out.ln(ans);
    return 0;
}
