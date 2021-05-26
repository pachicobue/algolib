#pragma once
#include "../misc/common.hpp"
#include "graph.hpp"
template<typename T>
Pair<bool, Vec<int>> topSort(const Graph<T>& g)
{
    const int N = g.v();
    Vec<int> ans;
    Vec<int> used(N, 0);
    auto dfs = Fix([&](auto dfs, int s) -> bool {
        if (used[s] == 1) {
            return false;
        } else if (used[s] == 0) {
            used[s] = 1;
            for (int to : g[s]) {
                if (not dfs(to)) { return false; }
            }
            used[s] = 2;
            ans.push_back(s);
        }
        return true;
    });
    for (int i : rep(N)) {
        if (not dfs(i)) { return {false, ans}; }
    }
    reverseAll(ans);
    return {true, ans};
}
