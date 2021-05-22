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
    \ LiChaoTree\n{\n    using L = Pair<T, T>;\n    static constexpr L NIL = {0, INF<T>};\n\
    \    struct Node\n    {\n        L line = NIL;\n        Arr<int, 2> sons{-1, -1};\n\
    \    };\n    static bool comp(const L& l1, const L& l2, T x)\n    {\n        if\
    \ (l1 == NIL or l2 == NIL) { return l2 == NIL; }\n        const auto& [a1, b1]\
    \ = l1;\n        const auto& [a2, b2] = l2;\n        if (a1 == a2) {\n       \
    \     return b1 <= b2;\n        } else if (a1 > a2) {\n            return x <=\
    \ fdiv(b2 - b1, a1 - a2);\n        } else {\n            return fdiv(b1 - b2,\
    \ a2 - a1) < x;\n        }\n    }\n\npublic:\n    LiChaoTree(T xmin, T xsup) :\
    \ m_xmin{xmin}, m_xsup{xsup}, m_nodes{Node{}}\n    {\n        assert(m_xmin <\
    \ m_xsup);\n    }\n    void addLine(T a, T b)\n    {\n        add(L{a, b}, 0,\
    \ m_xmin, m_xsup);\n    }\n    void addSeg(T a, T b, T x_left, T x_right)\n  \
    \  {\n        if (x_left >= x_right) { return; }\n        assert(m_xmin <= x_left\
    \ and x_right <= m_xsup);\n        Fixpoint([&](auto dfs, int i, T lx, T rx) ->\
    \ void {\n            if (x_left <= lx and rx <= x_right) {\n                add(L{a,\
    \ b}, i, lx, rx);\n            } else {\n                if (rx - lx == 1) { return;\
    \ }\n                auto& [li, ri] = m_nodes[i].sons;\n                const\
    \ T mx = (lx + rx) / 2;\n                if (lx < x_right and x_left < mx) {\n\
    \                    if (li == -1) { li = alloc(); }\n                    dfs(li,\
    \ lx, mx);\n                }\n                if (mx < x_right and x_left < rx)\
    \ {\n                    if (ri == -1) { ri = alloc(); }\n                   \
    \ dfs(ri, mx, rx);\n                }\n            }\n        })(0, m_xmin, m_xsup);\n\
    \    }\n    Pair<bool, L> minLine(const T x) const\n    {\n        T lx = m_xmin,\
    \ rx = m_xsup;\n        L ans = NIL;\n        for (int i = 0; i != -1;) {\n  \
    \          const auto& pl = m_nodes[i].line;\n            if (comp(pl, ans, x))\
    \ { ans = pl; }\n            const auto& [li, ri] = m_nodes[i].sons;\n       \
    \     const T mx = (lx + rx) / 2;\n            if (x < mx) {\n               \
    \ i = li;\n                rx = mx;\n            } else {\n                i =\
    \ ri;\n                lx = mx;\n            }\n        }\n        return {ans\
    \ != NIL, ans};\n    }\n\nprivate:\n    void add(L l, int i, T lx, T rx)\n   \
    \ {\n        for (;;) {\n            const auto& pl = m_nodes[i].line;\n     \
    \       const T mx = (lx + rx) / 2;\n            const bool lunder = comp(l, pl,\
    \ lx);\n            const bool runder = comp(l, pl, rx);\n            const bool\
    \ munder = comp(l, pl, mx);\n            if (munder) { std::swap(l, m_nodes[i].line);\
    \ }\n            if (rx - lx == 1) { break; }\n            if (lunder == runder)\
    \ { break; }\n            auto& [li, ri] = m_nodes[i].sons;\n            if (lunder\
    \ == munder) {\n                if (ri == -1) { ri = alloc(); }\n            \
    \    i = ri;\n                lx = mx;\n            } else {\n               \
    \ if (li == -1) { li = alloc(); }\n                i = li;\n                rx\
    \ = mx;\n            }\n        }\n    }\n    int alloc()\n    {\n        m_nodes.push_back(Node{});\n\
    \        return (int)m_nodes.size() - 1;\n    }\n    T m_xmin, m_xsup;\n    Vec<Node>\
    \ m_nodes;\n};\n"
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
  path: src/data_structure/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/li_chao_tree.hpp
layout: document
title: Li Chao Tree
---

## Li Chao Tree

### 概要

直線 $l_i(x): y = a _ i x + b _ i$ の集合 $\mathcal{L}$ について以下の操作が $\mathrm{O}(\log N)$ で行う。

- 直線追加: $\mathcal{L} \leftarrow \mathcal{L} \cup \lbrace l:y=ax+b \rbrace$
- 最小値取得: $\mathrm{argmin}_{l \in \mathcal{L}}\ l(x)$

### I/F

#### コンストラクタ

```
li_chao_tree<T, V> cht(const T xmin, const T xsup)
```

CHTを初期化する。
以下 $X = x _ {sup}-x _ {min}$

##### テンプレート引数

- `T`: $x$ 座標, 傾き, $y$ 切片の型
- `V`: $l(x)$ の型(デフォルトでは`T`と同じ)

##### 引数

- `xmin`: クエリされる $x$ 座標の最小値
- `xsup`: クエリされる $x$ 座標の最大値 + 1

##### 計算量

- $\mathrm{O}(1)$

#### add_line

```
void cht.add_line(const T a, const T b)
```

$\mathcal{L}$ に直線 $l: y=ax+b$ を追加

##### 計算量

- $\mathrm{O}(\log X)$

#### add_seg

```
void cht.add_line(const T a, const T b, const T xl, const T xr)
```

$\mathcal{L}$ に線分 $l: y=ax+b\quad (x _ l \le x \lt x _ r)$ を追加

##### 計算量

- $\mathrm{O}(\log^2 X)$


#### min_line

```
L cht.min_line(const T x)
```

返り値型 `L`: `std::pair<T, T>` 
$\mathrm{argmin}_{l \in \mathcal{L}}\ l(x)$ を取得

##### 計算量

- $\mathrm{O}(\log X)$

#### exist

```
bool cht.exist(const T x)
```

$x$ 上に線分が存在するかどうか

##### 計算量

- $\mathrm{O}(\log X)$
