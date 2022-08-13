#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../../../src/ds/hashmap/intdict.hpp"
#include "../../../src/util/fastio/printer.hpp"
#include "../../../src/util/fastio/scanner.hpp"
int main()
{
    const auto Q = in.val<int>();
    IntDict<u64, u64> dict(Q);
    LOOP (Q) {
        const auto t = in.val<int>();
        if (t == 0) {
            const auto [k, v] = in.tup<u64, u64>();
            dict[k] = v;
        } else {
            const auto k = in.val<u64>();
            out.ln(dict[k]);
        }
    }
    return 0;
}
