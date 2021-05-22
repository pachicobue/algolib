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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename T>\nclass\
    \ MaxFlow\n{\n    struct Edge\n    {\n        int to;\n        T cap;\n      \
    \  T flow;\n        int rid;\n        Edge() = default;\n        Edge(int t, T\
    \ c, T f, int r) : to{t}, cap{c}, flow{f}, rid{r} {}\n        T resCap() const\n\
    \        {\n            return cap - flow;\n        }\n    };\n\npublic:\n   \
    \ MaxFlow(int n) : m_v(n), m_ds(n, -1)\n    {\n        m_is[0].resize(n);\n  \
    \      m_is[1].resize(n);\n        m_gs[0].resize(n);\n        m_gs[1].resize(n);\n\
    \    }\n    void addEdge(int from, int to, T cap)\n    {\n        assert(0 <=\
    \ from and from < m_v);\n        assert(0 <= to and to < m_v);\n        assert(0\
    \ <= cap);\n        int id = m_gs[0][from].size();\n        int rid = m_gs[1][to].size();\n\
    \        m_gs[0][from].emplace_back(to, cap, 0);\n        m_gs[1][to].emplace_back(from,\
    \ cap, cap);\n        m_es.emplace_back(from, id);\n    }\n    const Edge& edge(int\
    \ i) const\n    {\n        const auto& [u, id] = m_es[i];\n        return m_gs[0][u][id];\n\
    \    }\n    T maxFlow(int s, int t, T max_flow = INF<T>)\n    {\n        auto\
    \ bfs = [&]() {\n            fillAll(m_ds, -1);\n            Queue<int> q;\n \
    \           m_ds[s] = 0, q.push(s);\n            while (not q.empty()) {\n   \
    \             const int u = q.front();\n                q.pop();\n           \
    \     for (int l : rep(2)) {\n                    for (const auto& e : m_gs[l][u])\
    \ {\n                        if (e.resCap() > 0 and m_ds[e.to] == -1) {\n    \
    \                        m_ds[e.to] = m_ds[u] + 1;\n                         \
    \   q.push(e.to);\n                        }\n                    }\n        \
    \        }\n            }\n        };\n        auto dfs = Fixpoint([&](auto dfs,\
    \ int u, T fmax) -> T {\n            if (u == t) { return fmax; }\n          \
    \  for (int l : rep(2)) {\n                for (int& i = m_is[l][u]; i < (int)m_gs[l][u].size();\
    \ i++) {\n                    auto& e = m_gs[l][u][i];\n                    if\
    \ (e.resCap() > 0 and m_ds[u] < m_ds[e.to]) {\n                        const T\
    \ d = dfs(e.to, std::min(fmax, e.resCap()));\n                        if (d >\
    \ 0) {\n                            e.flow += d;\n                           \
    \ m_gs[1 - l][e.to][e.rid].flow -= d;\n                            return d;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n            return 0;\n        });\n        T flow = 0;\n        while\
    \ (flow < max_flow) {\n            bfs();\n            if (m_ds[t] == -1) { return\
    \ flow; }\n            for (int l : rep(2)) {\n                fillAll(m_is[l],\
    \ 0);\n            }\n            while (true) {\n                T f = dfs(s,\
    \ max_flow - flow);\n                if (f == 0) { break; }\n                flow\
    \ += f;\n            }\n        }\n        return flow;\n    }\n    Vec<Edge>&\
    \ operator[](int i)\n    {\n        assert(0 <= i and i < m_v);\n        return\
    \ m_gs[0][i];\n    }\n    const Vec<Edge>& operator[](int i) const\n    {\n  \
    \      assert(0 <= i and i < m_v);\n        return m_gs[0][i];\n    }\n    int\
    \ v() const\n    {\n        return m_v;\n    }\n    friend Ostream& operator<<(Ostream&\
    \ os, const MaxFlow& mf)\n    {\n        const int N = mf.v();\n        os <<\
    \ \"[\\n\";\n        for (int u : rep(N)) {\n            for (const auto& e :\
    \ mf[u]) {\n                const int v = e.to;\n                const T cap =\
    \ e.cap, flow = e.flow;\n                os << u << \"->\" << v << \" [\" << flow\
    \ << \"/\" << cap << \"]\\n\";\n            }\n        }\n        return (os <<\
    \ \"]\\n\");\n    }\n\nprivate:\n    int m_v;\n    Vec<int> m_ds;\n    Arr<Vec<int>,\
    \ 2> m_is;\n    Vec<Pair<int, int>> m_es;\n    Arr<Vec<Vec<Edge>>, 2> m_gs;  //\
    \ (\u5143\u306E\u30B0\u30E9\u30D5,\u9006\u8FBA\u306E\u30B0\u30E9\u30D5)\n};\n"
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
  path: src/flow/max_flow.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/max_flow.hpp
layout: document
redirect_from:
- /library/src/flow/max_flow.hpp
- /library/src/flow/max_flow.hpp.html
title: src/flow/max_flow.hpp
---
