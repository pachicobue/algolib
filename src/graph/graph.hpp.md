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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/bcc.hpp
    title: src/graph/bcc.hpp
  - icon: ':warning:'
    path: src/graph/bellman_ford.hpp
    title: src/graph/bellman_ford.hpp
  - icon: ':warning:'
    path: src/graph/centroid_decomp.hpp
    title: src/graph/centroid_decomp.hpp
  - icon: ':warning:'
    path: src/graph/diameter.hpp
    title: src/graph/diameter.hpp
  - icon: ':warning:'
    path: src/graph/dijkstra.hpp
    title: src/graph/dijkstra.hpp
  - icon: ':warning:'
    path: src/graph/hld.hpp
    title: src/graph/hld.hpp
  - icon: ':warning:'
    path: src/graph/lca.hpp
    title: src/graph/lca.hpp
  - icon: ':warning:'
    path: src/graph/level_ancestor.hpp
    title: src/graph/level_ancestor.hpp
  - icon: ':warning:'
    path: src/graph/lowlink.hpp
    title: src/graph/lowlink.hpp
  - icon: ':warning:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  - icon: ':warning:'
    path: src/graph/top_sort.hpp
    title: src/graph/top_sort.hpp
  - icon: ':warning:'
    path: src/graph/warshall_floyd.hpp
    title: src/graph/warshall_floyd.hpp
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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename T = int>\n\
    class Graph\n{\n    struct Edge\n    {\n        Edge() = default;\n        Edge(int\
    \ t, T c) : to{t}, cost{c} {}\n        int to;\n        T cost;\n        operator\
    \ int() const\n        {\n            return to;\n        }\n    };\n\npublic:\n\
    \    Graph(int n) : m_v{n}, m_edges(n) {}\n    void addEdge(int u, int v, bool\
    \ bi = false)\n    {\n        assert(0 <= u and u < m_v);\n        assert(0 <=\
    \ v and v < m_v);\n        m_edges[u].emplace_back(v, 1);\n        if (bi) { m_edges[v].emplace_back(u,\
    \ T{1}); }\n    }\n    void addEdge(int u, int v, const T& c, bool bi = false)\n\
    \    {\n        assert(0 <= u and u < m_v);\n        assert(0 <= v and v < m_v);\n\
    \        m_edges[u].emplace_back(v, c);\n        if (bi) { m_edges[v].emplace_back(u,\
    \ c); }\n    }\n    const Vec<Edge>& operator[](const int u) const\n    {\n  \
    \      assert(0 <= u and u < m_v);\n        return m_edges[u];\n    }\n    Vec<Edge>&\
    \ operator[](const int u)\n    {\n        assert(0 <= u and u < m_v);\n      \
    \  return m_edges[u];\n    }\n    int v() const\n    {\n        return m_v;\n\
    \    }\n    friend Ostream& operator<<(Ostream& os, const Graph& g)\n    {\n \
    \       for (int u : rep(g.m_v)) {\n            for (const auto& e : g[u]) {\n\
    \                os << e.from << \"->\" << e.to << \"(\" << e.cost << \")\\n\"\
    ;\n            }\n        }\n        return os;\n    }\n    Vec<T> sizes(int root\
    \ = 0) const\n    {\n        const int N = v();\n        assert(0 <= root and\
    \ root < N);\n        Vec<T> ss(N, 1);\n        Fixpoint([&](auto dfs, int u,\
    \ int p) -> void {\n            for (const auto& [v, c] : m_edges[u]) {\n    \
    \            if (v == p) { continue; }\n                dfs(v, u);\n         \
    \       ss[v] += ss[u];\n            }\n        })(root, -1);\n        return\
    \ ss;\n    }\n    Vec<T> depths(int root = 0) const\n    {\n        const int\
    \ N = v();\n        assert(0 <= root and root < N);\n        Vec<T> ds(N, 0);\n\
    \        Fixpoint([&](auto dfs, int u, int p) -> void {\n            for (const\
    \ auto& [v, c] : m_edges[u]) {\n                if (v == p) { continue; }\n  \
    \              ds[v] = ds[u] + c;\n                dfs(v, u);\n            }\n\
    \        })(root, -1);\n        return ds;\n    }\n    Vec<int> parents(int root\
    \ = 0) const\n    {\n        const int N = v();\n        assert(0 <= root and\
    \ root < N);\n        Vec<int> ps(N, -1);\n        Fixpoint([&](auto dfs, int\
    \ u, int p) -> void {\n            for (const auto& [v, c] : m_edges[u]) {\n \
    \               if (v == p) { continue; }\n                ps[v] = u;\n      \
    \          dfs(v, u);\n            }\n        })(root, -1);\n        return ps;\n\
    \    }\n\nprivate:\n    int m_v;\n    Vec<Vec<Edge>> m_edges;\n};\n"
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
  path: src/graph/graph.hpp
  requiredBy:
  - src/graph/centroid_decomp.hpp
  - src/graph/top_sort.hpp
  - src/graph/level_ancestor.hpp
  - src/graph/warshall_floyd.hpp
  - src/graph/bellman_ford.hpp
  - src/graph/bcc.hpp
  - src/graph/dijkstra.hpp
  - src/graph/diameter.hpp
  - src/graph/scc.hpp
  - src/graph/hld.hpp
  - src/graph/lca.hpp
  - src/graph/lowlink.hpp
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/graph.hpp
layout: document
redirect_from:
- /library/src/graph/graph.hpp
- /library/src/graph/graph.hpp.html
title: src/graph/graph.hpp
---
