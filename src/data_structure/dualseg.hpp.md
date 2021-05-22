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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename OpMonoid>\n\
    class DualSeg\n{\n    using F = typename OpMonoid::F;\n    static constexpr F\
    \ id()\n    {\n        return OpMonoid::id();\n    }\n\npublic:\n    DualSeg(const\
    \ Vec<F>& vs)\n        : m_size(vs.size()),\n          m_depth(clog(m_size) +\
    \ 1),\n          m_half(1 << m_depth),\n          m_ops(m_half << 1, id())\n \
    \   {\n        std::copy(vs.begin(), vs.end(), m_ops.begin() + m_half);\n    }\n\
    \    F get(int i) const\n    {\n        assert(0 <= i and i < m_size);\n     \
    \   F ans = id();\n        i += m_half;\n        for (int h : per(m_depth)) {\n\
    \            ans = compose(ans, m_ops[i >> h]);\n        }\n        return ans;\n\
    \    }\n    void set(int i, const F& f)\n    {\n        assert(0 <= i and i <\
    \ m_size);\n        i += m_half;\n        clean(i), clean(i + 1);\n        m_ops[i]\
    \ = f;\n    }\n    void act(int l, int r, const F& f)\n    {\n        assert(0\
    \ <= l and r <= m_size);\n        if (l >= r) { return; }\n        int li = l\
    \ + m_half, ri = r + m_half;\n        clean(li), clean(ri);\n        for (; li\
    \ < ri; li >>= 1, ri >>= 1) {\n            if (li & 1) { update(li++, f); }\n\
    \            if (ri & 1) { update(--ri, f); }\n        }\n    }\n    friend Ostream&\
    \ operator<<(Ostream& os, const DualSeg& seg)\n    {\n        os << \"[\";\n \
    \       for (int i : rep(seg.m_size)) {\n            os << (i == 0 ? \"\" : \"\
    ,\") << seg.get(i);\n        }\n        return (os << \"]\\n\");\n    }\n\nprivate:\n\
    \    void down(int i)\n    {\n        update(i << 1, m_ops[i]), update(i << 1\
    \ | 1, m_ops[i]);\n        m_ops[i] = id();\n    }\n    void clean(int i)\n  \
    \  {\n        const int b = (i / (i & -i)) >> 1;\n        for (const int h : per(m_depth))\
    \ {\n            const int v = i >> h;\n            if (v > b) { break; }\n  \
    \          down(v);\n        }\n    }\n    void update(int i, const F& f)\n  \
    \  {\n        m_ops[i] = compose(f, m_ops[i]);\n    }\n    int m_size, m_depth,\
    \ m_half;\n    Vec<F> m_ops;\n    static inline OpMonoid compose;\n};\n"
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
  path: src/data_structure/dualseg.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/dualseg.hpp
layout: document
title: Dual Segment Tree
---

## Dual Segment Tree

### 概要

作用素モノイド $(F, \circ, \mathrm{id})$ が決まっている。  
要素数 $N$ の 作用素列 $G = \lbrack G _ 0, G _ 1, \dots , G _ {N-1}\rbrack$ について、以下の操作が $\mathrm{O}(\log N)$ でできる。

- 範囲作用: $G _ i \leftarrow f \circ G _ i \quad (i \in \lbrack l, r) )$
- 範囲一点取得: $G _ i$

### I/F

#### コンストラクタ

```
dualseg<OpMonoid> seg(const std::vector<F>& G)
```

作用素列 $G$ で初期化する

テンプレート引数`OpMonoid`は以下のようなフィールドを持つクラス

```
struct OpMonoid
{
    using F = int;
    F operator()(const F& f1, const F& f2) const { return f1 + f2; }
    static constexpr F id() { return F{0}; }
};
```

- `F`: 作用素型
- `operator()(F f1, F f2)`: $f _ 1 \circ f _ 2$ 
- `id()`: 単位元

##### 計算量

- $\mathrm{O}(N)$

#### get

```
F seg.get(int i)
```

$G _ i$ の取得

##### 計算量

- $\mathrm{O}(\log N)$

#### set

```
void seg.set(int i, const F& f)
```

$G _ i \leftarrow f$ 

##### 計算量

- $\mathrm{O}(\log N)$

#### act

```
void seg.act(int l, int r, const F& f)
```

$G _ i \leftarrow f \circ G _ i \quad (i \in \lbrack l, r) )$

##### 計算量

- $\mathrm{O}(\log N)$

#### 出力

```
std::cout << seg << std::endl
```
