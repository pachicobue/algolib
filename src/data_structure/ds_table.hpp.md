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
    path: src/data_structure/static_rmq.hpp
    title: src/data_structure/static_rmq.hpp
  - icon: ':warning:'
    path: src/graph/lca.hpp
    title: src/graph/lca.hpp
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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename SemiGroup>\n\
    class DSTable\n{\n    using T = typename SemiGroup::T;\npublic:\n    DSTable(const\
    \ Vec<T>& vs)\n        : m_size(vs.size()), m_depth(log2p1(m_size)), m_vss(m_depth,\
    \ vs)\n    {\n        for (int d : rep(m_depth)) {\n            const int w =\
    \ 1 << (m_depth - d - 1);\n            for (int i = 1; i * w < m_size; i += 2)\
    \ {\n                int l = i * w - 1, r = i * w;\n                for (int j\
    \ : rep(w)) {\n                    m_vss[d][l - j] = merge(vs[l - j], m_vss[d][l\
    \ - j + 1]);\n                    if (r + j < m_size) {\n                    \
    \    m_vss[d][r + j] = merge(vs[r + j], m_vss[d][r + j - 1]);\n              \
    \      }\n                }\n            }\n        }\n    }\n    T fold(const\
    \ int l, const int r) const\n    {\n        assert(0 <= l and l < r and r <= m_size);\n\
    \        if (r - l == 1) { return m_vss.back()[l]; }\n        const int d = m_depth\
    \ - log2p1(l ^ (r - 1));\n        return merge(m_vss[d][l], m_vss[d][r - 1]);\n\
    \    }\nprivate:\n    int m_size, m_depth;\n    Vec<Vec<T>> m_vss;\n    static\
    \ inline SemiGroup merge;\n};\n"
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
  path: src/data_structure/ds_table.hpp
  requiredBy:
  - src/data_structure/static_rmq.hpp
  - src/graph/lca.hpp
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/ds_table.hpp
layout: document
title: Disjoint Sparse Table
---

## Disjoint Sparse Table

### 概要

半群 $(T, \ast)$ 上の要素数 $N$ の 数列 $A = \lbrack A _ 0, A _ 1, \dots , A _ {N-1}\rbrack$ について、  
以下の操作が $\mathrm{O}(1)$ でできる。

- 範囲総積取得: $A _ l \ast \dots \ast A _ {r-1}$

### I/F

#### コンストラクタ

```
ds_table<SemiGroup> ds(const std::vector<T>& A)
```

数列 $A$ で初期化する

テンプレート引数`SemiGroup`は以下のようなフィールドを持つクラス

- `T`:型
- `operator()(T x1, T x2)`: $x _ 1 \ast x _ 2$

```
struct SemiGroup
{
    using T = int;
    T operator()(const T& x1, const T& x2) const { return std::min(x1, x2); }
};
```

##### 計算量

- $\mathrm{O}(N\log N)$

#### add

```
void bit.add(int i, const T& x)
```

$A _ i$ に $x$ を加算

##### 計算量

- $\mathrm{O}(\log N)$

#### fold

```
T ds.fold(int l, int r)
```

$A _ l \ast \dots \ast A _ {r-1}$ を取得

##### 計算量

- $\mathrm{O}(1)$

