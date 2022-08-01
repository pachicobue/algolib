#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../../src/ds/intdict.hpp"
#include "../../src/misc/printer.hpp"
#include "../../src/misc/scanner.hpp"
int main()
{
    IntDict<u64, u64> dict;
    const auto Q = in.val<int>();
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
