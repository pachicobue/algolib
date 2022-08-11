#define PROBLEM "https://yukicoder.me/problems/no/541"
#include "../../src/util/fastio/printer.hpp"
#include "../../src/util/fastio/scanner.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/linear/array_matrix.hpp"

int main()
{
    using mint = modint_1000000007;
    const auto N = in.val<i64>();
    ArrMat<mint, 10, 10> mat{{{1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
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
