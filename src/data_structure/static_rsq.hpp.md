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
    \ StaticRSQ\n{\npublic:\n    StaticRSQ(const Vec<T>& vs)\n        : m_size(vs.size()),\n\
    \          m_prefs(vs.size() + 1, T{}),\n          m_suffs(vs.size() + 1, T{})\n\
    \    {\n        std::copy(vs.begin(), vs.end(), m_prefs.begin() + 1);\n      \
    \  for (int i : rep(m_size)) {\n            m_prefs[i + 1] += m_prefs[i];\n  \
    \      }\n        std::copy(vs.begin(), vs.end(), m_suffs.begin());\n        for\
    \ (int i : per(m_size)) {\n            m_suffs[i] += m_suffs[i + 1];\n       \
    \ }\n    }\n    void unsafeSet(int i, const T& v)\n    {\n        assert(0 < i\
    \ and i < m_size);\n        m_prefs[i + 1] = m_prefs[i] + v, m_suffs[i] = m_suffs[i\
    \ + 1] + v;\n    }\n    T prefixSum(int l, int r) const\n    {\n        assert(0\
    \ <= l and l <= r and r <= m_size);\n        return m_prefs[r] - m_prefs[l];\n\
    \    }\n    T suffixSum(int l, int r) const\n    {\n        assert(0 <= l and\
    \ l <= r and r <= m_size);\n        return m_suffs[l] - m_suffs[r];\n    }\nprivate:\n\
    \    int m_size;\n    Vec<T> m_prefs, m_suffs;\n};\n"
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
  path: src/data_structure/static_rsq.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/static_rsq.hpp
layout: document
redirect_from:
- /library/src/data_structure/static_rsq.hpp
- /library/src/data_structure/static_rsq.hpp.html
title: src/data_structure/static_rsq.hpp
---
