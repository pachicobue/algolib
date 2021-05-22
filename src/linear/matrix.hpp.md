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
    path: src/linear/gauss_jordan.hpp
    title: src/linear/gauss_jordan.hpp
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
    \ Mat\n{\npublic:\n    Mat(const int row, const int column) : m_row{row},\n  \
    \                                         m_column{column},\n                \
    \                           m_vss(row, Vec<T>(column, 0)) {}\n    const Vec<T>&\
    \ operator[](const int r) const\n    {\n        assert(0 <= r and r < m_row);\n\
    \        return m_vss[r];\n    }\n    Vec<T>& operator[](const int r)\n    {\n\
    \        assert(0 <= r and r < m_row);\n        return m_vss[r];\n    }\n    friend\
    \ Mat operator-(const Mat& m)\n    {\n        Mat ans(m.m_row, m.m_column);\n\
    \        for (int i : rep(m.m_row)) {\n            for (int j : rep(m.m_column))\
    \ {\n                ans[i][j] = -m[i][j];\n            }\n        }\n       \
    \ return ans;\n    }\n    friend Mat operator+(const Mat& m1, const Mat& m2) {\
    \ return Mat{m1} += m2; }\n    friend Mat operator-(const Mat& m1, const Mat&\
    \ m2) { return Mat{m1} -= m2; }\n    friend Mat operator*(const Mat& m1, const\
    \ Mat& m2) { return Mat{m1} *= m2; }\n    friend Mat operator*(const Mat& m, const\
    \ T& t) { return Mat{m} *= t; }\n    friend Mat operator/(const Mat& m, const\
    \ T& t) { return Mat{m} /= t; }\n    friend Mat operator*(const T& t, const Mat&\
    \ m) { return m * t; }\n    template<typename I>\n    Mat pow(const Mat& m, I\
    \ n) const\n    {\n        return power(m, n, I());\n    }\n    friend Mat& operator+=(Mat&\
    \ m1, const Mat& m2)\n    {\n        assert(m1.m_row == m2.m_row);\n        assert(m1.m_column\
    \ == m2.m_column);\n        Mat ans(m1.m_row, m1.m_column);\n        for (int\
    \ i : rep(m1.m_row)) {\n            for (int j : rep(m1.m_column)) {\n       \
    \         m1[i][j] += m2[i][j];\n            }\n        }\n        return m1;\n\
    \    }\n    friend Mat& operator-=(Mat& m1, const Mat& m2)\n    {\n        assert(m1.m_row\
    \ == m2.m_row);\n        assert(m1.m_column == m2.m_column);\n        Mat ans(m1.m_row,\
    \ m1.m_column);\n        for (int i : rep(m1.m_row)) {\n            for (int j\
    \ : rep(m1.m_column)) {\n                m1[i][j] -= m2[i][j];\n            }\n\
    \        }\n        return m1;\n    }\n    friend Mat& operator*=(Mat& m1, const\
    \ Mat& m2)\n    {\n        assert(m1.m_row == m1.m_column);\n        assert(m2.m_row\
    \ == m2.m_column);\n        Mat ans(m1.m_row, m2.m_column);\n        for (int\
    \ i : rep(m1.m_row)) {\n            for (int j : rep(m2.m_column)) {\n       \
    \         for (int k : rep(m1.m_column)) {\n                    ans[i][j] = m1[i][k]\
    \ * m2[k][j];\n                }\n            }\n        }\n        return m1\
    \ = ans;\n    }\n    friend Mat& operator*=(Mat& m, const T& t)\n    {\n     \
    \   Mat ans(m.m_row, m.m_column);\n        for (int i : rep(m.m_row)) {\n    \
    \        for (int j : rep(m.m_column)) {\n                m[i][j] *= t;\n    \
    \        }\n        }\n        return m;\n    }\n    friend Mat& operator/=(Mat&\
    \ m, const T& t)\n    {\n        Mat ans(m.m_row, m.m_column);\n        for (int\
    \ i : rep(m.m_row)) {\n            for (int j : rep(m.m_column)) {\n         \
    \       m[i][j] /= t;\n            }\n        }\n        return m;\n    }\n  \
    \  friend Ostream& operator<<(Ostream& os, const Mat& m)\n    {\n        os <<\
    \ \"[\\n\";\n        for (int i : rep(m.m_row)) {\n            os << \"[\";\n\
    \            for (int j : rep(m.m_column)) {\n                os << m[i][j] <<\
    \ \",\";\n            }\n            os << \"]\\n\";\n        }\n        return\
    \ (os << \"]\\n\");\n    }\n    static Mat I(int N)\n    {\n        Mat ans(N,\
    \ N);\n        for (int i : rep(N)) { ans[i][i] = 1; }\n        return ans;\n\
    \    }\n    int row() const { return m_row; }\n    int column() const { return\
    \ m_column; }\n\nprivate:\n    int m_row, m_column;\n    Vec<Vec<T>> m_vss;\n\
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
  path: src/linear/matrix.hpp
  requiredBy:
  - src/linear/gauss_jordan.hpp
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/linear/matrix.hpp
layout: document
redirect_from:
- /library/src/linear/matrix.hpp
- /library/src/linear/matrix.hpp.html
title: src/linear/matrix.hpp
---
