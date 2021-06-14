#define PROBLEM "https://yukicoder.me/problems/no/541"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/linear/matrix.hpp"

int main()
{
    using mint = modint_1000000007;
    const auto N = in.val<i64>();
    Mat<mint> mat{{{1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
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
