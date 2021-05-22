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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename MergeMonoid,\
    \ typename OpMonoid, typename Act>\nclass LazySeg\n{\n    using T = typename MergeMonoid::T;\n\
    \    using F = typename OpMonoid::F;\n    static constexpr T e()\n    {\n    \
    \    return MergeMonoid::e();\n    }\n    static constexpr F id()\n    {\n   \
    \     return OpMonoid::id();\n    }\n\npublic:\n    LazySeg(const Vec<T>& vs)\n\
    \        : m_size(vs.size()),\n          m_depth(clog(m_size) + 1),\n        \
    \  m_half(1 << m_depth),\n          m_vs(m_half << 1, e()),\n          m_ops(m_half\
    \ << 1, id())\n    {\n        std::copy(vs.begin(), vs.end(), m_vs.begin() + m_half);\n\
    \        for (int i : range(1, m_half)) {\n            up(i);\n        }\n   \
    \ }\n    T get(const int a)\n    {\n        assert(a < m_size);\n        return\
    \ fold(a, a + 1);\n    }\n    void set(int i, const T& v)\n    {\n        assert(0\
    \ <= i and i < m_size);\n        i += m_half;\n        topDown(i), topDown(i +\
    \ 1);\n        m_ops[i] = id();\n        m_vs[i] = v;\n        while (i >>= 1)\
    \ {\n            up(i);\n        }\n    }\n    T fold(int l, int r)\n    {\n \
    \       assert(0 <= l and l <= r and r <= m_size);\n        if (l >= r) { return\
    \ e(); }\n        l += m_half, r += m_half;\n        topDown(l), topDown(r);\n\
    \        T accl = e(), accr = e();\n        for (; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) { accl = merge(accl, m_vs[l++]); }\n            if (r\
    \ & 1) { accr = merge(m_vs[--r], accr); }\n        }\n        return merge(accl,\
    \ accr);\n    }\n    void act(int l, int r, const F& f)\n    {\n        assert(0\
    \ <= l and l <= r and r <= m_size);\n        int li = l + m_half, ri = r + m_half;\n\
    \        topDown(li), topDown(ri);\n        for (; li < ri; li >>= 1, ri >>= 1)\
    \ {\n            if (li & 1) { update(li++, f); }\n            if (ri & 1) { update(--ri,\
    \ f); }\n        }\n        bottomUp(l + m_half), bottomUp(r + m_half);\n    }\n\
    \    friend Ostream& operator<<(Ostream& os, const LazySeg& lseg)\n    {\n   \
    \     auto lseg2 = lseg;\n        os << \"[\";\n        for (int i : rep(lseg.m_size))\
    \ {\n            os << (i == 0 ? \"\" : \",\") << lseg2.get(i);\n        }\n \
    \       return (os << \"]\\n\");\n    }\n\nprivate:\n    void up(int i)\n    {\n\
    \        m_vs[i] = merge(m_vs[i << 1], m_vs[i << 1 | 1]);\n    }\n    void update(int\
    \ i, const F& f)\n    {\n        m_ops[i] = compose(f, m_ops[i]);\n        m_vs[i]\
    \ = apply(f, m_vs[i]);\n    }\n    void down(int i)\n    {\n        update(i <<\
    \ 1, m_ops[i]), update(i << 1 | 1, m_ops[i]);\n        m_ops[i] = id();\n    }\n\
    \    void topDown(int i)\n    {\n        const int j = (i / (i & -i)) >> 1;\n\
    \        for (const int h : per(m_depth)) {\n            const int v = i >> h;\n\
    \            if (v > j) { break; }\n            down(v);\n        }\n    }\n \
    \   void bottomUp(int i)\n    {\n        i = (i / (i & -i)) >> 1;\n        for\
    \ (; i >= 1; i >>= 1) {\n            up(i);\n        }\n    }\n    int m_size,\
    \ m_depth, m_half;\n    Vec<T> m_vs;\n    Vec<F> m_ops;\n    static inline MergeMonoid\
    \ merge;\n    static inline OpMonoid compose;\n    static inline Act apply;\n\
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
  path: src/data_structure/lazyseg.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/lazyseg.hpp
layout: document
title: Lazy Segment Tree
---

## Lazy Segment Tree

### 概要

値モノイド $(T, \ast, e)$ と モノイド作用 $(F, \circ, \mathrm{id})$ が決まっている。  
更に $f(x _ 1 \ast x _ 2) = f(x _ 1) \ast f(x _ 2)\quad (\forall f \in F, x _ 1 x _ 2 \in T)$ が成立しているとする。  
要素数 $N$ の 数列 $A = \lbrack A _ 0, A _ 1, \dots , A _ {N-1}\rbrack$ について、以下の操作が $\mathrm{O}(\log N)$ でできる。

- 範囲総積取得: $A _ l \ast \dots \ast A _ {r-1}$
- 範囲作用: $A _ i \leftarrow f(A _ i) \quad (i \in \lbrack l, r) )$

### I/F

#### コンストラクタ

```
lazyseg<MergeMonoid, OpMonoid, Act> seg(const std::vector<T>& A)
```

数列 $A$ で初期化する

テンプレート引数`MergeMonoid`は以下のようなフィールドを持つクラス

```
struct MergeMonoid
{
    using T = int;
    T operator()(const T& x1, const T& x2) const { return std::min(x1, x2); }
    static constexpr T e() { return inf_v<T>; }
};
```

- `T`: 作用素型
- `operator()(T x1, T x2)`: $x _ 1 \ast x _ 2$ 
- `T e()`: 単位元

テンプレート引数`OpMonoid`は以下のようなフィールドを持つクラス

```
struct OpMonoid
{
    using F = int;
    F operator()(const F& f1, const F& f2) const { return f1 + f2; }
    static constexpr F id() { return 0; }
};
```

- `F`: 作用素型
- `operator()(F f1, F f2)`: $f _ 1 \circ f _ 2$ 
- `F id()`: 単位元

テンプレート引数`Act`は以下のようなフィールドを持つクラス

- `operator()(F f, T x)`: $f(x)$ 

```
struct Act
{
    T operator()(const F& f, const T& x) const { return f + x; }
};
```


##### 計算量

- $\mathrm{O}(N)$

#### get

```
T seg.get(int i)
```

$A _ i$ の取得

##### 計算量

- $\mathrm{O}(\log N)$

#### set

```
void seg.set(int i, const T& x)
```

$A _ i \leftarrow x$ 

##### 計算量

- $\mathrm{O}(\log N)$

#### fold

```
void seg.fold(int l, int r)
```

$A _ l \ast \dots \ast A _ {r-1}$ の取得

##### 計算量

- $\mathrm{O}(\log N)$

#### act

```
void seg.act(int l, int r, const F& f)
```

$A _ i \leftarrow f(A _ i) \quad (i \in \lbrack l, r) )$

##### 計算量

- $\mathrm{O}(\log N)$

#### 出力

```
std::cout << seg << std::endl
```
