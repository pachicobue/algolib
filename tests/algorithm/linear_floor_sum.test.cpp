#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#include "../../src/algorithm/linear_floor_sum.hpp"
#include "../../src/util/printer.hpp"
#include "../../src/util/scanner.hpp"
int main()
{
    const auto T = in.val<int>();
    LOOP (T) {
        const auto [N, M, A, B] = in.tup<i64, i64, i64, i64>();
        out.ln(linearFloorSum(N, A, B, M));
    }
    return 0;
}
