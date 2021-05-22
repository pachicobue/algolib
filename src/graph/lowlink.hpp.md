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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/bcc.hpp
    title: src/graph/bcc.hpp
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
    \ T>\nclass LowLink\n{\n    using P = Pair<int, int>;\n\npublic:\n    LowLink(const\
    \ Graph<T>& g)\n        : m_v(g.v()), m_ords(m_v), m_lows(m_v), m_is_art(m_v)\n\
    \    {\n        const int N = g.v();\n        int visited = 0;\n        Vec<bool>\
    \ used(N, false);\n        Fixpoint([&](auto dfs, int s, int p) -> void {\n  \
    \          used[s] = true;\n            m_ords[s] = visited++;\n            bool\
    \ is_art = false;\n            int dim = 0;\n            for (int to : g[s]) {\n\
    \                if (not used[to]) {\n                    dim++;\n           \
    \         dfs(to, s);\n                    chmin(m_lows[s], m_lows[to]);\n   \
    \                 is_art |= m_ords[s] > m_lows[to];\n                    if (isBridge(s,\
    \ to)) {\n                        m_bridges.push_back(std::minmax({s, to}));\n\
    \                    }\n                } else if (to != p) {\n              \
    \      chmin(m_lows[s], m_ords[to]);\n                }\n            }\n     \
    \       if (p == -1) {\n                m_is_art[s] = (dim >= 2);\n          \
    \  } else {\n                m_is_art[s] = is_art;\n            }\n        })(0,\
    \ -1);\n    }\n    bool isArt(int i) const\n    {\n        assert(0 <= i and i\
    \ < m_v);\n        return m_is_art[i];\n    }\n    bool isBridge(int i, int j)\
    \ const\n    {\n        assert(0 <= i and i < m_v);\n        assert(0 <= j and\
    \ j < m_v);\n        if (m_ords[i] > m_ords[j]) { std::swap(i, j); }\n       \
    \ return m_ords[i] < m_lows[j];\n    }\n    const Vec<P>& bridges() const\n  \
    \  {\n        return m_bridges;\n    }\n    const Vec<int>& arts() const\n   \
    \ {\n        return m_arts;\n    }\n\nprivate:\n    int m_v;\n    Vec<P> m_bridges;\n\
    \    Vec<int> m_arts;\n    Vec<int> m_ords;\n    Vec<int> m_lows;\n    Vec<bool>\
    \ m_is_art;\n};\n"
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
  path: src/graph/lowlink.hpp
  requiredBy:
  - src/graph/bcc.hpp
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/lowlink.hpp
layout: document
redirect_from:
- /library/src/graph/lowlink.hpp
- /library/src/graph/lowlink.hpp.html
title: src/graph/lowlink.hpp
---
