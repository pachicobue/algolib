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
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<int block_size> class\
    \ Mo\n{\npublic:\n    Mo(const Vec<int>& xs, const Vec<int>& ys)\n        : m_xs{xs},\
    \ m_ys{ys}, m_is(m_xs.size())\n    {\n        iotaAll(m_is);\n        sortAll(m_is,\
    \ [&](int i, int j) {\n            const int ib = m_xs[i] / block_size;\n    \
    \        const int jb = m_xs[j] / block_size;\n            return ib != jb ? ib\
    \ < jb : m_ys[i] < m_ys[j];\n        });\n    }\n    template<typename R, typename\
    \ L, typename D, typename U>\n    int next(R right, L left, D down, U up)\n  \
    \  {\n        assert(m_ii < (int)m_is.size());\n        const int i = m_is[m_ii++];\n\
    \        const int nx = m_xs[i], ny = m_ys[i];\n        for (; m_x < nx; m_x++)\
    \ {\n            right(m_x, m_y);\n        }\n        for (; m_x > nx; m_x--)\
    \ {\n            left(m_x, m_y);\n        }\n        for (; m_y < ny; m_y++) {\n\
    \            down(m_x, m_y);\n        }\n        for (; m_y > ny; m_y--) {\n \
    \           up(m_x, m_y);\n        }\n        return i;\n    }\nprivate:\n   \
    \ int m_ii = 0;\n    int m_x = 0, m_y = 0;\n    Vec<int> m_xs, m_ys;\n    Vec<int>\
    \ m_is;\n};\n"
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
  path: src/data_structure/mo.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/mo.hpp
layout: document
title: Mo's Algorithm
---

## Mo's Algorithm

### 概要

$N$ 個の 二次元格子点 $P _ i = (x _ i, y _ i)$ が与えられる。以下これをターミナルという。  
また $0 \le x _ i, y _ i \lt L$ であるとする。

$(0,0)$ からスタートして隣り合う格子点に移動することを繰り返して、ターミナル集合 $\lbrace P _ 0, \dots, P _ {N-1} \rbrace$ をすべてたどることを考える(たどる順番は何でも良い)。  
ブロックサイズ $B$ ごとにブロック分けして $\lbrace P _ 0, \dots, P _ {N-1} \rbrace$ をたどる順番をいい感じにすると、移動回数を $\mathrm{O}(BN+\frac{L^2}{B})$ にできる。  
$B = \sqrt{\frac{L^2}{N}}$ に設定することで、移動回数は $\mathrm{O}(L\sqrt{N})$ になる。

![Mo's algorithm](/algolib/data_structure/mo.png)

この話を応用すると、連続部分列に対する オフラインクエリ みたいなものに適用できる。  
<u>(例) 静的数列の区間種類数クエリ</u>  
数列 $A = \lbrace A _ 0, \dots, A _ {N-1} \rbrace$ に対して、以下のようなクエリが $Q$ 個飛んでくる。  

- $(l,r)$ : $\lbrace A _ l, \dots, A _ {r-1} \rbrace$ の値の種類数を出力

このクエリはオフラインで与えられる。  

座標 $(x,y)$ のことを $\lbrace A _ x, \dots, A _ {y-1}\rbrace$ と捉えると、隣の格子点に移動することは区間を1だけ伸縮させることに対応する。  
以下の4種類の移動を実装すればいい。

- $(x,y) \rightarrow (x+1, y)$: $A _ {x}$ を削除
- $(x,y) \rightarrow (x-1, y)$: $A _ {x-1}$ を挿入
- $(x,y) \rightarrow (x, y+1)$: $A _ {y}$ を挿入 
- $(x,y) \rightarrow (x, y-1)$: $A _ {y-1}$ を削除

(値，個数)の集合,値の種類数 を管理しつつ、要素の 挿入/削除 を捌けばいい。  
これは $\mathrm{O}(1)$ でできるので、この問題は $\mathrm{O}(N\sqrt{N})$ で解ける。

### I/F

#### コンストラクタ

```
mo_iterator<B> mo(const std::vector<int>& xs, const std::vector<int>& ys)
```

ターミナル $(x _ i, y _ i)$ を配置。  
内部でたどるべき順番に並べ替えて保持する。

- `B`: ブロックサイズ


##### 計算量

- $\mathrm{O}(N \log N)$

#### next

```
int mo.next<R,L,D,U>(R right, L left, D down, U up)
```

次のターミナルまで移動する。  
返り値は到達したターミナル番号

##### 入力

- `right`: $(x,y)\rightarrow (x+1,y)$ の移動処理 
- `left`: $(x,y)\rightarrow (x-1,y)$ の移動処理 
- `down`: $(x,y)\rightarrow (x,y+1)$ の移動処理 
- `up`: $(x,y)\rightarrow (x,y-1)$ の移動処理 

##### 計算量

- $\mathrm{O}(L)$

但し $N$ 回の移動で合計 $\mathrm{O}(BL+\frac{L^2}{B})$ になる。
