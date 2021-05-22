---
data:
  _extendedDependsOn: []
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
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: misc/common.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"./misc/common.hpp\"\ntemplate<typename T> class\
    \ MonotonicCHT\n{\n    using L = Pair<T, T>;\n    static constexpr L NIL = {0,\
    \ INF<T>};\n    static bool needLess(const L& l1, const L& l2, const L& l3)\n\
    \    {\n        const auto [a1, b1] = l1;\n        const auto [a2, b2] = l2;\n\
    \        const auto [a3, b3] = l3;\n        const T x12 = fdiv(b2 - b1, a1 - a2),\
    \ x23 = fdiv(b3 - b2, a2 - a3);\n        return x12 >= x23;\n    }\n    static\
    \ bool comp(const L& l1, const L& l2, T x)\n    {\n        const auto [a1, b1]\
    \ = l1;\n        const auto [a2, b2] = l2;\n        if (a1 == a2) {\n        \
    \    return b1 <= b2;\n        } else if (a1 > a2) {\n            return x <=\
    \ fdiv(b2 - b1, a1 - a2);\n        } else {\n            return fdiv(b1 - b2,\
    \ a2 - a1) < x;\n        }\n    }\npublic:\n    MonotonicCHT(bool query_inc =\
    \ true)\n        : m_query_inc{query_inc}, m_prev_x{m_query_inc ? -INF<T> : INF<T>}\n\
    \    {}\n    void addLine(T a, T b)\n    {\n        const L l{a, b};\n       \
    \ if (m_lines.empty()) {\n            m_lines.push_back(l);\n            return;\n\
    \        }\n        auto& [Ma, Mb] = m_lines.front();\n        auto& [ma, mb]\
    \ = m_lines.back();\n        assert(a <= ma or Ma <= a);\n        if (a <= ma)\
    \ {\n            if (a == ma) {\n                chmin(mb, b);\n            }\
    \ else {\n                while (m_lines.size() >= 2) {\n                    const\
    \ int n = m_lines.size();\n                    const auto& l0 = m_lines[n - 2];\n\
    \                    const auto& l1 = m_lines[n - 1];\n                    if\
    \ (not needLess(l0, l1, l)) { break; }\n                    m_lines.pop_back();\n\
    \                }\n                m_lines.push_back(l);\n            }\n   \
    \     } else {\n            if (Ma == a) {\n                chmin(Mb, b);\n  \
    \          } else {\n                while (m_lines.size() >= 2) {\n         \
    \           const auto& l1 = m_lines[0];\n                    const auto& l2 =\
    \ m_lines[1];\n                    if (not needLess(l, l1, l2)) { break; }\n \
    \                   m_lines.pop_front();\n                }\n                m_lines.push_front(l);\n\
    \            }\n        }\n    }\n    L minLine(const T x)\n    {\n        if\
    \ (m_lines.empty()) { return NIL; }\n        if (m_query_inc) {\n            assert(m_prev_x\
    \ <= x);\n            m_prev_x = x;\n            while (m_lines.size() >= 2) {\n\
    \                const auto& l0 = m_lines[0];\n                const auto& l1\
    \ = m_lines[1];\n                if (comp(l0, l1, x)) { break; }\n           \
    \     m_lines.pop_front();\n            }\n            return m_lines.front();\n\
    \        } else {\n            assert(x <= m_prev_x);\n            m_prev_x =\
    \ x;\n            while (m_lines.size() >= 2) {\n                const int n =\
    \ m_lines.size();\n                const auto& l0 = m_lines[n - 2];\n        \
    \        const auto& l1 = m_lines[n - 1];\n                if (not comp(l0, l1,\
    \ x)) { break; }\n                m_lines.pop_back();\n            }\n       \
    \     return m_lines.back();\n        }\n    }\nprivate:\n    bool m_query_inc;\n\
    \    T m_prev_x;\n    Deq<L> m_lines;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/monotonic_cht.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/monotonic_cht.hpp
layout: document
title: "\u533A\u9593\u3092map\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
---

## 区間をmapで管理するやつ

### 概要

数直線が初め色0で塗られている。  
ここから以下の操作を行う 

- 半開区間 $[l,r)$ を色1 で塗る
- 半開区間 $[l,r)$ を色0 で塗る
- $x$ が 色1で塗られているなら、$x$を含む色1の半開区間を取得

色1で塗った操作の回数 $N$ に対して、これらの操作を ならし$\mathrm{O}(\log N)$ で行える。

### I/F

#### コンストラクタ

```
ranges<T> rs()
```

- `T`: 座標の型(符号付き整数しか対応していない)

#### insert

```
void rs.insert(T l, T r)
```

$[l,r)$ に色1を塗る

##### 計算量

- $\mathrm{O}(\log N)$ amortized

#### erase

```
void rs.erase(T l, T r)
```

$[l,r)$ に色0を塗る

##### 計算量

- $\mathrm{O}(\log N)$ amortized

#### support

```
std::pair<bool, std::pair<T,T>> rs.support(T x)
```

($x$ が色1で塗られているか, $x$ が含まれる色1の半開区間)

##### 計算量

- $\mathrm{O}(\log N)$

#### data

```
std::map<T,T> rs.data()
```

内部で保持しているmapへの参照  
色1 の半開区間$[l,r)$ に対して、`map[l] = r` となっている

##### 計算量

- $\mathrm{O}(1)$

#### 出力

```
std::cout << rs << std::endl
```
