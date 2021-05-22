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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/linear/bit_gauss_jordan.hpp
    title: src/linear/bit_gauss_jordan.hpp
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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<int column>\nclass\
    \ BitMat\n{\npublic:\n    BitMat(int row) : m_row{row},\n                    \
    \  m_vss(m_row) {}\n    const BSet<column>& operator[](const int r) const\n  \
    \  {\n        assert(0 <= r and r < m_row);\n        return m_vss[r];\n    }\n\
    \    BSet<column>& operator[](const int r)\n    {\n        assert(0 <= r and r\
    \ < m_row);\n        return m_vss[r];\n    }\n    friend BitMat operator^(const\
    \ BitMat& m1, const BitMat& m2)\n    {\n        assert(m1.m_row == m2.m_row);\n\
    \        BitMat ans(m1.m_row);\n        for (int i : rep(m1.row)) { ans[i] = m1[i]\
    \ ^ m2[i]; }\n        return ans;\n    }\n    template<int col2>\n    friend BitMat\
    \ operator*(const BitMat& m1, const BitMat<col2>& m2)\n    {\n        assert(column\
    \ == m2.m_row);\n        BitMat<col2> ans(m1.m_row);\n        for (int i : rep(m1.m_row))\
    \ {\n            for (int j : rep(column)) {\n                if (not m1[i][j])\
    \ { continue; }\n                ans[i] ^= m2[j];\n            }\n        }\n\
    \        return ans;\n    }\n    template<typename I>\n    BitMat pow(I n) { return\
    \ power(*this, n, I(m_row)); }\n    friend BitMat& operator^=(BitMat& m1, const\
    \ BitMat& m2)\n    {\n        assert(m1.m_row == m2.m_row);\n        for (int\
    \ i : rep(m1.m_row)) { m1[i] ^= m2[i]; }\n        return m1;\n    }\n    friend\
    \ BitMat& operator*=(BitMat& m1, const BitMat& m2) { return m1 = m1 * m2; }\n\
    \    friend Ostream& operator<<(Ostream& os, const BitMat& m)\n    {\n       \
    \ os << \"[\\n\";\n        for (int i : rep(m.m_row)) { os << \"[\" << m[i] <<\
    \ \"]\\n\"; }\n        return (os << \"]\");\n    }\n    static BitMat I(const\
    \ int n)\n    {\n        BitMat ans(n);\n        for (int i : rep(n)) { ans[i].set(i);\
    \ }\n        return ans;\n    }\n\n    int row() const { return m_row; }\n\nprivate:\n\
    \    int m_row;\n    Vec<BSet<column>> m_vss;\n};\n"
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
  path: src/linear/bit_matrix.hpp
  requiredBy:
  - src/linear/bit_gauss_jordan.hpp
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/linear/bit_matrix.hpp
layout: document
redirect_from:
- /library/src/linear/bit_matrix.hpp
- /library/src/linear/bit_matrix.hpp.html
title: src/linear/bit_matrix.hpp
---
