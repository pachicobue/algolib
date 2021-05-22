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
    \ T>\nclass HLD\n{\n    using P = Pair<int, int>;\n\npublic:\n    HLD(Graph<T>&\
    \ g, int r = 0)\n        : m_v(g.v()),\n          m_ps(m_v, -1),\n          m_tops(m_v,\
    \ -1),\n          m_ords(m_v, -1),\n          m_ins(m_v, -1),\n          m_outs(m_v,\
    \ -1)\n    {\n        const int N = g.v();\n        Vec<int> szs(N, 1);\n    \
    \    Fixpoint([&](auto dfs, int u, int p) -> int {\n            m_ps[u] = p;\n\
    \            for (int v : g[u]) {\n                if (p == v) { continue; }\n\
    \                szs[u] += dfs(v, u);\n                if (szs[(int)g[u][0]] <\
    \ szs[v]) { std::swap(g[u][0], g[u][v]); }\n            }\n            return\
    \ szs[u];\n        })(r, -1);\n        m_tops[r] = r;\n        int index = 0;\n\
    \        Fixpoint([&](auto dfs, int u, int p) -> void {\n            m_ins[u]\
    \ = index++;\n            m_ords[m_ins[u]] = u;\n            for (int i : rep(g[u].size()))\
    \ {\n                const int v = g[u][i];\n                if (v == p) { continue;\
    \ }\n                if (i == 0) {\n                    m_tops[v] = m_tops[u];\n\
    \                } else {\n                    m_tops[v] = v;\n              \
    \  }\n                dfs(v, u);\n            }\n        })(r, -1);\n    }\n \
    \   int pos(int v) const\n    {\n        assert(0 <= v and v < m_v);\n       \
    \ return m_ins[v];\n    }\n    int at(int n) const\n    {\n        assert(0 <=\
    \ n and n < m_v);\n        return m_ords[n];\n    }\n    P sub(int v) const\n\
    \    {\n        assert(0 <= v and v < m_v);\n        return {m_ins[v], m_outs[v]};\n\
    \    }\n    Vec<P> path(int u, int v) const\n    {\n        assert(0 <= u and\
    \ u < m_v);\n        assert(0 <= v and v < m_v);\n        Vec<P> head, tail;\n\
    \        for (int pu = m_tops[u], pv = m_tops[v]; pu != pv;) {\n            if\
    \ (m_ins[pu] < m_ins[pv]) {\n                tail.push_back({m_ins[pv], m_ins[v]});\n\
    \                v = m_ps[pv];\n                pv = m_tops[v];\n            }\
    \ else {\n                head.push_back({m_ins[u], m_ins[pu]});\n           \
    \     u = m_ps[pu];\n                pu = m_tops[u];\n            }\n        }\n\
    \        head.push_back({m_ins[u], m_ins[v]});\n        reverseAll(tail);\n  \
    \      for (const auto& p : tail) {\n            head.push_back(p);\n        }\n\
    \        return head;\n    }\n\nprivate:\n    int m_v;\n    Vec<int> m_ps;\n \
    \   Vec<int> m_tops;\n    Vec<int> m_ords;\n    Vec<int> m_ins, m_outs;\n};\n"
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
  path: src/graph/hld.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/hld.hpp
layout: document
redirect_from:
- /library/src/graph/hld.hpp
- /library/src/graph/hld.hpp.html
title: src/graph/hld.hpp
---
