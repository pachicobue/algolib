---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data_structure/ds_table.hpp
    title: Disjoint Sparse Table
  - icon: ':warning:'
    path: src/data_structure/static_rmq.hpp
    title: src/data_structure/static_rmq.hpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/misc/common/show.hpp: line 5: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n#include \"../data_structure/static_rmq.hpp\"\n#include \"\
    ../misc/common.hpp\"\n#include \"graph.hpp\"\ntemplate<typename C>\nclass LCA\n\
    {\n    using P = Pair<int, int>;\npublic:\n    LCA(const Graph<C>& g, int r =\
    \ 0)\n        : m_v(g.v()),\n          m_ins(g.v(), 0),\n          m_ds([&]()\
    \ {\n              Vec<P> ans;\n              Vec<bool> used(g.v(), false);\n\
    \              Fixpoint([&](auto dfs, const P& s) -> void {\n                \
    \  const int u = s.second;\n                  used[u] = true;\n              \
    \    m_ins[u] = ans.size();\n                  ans.push_back(s);\n           \
    \       for (int v : g[u]) {\n                      if (used[v]) { continue; }\n\
    \                      dfs({s.first + 1, v});\n                      ans.push_back(s);\n\
    \                  }\n              })({0, r});\n              return ans;\n \
    \         }()),\n          m_rmq(m_ds)\n    {}\n    int operator()(int u, int\
    \ v) const\n    {\n        const auto [ul, vl] = std::minmax({m_ins[u], m_ins[v]});\n\
    \        return m_rmq.fold(ul, vl + 1).second;\n    }\nprivate:\n    struct Ord\n\
    \    {\n        using T = P;\n        bool operator()(const T& p1, const T& p2)\
    \ const\n        {\n            return p1 < p2;\n        }\n    };\n    int m_v;\n\
    \    Vec<int> m_ins;\n    Vec<P> m_ds;\n    StaticRMQ<Ord> m_rmq;\n};\n"
  dependsOn:
  - src/data_structure/static_rmq.hpp
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
  - src/data_structure/ds_table.hpp
  - src/graph/graph.hpp
  isVerificationFile: false
  path: src/graph/lca.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/lca.hpp
layout: document
redirect_from:
- /library/src/graph/lca.hpp
- /library/src/graph/lca.hpp.html
title: src/graph/lca.hpp
---
