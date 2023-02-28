// verification-helper: PROBLEM https://yukicoder.me/problems/no/541
#include "linear_algebra/static_matrix.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main()
{
    using mint = modint_1000000007;
    const auto N = in.val<i64>();
    StaticMatrix<mint, 10, 10> mat{{{1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
                                    {0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
                                    {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                                    {0, 0, 1, 1, 0, 0, 1, 0, 1, 1},
                                    {0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
                                    {0, 0, 1, 0, 0, 1, 0, 1, 1, 1},
                                    {0, 0, 0, 1, 1, 0, 1, 1, 1, 1},
                                    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                                    {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}}};
    out.ln(mat.pow(N + 1)[0][9]);
    return 0;
}
