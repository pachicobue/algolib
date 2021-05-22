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
    \ T>\nclass CentroidDecomp\n{\npublic:\n    CentroidDecomp(const Graph<T>& g)\n\
    \        : m_g{g},\n          m_cs(m_g.v()),\n          m_sub_calced{false},\n\
    \          m_subss(m_g.v()),\n          m_subsss(m_g.v())\n    {\n        const\
    \ int N = m_g.v();\n        Vec<int> szs(N, 1);\n        Vec<bool> used(N, false);\n\
    \        auto sizeDfs = Fixpoint([&](auto dfs, int s, int p) -> int {\n      \
    \      szs[s] = 1;\n            for (int to : m_g[s]) {\n                if (to\
    \ == p or used[to]) { continue; }\n                szs[s] += dfs(to, s);\n   \
    \         }\n        });\n        auto getCentor = Fixpoint([&](auto dfs, int\
    \ s, int p, int tot) -> int {\n            for (int to : m_g[s]) {\n         \
    \       if (to == p or used[to]) { continue; }\n                if (szs[to] *\
    \ 2 > tot) { return dfs(to, s, tot); }\n            }\n            if (tot ==\
    \ N) { m_center = s; }\n            return s;\n        });\n        Fixpoint([&](auto\
    \ dfs, int s, int pc) -> int {\n            const int tot = sizeDfs(s, -1);\n\
    \            const int c = getCentor(s, -1, tot);\n            used[c] = true;\n\
    \            if (pc != -1) { m_cs.addEdge(pc, c); }\n            for (int to :\
    \ m_g[s]) {\n                if (not used[to]) { dfs(to, s, c); }\n          \
    \  }\n        })(0, N);\n    }\n    const int center() const\n    {\n        return\
    \ m_center;\n    }\n    const Graph<>& centers() const\n    {\n        return\
    \ m_cs;\n    }\n    const Vec<int>& subs(int v)\n    {\n        const int N =\
    \ m_g.v();\n        assert(0 <= v and v < N);\n        calcSub();\n        return\
    \ m_subss[v];\n    }\n    const Vec<Vec<int>>& subss(int v)\n    {\n        const\
    \ int N = m_g.v();\n        assert(0 <= v and v < N);\n        calcSub();\n  \
    \      return m_subsss[v];\n    }\nprivate:\n    void calcSub()\n    {\n     \
    \   if (not m_sub_calced) {\n            const int N = m_g.v();\n            Vec<bool>\
    \ used(N, false);\n            Fixpoint([&](auto dfs, const int c) -> void {\n\
    \                used[c] = true;\n                m_subss[c].push_back(c);\n \
    \               for (int to : m_g[c]) {\n                    if (used[to]) { continue;\
    \ }\n                    m_subsss[c].push_back(Vec<int>{});\n                \
    \    Fixpoint([&](auto dfs2, const int s, const int p) -> void {\n           \
    \             for (int to2 : m_g[s]) {\n                            if (p == to2\
    \ or used[to2]) { continue; }\n                            m_subss[c].push_back(to2);\n\
    \                            m_subsss[c].back().push_back(to2);\n            \
    \                dfs2(to2, s);\n                        }\n                  \
    \  })(to, -1);\n                }\n                for (int to : m_g[c]) {\n \
    \                   dfs(to);\n                }\n            })(m_center);\n \
    \       }\n        m_sub_calced = true;\n    }\n    Graph<T> m_g;\n    int m_center;\n\
    \    Graph<> m_cs;\n    bool m_sub_calced;\n    Vec<Vec<int>> m_subss;\n    Vec<Vec<Vec<int>>>\
    \ m_subsss;\n};\n"
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
  path: src/graph/centroid_decomp.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/centroid_decomp.hpp
layout: document
redirect_from:
- /library/src/graph/centroid_decomp.hpp
- /library/src/graph/centroid_decomp.hpp.html
title: src/graph/centroid_decomp.hpp
---
