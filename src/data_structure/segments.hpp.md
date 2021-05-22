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
  code: "#pragma once\n#include \"../misc/common.hpp\"\nclass segments\n{\n    using\
    \ P = Pair<int, int>;\npublic:\n    segments(int size)\n        : m_ceil(ceil2(size)),\
    \ m_segs(m_ceil << 1, P{0, 0}), m_num{m_ceil << 1}\n    {\n        for (int sz\
    \ = 1; sz <= m_ceil; sz <<= 1) {\n            const int len = m_ceil / sz;\n \
    \           for (int j : range(sz, sz * 2)) {\n                m_segs[j] = {len\
    \ * (j - sz), len * (j - sz + 1)};\n            }\n        }\n    }\n    Vec<int>\
    \ under(int l, int r) const\n    {\n        if (l >= r or r > m_ceil) { return\
    \ Vec<int>{}; }\n        Vec<int> lis, ris;\n        int li = l + m_ceil, ri =\
    \ r + m_ceil;\n        for (; li < ri; li >>= 1, ri >>= 1) {\n            if (li\
    \ & 1) { lis.push_back(li++); }\n            if (ri & 1) { ris.push_back(--ri);\
    \ }\n        }\n        reverseAll(ris);\n        return lis + ris;\n    }\n \
    \   Vec<int> over(int i) const\n    {\n        if (i >= m_ceil) { return Vec<int>{};\
    \ }\n        Vec<int> aboves;\n        i += m_ceil;\n        for (; i >= 1; i\
    \ >>= 1) {\n            aboves.push_back(i);\n        }\n        reverseAll(aboves);\n\
    \        return aboves;\n    }\n    const P& operator[](int i) const\n    {\n\
    \        return m_segs[i];\n    }\n    int size() const\n    {\n        return\
    \ m_num;\n    }\nprivate:\n    int m_ceil;\n    Vec<P> m_segs;\n    int m_num;\n\
    };\n"
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
  path: src/data_structure/segments.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segments.hpp
layout: document
redirect_from:
- /library/src/data_structure/segments.hpp
- /library/src/data_structure/segments.hpp.html
title: src/data_structure/segments.hpp
---
