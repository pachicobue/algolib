#define PROBLEM "https://yukicoder.me/problems/no/541"
#include "../../src/linear_algebra/static_matrix.hpp"
#include "../../src/util/modint.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"

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
