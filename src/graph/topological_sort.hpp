#pragma once
#include <optional>
#include "../internal.hpp"
#include "graph.hpp"
/**
 * @brief トポロジカルソート
 *
 * @param g 有効グラフ
 * @return Opt<Vec<int>> トポロジカル順に頂点番号をソートした列 (不可能な場合は std::nullopt)
 */
template <typename T> auto topologicalSort(const Graph<T>& g) -> Opt<Vec<int>> {
    const int N = g.V();
    Vec<int> ans;
    Vec<int> used(N, 0);
    auto dfs = Fix([&](auto self, int s) -> bool {
        if (used[s] == 1) {
            return false;
        } else if (used[s] == 0) {
            used[s] = 1;
            for (int to : g[s]) {
                if (not self(to)) { return false; }
            }
            used[s] = 2;
            ans.push_back(s);
        }
        return true;
    });
    for (int i : rep(N)) {
        if (not dfs(i)) { return std::nullopt; }
    }
    seqReverse(ans);
    return ans;
}
