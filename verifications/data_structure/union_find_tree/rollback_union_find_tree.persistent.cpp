// verification-helper: PROBLEM https://judge.yosupo.jp/problem/persistent_unionfind
#include "data_structure/union_find_tree/rollback_union_find_tree.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main()
{
    const auto [N, Q] = in.tup<int, int>();
    Vec<int> ts(Q), ks(Q), us(Q), vs(Q);
    Vec<Vec<Pair<int, Pair<int, int>>>> g(Q + 1);
    Vec<Vec<int>> qss(Q + 1);
    for (int q : rep(Q)) {
        std::tie(ts[q], ks[q], us[q], vs[q]) = in.tup<int, int, int, int>(0, -1, 0, 0);
        if (ts[q] == 0) {
            g[ks[q]].push_back({q + 1, {us[q], vs[q]}});
        } else {
            qss[ks[q]].push_back(q);
        }
    }
    Vec<int> ans(Q, -1);
    RollbackUnionFindTree uf(N);
    Fix([&](auto self, int a) -> void {
        for (int q : qss[a]) { ans[q] = uf.same(us[q], vs[q]); }
        for (const auto& [b, e] : g[a]) {
            const auto [u, v] = e;
            uf.unite(u, v);
            self(b);
            uf.undo();
        }
    })(0);
    for (int q : rep(Q)) {
        if (ts[q] == 1) { out.ln(ans[q]); }
    }
    return 0;
}
