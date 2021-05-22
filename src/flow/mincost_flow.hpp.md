---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/misc/common.hpp
    title: src/misc/common.hpp
  - icon: ':warning:'
    path: src/misc/common/bit_ops.hpp
    title: src/misc/common/bit_ops.hpp
  - icon: ':warning:'
    path: src/misc/common/constants.hpp
    title: src/misc/common/constants.hpp
  - icon: ':warning:'
    path: src/misc/common/fixpoint.hpp
    title: src/misc/common/fixpoint.hpp
  - icon: ':warning:'
    path: src/misc/common/func_alias.hpp
    title: src/misc/common/func_alias.hpp
  - icon: ':warning:'
    path: src/misc/common/nd_vec.hpp
    title: src/misc/common/nd_vec.hpp
  - icon: ':warning:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
  - icon: ':warning:'
    path: src/misc/common/range.hpp
    title: src/misc/common/range.hpp
  - icon: ':warning:'
    path: src/misc/common/rng.hpp
    title: src/misc/common/rng.hpp
  - icon: ':warning:'
    path: src/misc/common/show.hpp
    title: src/misc/common/show.hpp
  - icon: ':warning:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  - icon: ':warning:'
    path: src/misc/common/xoshiro.hpp
    title: src/misc/common/xoshiro.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/misc/common/show.hpp: line 5: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename Cap, typename\
    \ Cost>\nstruct MinCostBFlow\n{\n    struct Edge\n    {\n        int from, to;\n\
    \        Cap cap;\n        Cap flow;\n        Cost cost;\n        int rid;\n \
    \       Edge() = default;\n        Edge(int from_, int to_, Cap cap_, Cap flow_,\
    \ Cost cost_, int rid_)\n            = default;\n    };\n    Cap resCap(const\
    \ Edge& e) const\n    {\n        return e.cap - e.flow;\n    }\n    Cost resCost(const\
    \ Edge& e) const\n    {\n        return e.cost + m_pots[e.from] - m_pots[e.to];\n\
    \    }\n\npublic:\n    MinCostBFlow(int n) : m_v(n), m_bs(n, 0), m_ds(n), m_pots(n,\
    \ 0)\n    {\n        m_gs[0].resize(n);\n        m_gs[1].resize(n);\n    }\n \
    \   void addEdge(int from, int to, Cap cap, Cost cost)\n    {\n        addEdge(from,\
    \ to, 0, cap, cost);\n    }\n    void addEdge(int from, int to, Cap lower, Cap\
    \ upper, Cost cost)\n    {\n        assert(0 <= from and from < m_v);\n      \
    \  assert(0 <= to and to < m_v);\n        assert(lower <= upper);\n        const\
    \ int id = m_gs[0][from].size();\n        const int rid = m_gs[1][to].size();\n\
    \        m_gs[0][from].emplace_back(from, to, upper, 0, cost, rid);\n        m_gs[1][to].emplace_back(to,\
    \ from, -lower, 0, -cost, id);\n        m_es.emplace_back(from, id);\n    }\n\
    \    void addSupply(int v, Cap b)\n    {\n        m_bs[v] += b;\n    }\n    void\
    \ addDemand(int v, Cap b)\n    {\n        m_bs[v] -= b;\n    }\n    template<typename\
    \ Result = Cost>\n    Pair<bool, Result> flow()\n    {\n        for (int l : rep(2))\
    \ {\n            for (int u : rep(m_v)) {\n                for (auto& e : m_gs[l][u])\
    \ {\n                    const Cap cap = e.resCap();\n                    if (cap\
    \ < 0) {\n                        const int v = e.to;\n                      \
    \  auto& re = m_gs[1 - l][v][e.rid];\n                        e.flow += cap, re.flow\
    \ -= cap;\n                        m_bs[u] -= cap, m_bs[v] += cap;\n         \
    \           }\n                }\n            }\n        }\n        Cap maxcap\
    \ = 1;\n        for (int l : rep(2)) {\n            for (int u : rep(m_v)) {\n\
    \                for (const auto& e : m_gs[l][u]) {\n                    chmax(maxcap,\
    \ e.resCap());\n                }\n            }\n        }\n        for (Cap\
    \ delta = floor2(maxcap); delta > 0; delta >>= 1) {\n            preCalc(delta);\n\
    \            while (dual(delta)) {\n                primal(delta);\n         \
    \   }\n        }\n        const bool feasible = m_excs.empty() and m_defs.empty();\n\
    \        Result ans = 0;\n        for (int u : rep(m_v)) {\n            for (const\
    \ auto& e : m_gs[0][u]) {\n                ans += (Result)e.flow * e.cost;\n \
    \           }\n        }\n        return {feasible, ans};\n    }\n    Vec<Edge>&\
    \ operator[](int i)\n    {\n        assert(0 <= i and i < m_v);\n        return\
    \ m_gs[0][i];\n    }\n    const Vec<Edge>& operator[](int i) const\n    {\n  \
    \      assert(0 <= i and i < m_v);\n        return m_gs[0][i];\n    }\n    const\
    \ Edge& edge(int i) const\n    {\n        const auto& [u, id] = m_es[i];\n   \
    \     return m_gs[0][u][id];\n    }\n    Cap potential(int i) const\n    {\n \
    \       return m_pots[i];\n    }\n    int v() const\n    {\n        return m_v;\n\
    \    }\n    friend Ostream& operator<<(Ostream& os, const MinCostBFlow& mcf)\n\
    \    {\n        os << \"[\\n\";\n        for (int u : rep(mcf.v())) {\n      \
    \      for (const auto& e : mcf[u]) {\n                const int v = e.to;\n \
    \               const Cap cap = e.cap, flow = e.flow;\n                const Cost\
    \ cost = e.cost;\n                os << u << \"->\" << v << \" [\" << flow <<\
    \ \"/\" << cap\n                   << \",cost=\" << cost << \"]\\n\";\n      \
    \      }\n        }\n        return (os << \"]\\n\");\n    }\n\nprivate:\n   \
    \ void preCalc(Cap delta)\n    {\n        m_excs.clear(), m_defs.clear();\n  \
    \      for (int l : rep(2)) {\n            for (int u : rep(m_v)) {\n        \
    \        for (auto& e : m_gs[l][u]) {\n                    const int v = e.to;\n\
    \                    const Cap cap = e.resCap();\n                    const Cost\
    \ cost = resCost(u, v, e);\n                    if (delta <= cap and cost < 0)\
    \ {\n                        auto& re = m_gs[1 - l][v][e.rid];\n             \
    \           e.flow += cap, re.flow -= cap;\n                        m_bs[u] -=\
    \ cap, m_bs[v] += cap;\n                    }\n                }\n           \
    \ }\n        }\n        for (int v : rep(m_v)) {\n            if (m_bs[v] > 0)\
    \ {\n                m_excs.push_back(v);\n            } else if (m_bs[v] < 0)\
    \ {\n                m_defs.push_back(v);\n            }\n        }\n    }\n \
    \   void primal(Cap delta)\n    {\n        Vec<bool> used(m_v, false);\n     \
    \   auto dfs = Fixpoint([&](auto dfs, int v, Cap fmax) -> Cap {\n            if\
    \ (fmax < delta) { return 0; }\n            used[v] = true;\n            if (m_bs[v]\
    \ > 0) {\n                chmin(fmax, m_bs[v]);\n                m_bs[v] -= fmax;\n\
    \                return fmax;\n            }\n            for (int l : rep(2))\
    \ {\n                for (auto& re : m_gs[l][v]) {\n                    const\
    \ int u = re.to;\n                    if (used[u]) { continue; }\n           \
    \         auto& e = m_gs[1 - l][u][re.rid];\n                    const Cost cost\
    \ = resCost(u, v, e);\n                    if (e.resCap() > 0 and cost == 0) {\n\
    \                        chmin(fmax, e.resCap());\n                        const\
    \ Cap f = dfs(u, fmax);\n                        if (f >= delta) {\n         \
    \                   e.flow += f, re.flow -= f;\n                            return\
    \ f;\n                        }\n                    }\n                }\n  \
    \          }\n            return 0;\n        });\n        for (int t : m_defs)\
    \ {\n            if (m_ds[t] > m_dmax) { continue; }\n            const auto&\
    \ f = dfs(t, -m_bs[t]);\n            if (f >= delta) {\n                m_bs[t]\
    \ += f;\n                SHOW(delta, f);\n            }\n        }\n    }\n  \
    \  bool dual(Cap delta)\n    {\n        fillAll(m_ds, INF<Cost>);\n        eraseIf(m_excs,\
    \ [&](int v) { return m_bs[v] < delta; });\n        eraseIf(m_defs, [&](int v)\
    \ { return m_bs[v] > -delta; });\n        for (int v : m_excs) {\n           \
    \ m_ds[v] = 0, m_pq.emplace(m_ds[v], v);\n        }\n        int def_count = 0;\n\
    \        m_dmax = 0;\n        while (not m_pq.empty()) {\n            const auto\
    \ [d, u] = m_pq.top();\n            m_pq.pop();\n            if (m_ds[u] < d)\
    \ { continue; }\n            chmax(m_dmax, d);\n            if (m_bs[u] <= -delta)\
    \ { def_count++; }\n            for (int l : rep(2)) {\n                for (const\
    \ auto& e : m_gs[l][u]) {\n                    const int v = e.to;\n         \
    \           const Cap nd = d + resCost(u, v, e);\n                    if (e.resCap()\
    \ >= delta) {\n                        if (m_ds[v] <= nd) { continue; }\n    \
    \                    m_ds[v] = nd, m_pq.emplace(nd, v);\n                    }\n\
    \                }\n            }\n        }\n        for (int i : rep(m_v)) {\n\
    \            m_pots[i] += std::min(m_dmax, m_ds[i]);\n        }\n        return\
    \ def_count > 0;\n    }\n    int m_v;\n    Vec<Cap> m_bs;\n    Vec<Cost> m_ds;\n\
    \    Vec<int> m_excs, m_defs;\n    Vec<Cost> m_pots;\n    MinHeap<Pair<Cost, int>>\
    \ m_pq;\n    Cap m_dmax;\n    Vec<Pair<int, int>> m_es;\n    Arr<Vec<Vec<Edge>>,\
    \ 2> m_gs;  // (\u5143\u306E\u30B0\u30E9\u30D5,\u9006\u8FBA\u306E\u30B0\u30E9\u30D5\
    )\n};\n"
  dependsOn:
  - src/misc/common.hpp
  - src/misc/common/type_alias.hpp
  - src/misc/common/constants.hpp
  - src/misc/common/func_alias.hpp
  - src/misc/common/show.hpp
  - src/misc/common/print/int128_t.hpp
  - src/misc/common/bit_ops.hpp
  - src/misc/common/fixpoint.hpp
  - src/misc/common/nd_vec.hpp
  - src/misc/common/range.hpp
  - src/misc/common/rng.hpp
  - src/misc/common/xoshiro.hpp
  isVerificationFile: false
  path: src/flow/mincost_flow.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/mincost_flow.hpp
layout: document
redirect_from:
- /library/src/flow/mincost_flow.hpp
- /library/src/flow/mincost_flow.hpp.html
title: src/flow/mincost_flow.hpp
---
