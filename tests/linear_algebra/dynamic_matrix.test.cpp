#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "../../src/linear_algebra/dynamic_matrix.hpp"
#include "../../src/util/nd_vec.hpp"
#include "../../src/util/modint.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"

int main()
{
    using mint = modint_998244353;
    const auto [N, M, K] = in.tup<int, int, int>();
    DynamicMatrix<mint> A(N, M);
    for (int i : rep(N)) {
        for (int j : rep(M)) { A[i][j] = in.val<mint>(); }
    }
    DynamicMatrix<mint> B(M, K);
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
