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
  code: "#pragma once\n#include \"../misc/common.hpp\"\n#include \"graph.hpp\"\nclass\
    \ LA\n{\npublic:\n    template<typename T>\n    LA(const Graph<T>& g, int r =\
    \ 0) : m_v(g.v()), m_ds(m_v, 0), m_ps(m_v)\n    {\n        Fixpoint([&](auto dfs,\
    \ int u, int p) -> void {\n            for (int k = 1; (1 << k) <= m_ds[u]; k++)\
    \ {\n                m_ps[u].push_back(m_ps[m_ps[u][k - 1]][k - 1]);\n       \
    \     }\n            for (int v : g[u]) {\n                m_ds[v] = m_ds[u] +\
    \ 1;\n                m_ps[v].push_back(u);\n                dfs(v, u);\n    \
    \        }\n        })(r, -1);\n    };\n    int lca(int u, int v) const\n    {\n\
    \        assert(0 <= u and u < m_v);\n        assert(0 <= v and v < m_v);\n  \
    \      if (m_ds[u] > m_ds[v]) { std::swap(u, v); }\n        v = (*this)(v, m_ds[v]\
    \ - m_ds[u]);\n        if (u == v) { return u; }\n        while (true) {\n   \
    \         if (m_ps[u][0] == m_ps[v][0]) { return m_ps[u][0]; }\n            for\
    \ (int i = m_ps[u].size() - 1; i >= 0; i--) {\n                const int nu =\
    \ m_ps[u][i], nv = m_ps[v][i];\n                if (nu != nv) {\n            \
    \        u = nu, v = nv;\n                    break;\n                }\n    \
    \        }\n        }\n    }\n    int operator()(int v, int d) const\n    {\n\
    \        assert(0 <= v and v < m_v);\n        for (int k = (int)log2p1(d); k >=\
    \ 0; k--) {\n            if (btest(d, k)) { v = m_ps[v][k]; }\n        }\n   \
    \     return v;\n    }\n\nprivate:\n    int m_v;\n    Vec<int> m_ds;\n    Vec<Vec<int>>\
    \ m_ps;\n};\n"
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
  path: src/graph/level_ancestor.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/level_ancestor.hpp
layout: document
redirect_from:
- /library/src/graph/level_ancestor.hpp
- /library/src/graph/level_ancestor.hpp.html
title: src/graph/level_ancestor.hpp
---
