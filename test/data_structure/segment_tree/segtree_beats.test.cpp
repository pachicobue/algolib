// verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
#include "data_structure/segment_tree/segtree_beats.hpp"
#include <algorithm>
#include "internal.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

auto secondMin(i64 a1, i64 a2, i64 b1, i64 b2) -> i64 {
    return a1 == b1 ? std::min(a2, b2) : a2 < b1 ? a2
                                     : b2 < a1   ? b2
                                                 : std::max(a1, b1);
}
auto secondMax(i64 a1, i64 a2, i64 b1, i64 b2) -> i64 {
    return a1 == b1 ? std::max(a2, b2) : a2 > b1 ? a2
                                     : b2 > a1   ? b2
                                                 : std::min(a1, b1);
}
auto clamp(i64 x, i64 low, i64 hi) -> i64 {
    return std::min(hi, std::max(low, x));
}

struct T {
    Arr<i64, 2> mins; // 1st min, 2nd min
    Arr<i64, 2> maxs; // 1st max, 2nd max
    i64 sum;
    int size;
    int minnum, maxnum;
    bool failed;
};
auto e() -> T {
    return {
        { INF<i64>,  INF<i64>},
        {-INF<i64>, -INF<i64>},
        0_i64,
        0,
        0,
        0,
        false
    };
}
auto merge(const T& x1, const T& x2) -> T {
    const auto& [mins1, maxs1, sum1, size1, minnum1, maxnum1, failed1] = x1;
    const auto& [mins2, maxs2, sum2, size2, minnum2, maxnum2, failed2] = x2;
    Arr<i64, 2> nmins{INF<i64>, INF<i64>};
    Arr<i64, 2> nmaxs{-INF<i64>, -INF<i64>};
    nmins[0] = std::min(mins1[0], mins2[0]);
    nmins[1] = secondMin(mins1[0], mins1[1], mins2[0], mins2[1]);
    nmaxs[0] = std::max(maxs1[0], maxs2[0]);
    nmaxs[1] = secondMax(maxs1[0], maxs1[1], maxs2[0], maxs2[1]);
    const int nminnum = minnum1 * (nmins[0] == mins1[0]) + minnum2 * (nmins[0] == mins2[0]);
    const int nmaxnum = maxnum1 * (nmaxs[0] == maxs1[0]) + maxnum2 * (nmaxs[0] == maxs2[0]);
    return T{nmins, nmaxs, sum1 + sum2, size1 + size2, nminnum, nmaxnum, failed1 or failed2};
}

struct F // Clamp[low,hi] \circ Add[add]
{
    i64 low, hi;
    i64 add;
    friend bool operator==(const F& f1, const F& f2) {
        return f1.low == f2.low and f1.hi == f2.hi and f1.add == f2.add;
    }
};
auto id() -> F {
    return {-INF<i64>, INF<i64>, 0_i64};
}
auto compose(const F& f1, const F& f2) -> F {
    const auto& [low1, hi1, add1] = f1;
    const auto& [low2, hi2, add2] = f2;
    return F{std::max(low1, low2 + add1), clamp(hi2 + add1, low1, hi1), add1 + add2};
}

auto apply(const F& f, const T& x) -> T {
    const auto& [mins, maxs, sum, size, minnum, maxnum, failed] = x;
    const auto& [low, hi, add] = f;
    const i64 nmin = clamp(mins[0] + add, low, hi);
    const i64 nmax = clamp(maxs[0] + add, low, hi);
    if (nmin == nmax) { // 全部同じ値になる
        return T{
            {nmin,  INF<i64>},
            {nmax, -INF<i64>},
            nmin * size,
            size,
            size,
            size,
            false
        };
    }
    if (minnum + maxnum == size) { // mins[1] <= x <= maxs[1] の元が存在しない
        return T{
            {nmin, nmax},
            {nmax, nmin},
            nmin * minnum + nmax * maxnum,
            size,
            minnum,
            maxnum,
            false
        };
    }
    if (low <= mins[1] + add and maxs[1] + add <= hi) { // mins[1] <= x <= maxs[1] の元がClampの影響を受けない
        Arr<i64, 2> nmins = {nmin, mins[1] + add};
        Arr<i64, 2> nmaxs = {nmax, maxs[1] + add};
        const i64 midsum = (sum - mins[0] * minnum - maxs[0] * maxnum);
        const int midnum = size - minnum - maxnum;
        const i64 nsum = nmin * minnum + nmax * maxnum + (midsum + add * midnum);
        return T{nmins, nmaxs, nsum, size, minnum, maxnum, false};
    }
    auto nx = x;
    nx.failed = true;
    return nx;
}

auto failed(const T& x) -> bool {
    return x.failed;
}

int main() {
    const auto [N, Q] = in.tup<int, int>();
    const auto as = in.vec<i64>(N);
    SegBeats<T, e, merge, F, id, compose, apply, failed> seg(N);
    for (int i : rep(N)) {
        seg.set(i,
                {
                    {as[i],  INF<i64>},
                    {as[i], -INF<i64>},
                    as[i],
                    1,
                    1,
                    1,
                    false
        });
    }
    LOOP (Q) {
        const auto type = in.val<int>();
        if (type == 0) {
            const auto [l, r, b] = in.tup<int, int, i64>();
            seg.act(l, r, {-INF<i64>, b, 0_i64});
        } else if (type == 1) {
            const auto [l, r, b] = in.tup<int, int, i64>();
            seg.act(l, r, {b, INF<i64>, 0_i64});
        } else if (type == 2) {
            const auto [l, r, b] = in.tup<int, int, i64>();
            seg.act(l, r, {-INF<i64>, INF<i64>, b});
        } else {
            const auto [l, r] = in.tup<int, int>();
            out.ln(seg.fold(l, r).sum);
        }
    }
    return 0;
}
