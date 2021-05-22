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
    \ T>\nVec<T> dijkstra(const Graph<T>& g, int s)\n{\n    const int N = g.v();\n\
    \    assert(0 <= s and s < N);\n    Vec<T> ds(N, INF<T>);\n    using P = Pair<T,\
    \ int>;\n    MinHeap<P> Q;\n    ds[s] = 0;\n    Q.push({T{}, s});\n    while (not\
    \ Q.empty()) {\n        const auto [c, u] = Q.top();\n        Q.pop();\n     \
    \   if (ds[u] < c) { continue; }\n        for (const auto& [v, c] : g[u]) {\n\
    \            if (ds[v] <= ds[u] + c) { continue; }\n            ds[v] = ds[u]\
    \ + c;\n            Q.push({ds[v], v});\n        }\n    }\n    return ds;\n}\n"
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
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: src/graph/dijkstra.hpp
---
