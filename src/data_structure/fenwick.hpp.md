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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename T> class\
    \ Fenwick\n{\npublic:\n    Fenwick(const Vec<T>& vs)\n        : m_size(vs.size()),\
    \ m_cap(ceil2(m_size)), m_vs(m_cap + 1, 0)\n    {\n        std::copy(vs.begin(),\
    \ vs.end(), m_vs.begin() + 1);\n        for (int x : range(1, m_cap)) {\n    \
    \        m_vs[x + (x & -x)] += m_vs[x];\n        }\n    }\n    void add(int i,\
    \ const T& v)\n    {\n        assert(0 <= i and i < m_size);\n        for (int\
    \ ind = i + 1; ind <= m_cap; ind += ind & (-ind)) {\n            m_vs[ind] +=\
    \ v;\n        }\n    }\n    T sum(int i) const\n    {\n        assert(0 <= i and\
    \ i <= m_size);\n        T sum{};\n        for (int ind = i; ind != 0; ind &=\
    \ ind - 1) {\n            sum += m_vs[ind];\n        }\n        return sum;\n\
    \    }\n    T sum(int l, int r) const\n    {\n        assert(0 <= l and l <= r\
    \ and r <= m_size);\n        return sum(r) - sum(l);\n    }\n    template<typename\
    \ F> int maxRight(F f)\n    {\n        assert(f(T{}));\n        T sum = T{};\n\
    \        int x = 0;\n        for (int k = (m_cap >> 1); k >= 1; k >>= 1) {\n \
    \           if (x + k <= m_size and f(sum + m_vs[x + k])) {\n                sum\
    \ += m_vs[x + k], x += k;\n            }\n        }\n        return x;\n    }\n\
    \    friend Ostream& operator<<(Ostream& os, const Fenwick& fw)\n    {\n     \
    \   os << \"[\";\n        for (int i : rep(fw.m_size)) {\n            os << (i\
    \ == 0 ? \"\" : \",\") << fw.sum(i, i + 1);\n        }\n        return (os <<\
    \ \"]\\n\");\n    }\n\nprivate:\n    int m_size, m_cap;\n    Vec<T> m_vs;\n};\n"
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
  path: src/data_structure/fenwick.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/fenwick.hpp
layout: document
title: Fenwick Tree
---

## Fenwick Tree

### 概要

要素数 $N$ の 数列 $A = \lbrack A _ 0, A _ 1, \dots , A _ {N-1}\rbrack$ について、以下の操作が $\mathrm{O}(\log N)$ でできる。

- 一点加算: $A _ i \leftarrow A _ i + x$
- 範囲総和取得:  $A _ 0 + A _ 1 + \dots + A _ {n-1}$

### I/F

#### コンストラクタ

```
fenwick<T> bit(const std::vector<T>& A)
```

数列 $A$ で初期化する

##### 計算量

- $\mathrm{O}(N)$

#### add

```
void bit.add(int i, const T& x)
```

$A _ i$ に $x$ を加算

##### 計算量

- $\mathrm{O}(\log N)$

#### sum

```
(1) T bit.sum(int i)
(2) T bit.sum(int l, int r)
```

(1) $A _ 0 + A _ 1 + \dots + A _ {i-1}$ を取得
(2) $A _ l + A _ {l+1} + \dots + A _ {r-1}$ を取得

##### 計算量

- $\mathrm{O}(\log N)$

#### max_right

```
int bit.max_right<F>(F f)
```

以下を両方満たす $0 \le r \le N$ を1つ返す
- $f(A _ 0 + A _ 1 + \dots + A _ {r-1}) = true$
- $f(A _ 0 + A _ 1 + \dots + A _ {r}) = false$

##### 制約

- f(0) = True

##### 計算量

- $\mathrm{O}(\log N)$

#### 出力

```
std::cout << bit << std::endl
```

