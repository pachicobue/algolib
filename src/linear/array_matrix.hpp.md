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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename T, int row,\
    \ int column>\nclass ArrMat\n{\npublic:\n    ArrMat()\n    {\n        for (auto&\
    \ v : m_vss) { fillAll(v, T{}); }\n    }\n    ArrMat(const IList<IList<T>>& vss)\n\
    \    {\n        assert(row == vss.size());\n        assert(column == vss.begin()->size());\n\
    \        int i = 0;\n        for (auto it = vss.begin(); it != vss.end(); it++)\
    \ {\n            std::copy(it->begin(), it->end(), m_vss[i].begin());\n      \
    \  }\n    }\n    ArrMat(const ArrMat& m) : m_vss{m.m_table} {}\n    ArrMat& operator=(const\
    \ ArrMat& m)\n    {\n        for (const int i : rep(row)) {\n            for (const\
    \ int j : rep(column)) {\n                m_vss[i][j] = m[i][j];\n           \
    \ }\n        }\n        return *this;\n    }\n    const Arr<T, column>& operator[](const\
    \ int r) const { return m_vss[r]; }\n    Arr<T, column>& operator[](const int\
    \ r) { return m_vss[r]; }\n    friend ArrMat operator-(const ArrMat& m)\n    {\n\
    \        ArrMat ans;\n        for (const int r : rep(row)) {\n            for\
    \ (const int c : rep(column)) {\n                ans[r][c] = -m[r][c];\n     \
    \       }\n        }\n        return ans;\n    }\n    friend ArrMat operator+(const\
    \ ArrMat& m1, const ArrMat& m2)\n    {\n        ArrMat ans;\n        for (const\
    \ int r : rep(row)) {\n            for (const int c : rep(column)) {\n       \
    \         ans[r][c] = m1[r][c] + m2[r][c];\n            }\n        }\n       \
    \ return ans;\n    }\n    friend ArrMat operator-(const ArrMat& m1, const ArrMat&\
    \ m2)\n    {\n        ArrMat ans;\n        for (const int r : rep(row)) {\n  \
    \          for (const int c : rep(column)) {\n                ans[r][c] = m1[r][c]\
    \ - m2[r][c];\n            }\n        }\n        return ans;\n    }\n    template<int\
    \ c>\n    friend ArrMat operator*(const ArrMat<T, row, c>& m1, const ArrMat<T,\
    \ c, column>& m2)\n    {\n        ArrMat<T, row, column> ans;\n        for (const\
    \ int i : rep(row)) {\n            for (const int j : rep(column)) {\n       \
    \         for (const int k : rep(c)) {\n                    ans[i][j] += m1[i][k]\
    \ * m2[k][j];\n                }\n            }\n        }\n        return ans;\n\
    \    }\n    friend ArrMat operator*(const ArrMat& m, const T& t)\n    {\n    \
    \    ArrMat ans;\n        for (const int r : rep(row)) {\n            for (const\
    \ int c : rep(column)) {\n                ans[r][c] = m[r][c] * t;\n         \
    \   }\n        }\n        return ans;\n    }\n    friend ArrMat operator/(const\
    \ ArrMat& m, const T& t)\n    {\n        ArrMat ans;\n        for (const int r\
    \ : rep(row)) {\n            for (const int c : rep(column)) {\n             \
    \   ans[r][c] = m[r][c] / t;\n            }\n        }\n        return ans;\n\
    \    }\n    friend ArrMat operator*(const T& t, const ArrMat& m) { return m *\
    \ t; }\n    template<typename Int>\n    ArrMat pow(Int n) const { return power(*this,\
    \ n, I()); }\n    friend ArrMat& operator+=(ArrMat& m1, const ArrMat& m2) { return\
    \ m1 = m1 + m2; }\n    friend ArrMat& operator-=(ArrMat& m1, const ArrMat& m2)\
    \ { return m1 = m1 - m2; }\n    friend ArrMat& operator*=(ArrMat& m1, const ArrMat&\
    \ m2) { return m1 = m1 * m2; }\n    friend ArrMat& operator*=(ArrMat& m, const\
    \ T& t) { return m = m * t; }\n    friend ArrMat& operator/=(ArrMat& m, const\
    \ T& t) { return m = m / t; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const ArrMat& m)\n    {\n        os << \"[\\n\";\n        for (const int\
    \ i : rep(row)) {\n            os << \"[\";\n            for (const int j : rep(column))\
    \ { os << m[i][j] << \",\"; }\n            os << \"]\\n\";\n        }\n      \
    \  return (os << \"]\");\n    }\n    static ArrMat I()\n    {\n        static_assert(row\
    \ == column, \"I() should be rectangular!\");\n        ArrMat ans;\n        for\
    \ (const int i : rep(row)) {\n            ans[i][i] = 1;\n        }\n        return\
    \ ans;\n    }\n\nprivate:\n    Arr<Arr<T, column>, row> m_vss;\n};\n"
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
  path: src/linear/array_matrix.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/linear/array_matrix.hpp
layout: document
redirect_from:
- /library/src/linear/array_matrix.hpp
- /library/src/linear/array_matrix.hpp.html
title: src/linear/array_matrix.hpp
---
