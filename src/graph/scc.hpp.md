---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/graph/graph.hpp
    title: src/graph/graph.hpp
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
  code: "#pragma once\n#include \"../misc/common.hpp\"\n#include \"graph.hpp\"\ntemplate<typename\
    \ T>\nclass sc_comp\n{\npublic:\n    sc_comp(const Graph<T>& g) : m_v(g.v()),\
    \ m_cs(m_v, -1)\n    {\n        const int N = g.v();\n        Graph<T> rg(N);\n\
    \        for (int u : rep(N)) {\n            for (const auto& [v, cost] : g[i])\
    \ {\n                rg.add_edge(v, u, cost);\n            }\n        }\n    \
    \    Vec<int> st;\n        Vec<bool> used(N, false);\n        auto dfs = Fixpoint([&](auto\
    \ dfs, int u) -> void {\n            used[u] = true;\n            for (int v :\
    \ g[u]) {\n                if (not used[v]) { dfs(v); }\n            }\n     \
    \       st.push_back(u);\n        });\n        auto rdfs = Fixpoint([&](auto dfs,\
    \ int v) -> void {\n            m_cs[v] = m_cnum;\n            for (int u : rg[v])\
    \ {\n                if (m_cs[u] != -1) { continue; }\n                dfs(u);\n\
    \            }\n        });\n        for (int i : rep(N)) {\n            if (used[i])\
    \ { continue; }\n            dfs(i);\n        }\n        reverseAll(st);\n   \
    \     for (int i : st) {\n            if (m_cs[i] != -1) { continue; }\n     \
    \       rdfs(i);\n            m_cnum++;\n        }\n    }\n    int operator[](int\
    \ v) const\n    {\n        assert(0 <= v and v < m_v);\n        return m_cs[v];\n\
    \    }\n    int cnum() const\n    {\n        return m_cnum;\n    }\n    Vec<Vec<int>>\
    \ groups() const\n    {\n        Vec<Vec<int>> iss(m_v);\n        for (const int\
    \ i : rep(m_v)) {\n            iss[m_cs[i]].push_back(i);\n        }\n       \
    \ return iss;\n    }\n\nprivate:\n    int m_v;\n    int m_cnum = 0;\n    Vec<int>\
    \ m_cs;\n};\n"
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
  - src/graph/graph.hpp
  isVerificationFile: false
  path: src/graph/scc.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/scc.hpp
layout: document
redirect_from:
- /library/src/graph/scc.hpp
- /library/src/graph/scc.hpp.html
title: src/graph/scc.hpp
---
