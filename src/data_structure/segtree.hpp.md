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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename MergeMonoid>\n\
    class SegTree\n{\n    using T = typename MergeMonoid::T;\n    static constexpr\
    \ T e()\n    {\n        return MergeMonoid::e();\n    }\n\npublic:\n    SegTree(const\
    \ Vec<T>& vs)\n        : m_size(vs.size()),\n          m_half(ceil2(m_size)),\n\
    \          m_vals(m_half << 1, MergeMonoid::e())\n    {\n        std::copy(vs.begin(),\
    \ vs.end(), m_vals.begin() + m_half);\n        for (int i = m_half - 1; i >= 1;\
    \ i--) {\n            up(i);\n        }\n    }\n    T get(int i) const\n    {\n\
    \        assert(0 <= i and i < m_size);\n        return m_vals[i + m_half];\n\
    \    }\n    void set(int i, const T& v)\n    {\n        assert(0 <= i and i <\
    \ m_size);\n        m_vals[i += m_half] = v;\n        while (i >>= 1) {\n    \
    \        up(i);\n        }\n    }\n    T fold(int l, int r) const\n    {\n   \
    \     assert(0 <= l and l <= r and r <= m_size);\n        T lv = e(), rv = e();\n\
    \        int li = l + m_half, ri = r + m_half;\n        for (; li < ri; li >>=\
    \ 1, ri >>= 1) {\n            if (li & 1) { lv = merge(lv, m_vals[li++]); }\n\
    \            if (ri & 1) { rv = merge(m_vals[--ri], rv); }\n        }\n      \
    \  return merge(lv, rv);\n    }\n    friend Ostream& operator<<(Ostream& os, const\
    \ SegTree& seg)\n    {\n        os << \"[\";\n        for (int i : rep(seg.m_size))\
    \ {\n            os << (i == 0 ? \"\" : \",\") << seg.m_vals[i + seg.m_half];\n\
    \        }\n        return (os << \"]\");\n    }\n\nprivate:\n    void up(int\
    \ i)\n    {\n        m_vals[i] = merge(m_vals[i << 1], m_vals[i << 1 | 1]);\n\
    \    }\n    int m_size, m_half;\n    Vec<T> m_vals;\n    static inline MergeMonoid\
    \ merge;\n};\n"
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
  path: src/data_structure/segtree.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree.hpp
- /library/src/data_structure/segtree.hpp.html
title: src/data_structure/segtree.hpp
---
