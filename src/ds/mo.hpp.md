---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/misc/common.hpp
    title: src/misc/common.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/bit_ops.hpp
    title: src/misc/common/bit_ops.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/constants.hpp
    title: src/misc/common/constants.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/fixpoint.hpp
    title: src/misc/common/fixpoint.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/func_alias.hpp
    title: src/misc/common/func_alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/irange.hpp
    title: src/misc/common/irange.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/macros.hpp
    title: src/misc/common/macros.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/operator_alias.hpp
    title: src/misc/common/operator_alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/rng.hpp
    title: src/misc/common/rng.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/show.hpp
    title: src/misc/common/show.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/vec_utils.hpp
    title: src/misc/common/vec_utils.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/xoshiro.hpp
    title: src/misc/common/xoshiro.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifications/ds/mo.test.cpp
    title: verifications/ds/mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\nusing i32 = int;\nusing u32 = unsigned int;\n\
    using i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing f64 = double;\nusing f80 = long double;\nusing\
    \ f128 = __float128;\nconstexpr i32 operator\"\" _i32(u64 v)\n{\n    return v;\n\
    }\nconstexpr i32 operator\"\" _u32(u64 v)\n{\n    return v;\n}\nconstexpr i64\
    \ operator\"\" _i64(u64 v)\n{\n    return v;\n}\nconstexpr u64 operator\"\" _u64(u64\
    \ v)\n{\n    return v;\n}\nconstexpr f64 operator\"\" _f64(f80 v)\n{\n    return\
    \ v;\n}\nconstexpr f80 operator\"\" _f80(f80 v)\n{\n    return v;\n}\nusing Istream\
    \ = std::istream;\nusing Ostream = std::ostream;\nusing Str = std::string;\ntemplate<typename\
    \ T>\nusing Lt = std::less<T>;\ntemplate<typename T>\nusing Gt = std::greater<T>;\n\
    template<typename T>\nusing IList = std::initializer_list<T>;\ntemplate<int n>\n\
    using BSet = std::bitset<n>;\ntemplate<typename T1, typename T2>\nusing Pair =\
    \ std::pair<T1, T2>;\ntemplate<typename... Ts>\nusing Tup = std::tuple<Ts...>;\n\
    template<typename T, int N>\nusing Arr = std::array<T, N>;\ntemplate<typename...\
    \ Ts>\nusing Deq = std::deque<Ts...>;\ntemplate<typename... Ts>\nusing Set = std::set<Ts...>;\n\
    template<typename... Ts>\nusing MSet = std::multiset<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing USet = std::unordered_set<Ts...>;\ntemplate<typename... Ts>\nusing\
    \ UMSet = std::unordered_multiset<Ts...>;\ntemplate<typename... Ts>\nusing Map\
    \ = std::map<Ts...>;\ntemplate<typename... Ts>\nusing MMap = std::multimap<Ts...>;\n\
    template<typename... Ts>\nusing UMap = std::unordered_map<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing UMMap = std::unordered_multimap<Ts...>;\ntemplate<typename... Ts>\n\
    using Vec = std::vector<Ts...>;\ntemplate<typename... Ts>\nusing Stack = std::stack<Ts...>;\n\
    template<typename... Ts>\nusing Queue = std::queue<Ts...>;\ntemplate<typename\
    \ T>\nusing MaxHeap = std::priority_queue<T>;\ntemplate<typename T>\nusing MinHeap\
    \ = std::priority_queue<T, Vec<T>, Gt<T>>;\nusing NSec = std::chrono::nanoseconds;\n\
    using USec = std::chrono::microseconds;\nusing MSec = std::chrono::milliseconds;\n\
    using Sec = std::chrono::seconds;\ntemplate<typename T>\nconstexpr T LIMMIN =\
    \ std::numeric_limits<T>::min();\ntemplate<typename T>\nconstexpr T LIMMAX = std::numeric_limits<T>::max();\n\
    template<typename T>\nconstexpr T INF = (LIMMAX<T> - 1) / 2;\ntemplate<typename\
    \ T>\nconstexpr T PI = T{3.141592653589793238462643383279502884};\ntemplate<typename\
    \ T = u64>\nconstexpr T TEN(const int n)\n{\n    return n == 0 ? T{1} : TEN<T>(n\
    \ - 1) * T{10};\n}\nOstream& operator<<(Ostream& os, i128 v)\n{\n    bool minus\
    \ = false;\n    if (v < 0) { minus = true, v = -v; }\n    Str ans;\n    if (v\
    \ == 0) { ans = \"0\"; }\n    while (v) {\n        ans.push_back('0' + v % 10),\
    \ v /= 10;\n    }\n    std::reverse(ans.begin(), ans.end());\n    return os <<\
    \ (minus ? \"-\" : \"\") << ans;\n}\nOstream& operator<<(Ostream& os, u128 v)\n\
    {\n    Str ans;\n    if (v == 0) { ans = \"0\"; }\n    while (v) {\n        ans.push_back('0'\
    \ + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(), ans.end());\n    return\
    \ os << ans;\n}\ntemplate<typename T>\nbool chmin(T& a, const T& b)\n{\n    if\
    \ (a > b) {\n        a = b;\n        return true;\n    } else {\n        return\
    \ false;\n    }\n}\ntemplate<typename T>\nbool chmax(T& a, const T& b)\n{\n  \
    \  if (a < b) {\n        a = b;\n        return true;\n    } else {\n        return\
    \ false;\n    }\n}\ntemplate<typename T>\nconstexpr T floorDiv(T x, T y)\n{\n\
    \    if (y < T{}) { x = -x, y = -y; }\n    return x >= T{} ? x / y : (x - y +\
    \ 1) / y;\n}\ntemplate<typename T>\nconstexpr T ceilDiv(T x, T y)\n{\n    if (y\
    \ < T{}) { x = -x, y = -y; }\n    return x >= T{} ? (x + y - 1) / y : x / y;\n\
    }\ntemplate<typename T, typename I>\nconstexpr T modPower(T v, I n, T mod)\n{\n\
    \    T ans = 1 % mod;\n    for (; n > 0; n >>= 1, (v *= v) %= mod) {\n       \
    \ if (n % 2 == 1) { (ans *= v) %= mod; }\n    }\n    return ans;\n}\ntemplate<typename\
    \ T, typename I>\nconstexpr T power(T v, I n)\n{\n    T ans = 1;\n    for (; n\
    \ > 0; n >>= 1, v *= v) {\n        if (n % 2 == 1) { ans *= v; }\n    }\n    return\
    \ ans;\n}\ntemplate<typename T, typename I>\nconstexpr T power(T v, I n, const\
    \ T& e)\n{\n    T ans = e;\n    for (; n > 0; n >>= 1, v *= v) {\n        if (n\
    \ % 2 == 1) { ans *= v; }\n    }\n    return ans;\n}\ntemplate<typename T>\nVec<T>\
    \ operator+=(Vec<T>& vs1, const Vec<T>& vs2)\n{\n    vs1.insert(vs1.end(), vs2.begin(),\
    \ vs2.end());\n    return vs1;\n}\ntemplate<typename T>\nVec<T> operator+(const\
    \ Vec<T>& vs1, const Vec<T>& vs2)\n{\n    auto vs = vs1;\n    vs += vs2;\n   \
    \ return vs;\n}\ntemplate<typename T>\nvoid fillAll(Vec<T>& vs, const T& v)\n\
    {\n    std::fill(vs.begin(), vs.end(), v);\n}\ntemplate<typename T, typename C\
    \ = Lt<T>>\nvoid sortAll(Vec<T>& vs, C comp = C{})\n{\n    std::sort(vs.begin(),\
    \ vs.end(), comp);\n}\ntemplate<typename T>\nvoid reverseAll(Vec<T>& vs)\n{\n\
    \    std::reverse(vs.begin(), vs.end());\n}\ntemplate<typename T>\nvoid uniqueAll(Vec<T>&\
    \ vs)\n{\n    sortAll(vs);\n    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());\n\
    }\ntemplate<typename T, typename V = T>\nV sumAll(const Vec<T>& vs)\n{\n    return\
    \ std::accumulate(vs.begin(), vs.end(), V{});\n}\ntemplate<typename T>\nint minInd(const\
    \ Vec<T>& vs)\n{\n    return std::min_element(vs.begin(), vs.end()) - vs.begin();\n\
    }\ntemplate<typename T>\nint maxInd(const Vec<T>& vs)\n{\n    return std::max_element(vs.begin(),\
    \ vs.end()) - vs.begin();\n}\ntemplate<typename T>\nint lbInd(const Vec<T>& vs,\
    \ const T& v)\n{\n    return std::lower_bound(vs.begin(), vs.end(), v) - vs.begin();\n\
    }\ntemplate<typename T>\nint ubInd(const Vec<T>& vs, const T& v)\n{\n    return\
    \ std::upper_bound(vs.begin(), vs.end(), v) - vs.begin();\n}\ntemplate<typename\
    \ T, typename F>\nVec<T> genVec(int n, F gen)\n{\n    Vec<T> ans;\n    std::generate_n(std::back_insert_iterator(ans),\
    \ n, gen);\n    return ans;\n}\nVec<int> iotaVec(int n, int offset = 0)\n{\n \
    \   Vec<int> ans(n);\n    std::iota(ans.begin(), ans.end(), offset);\n    return\
    \ ans;\n}\ntemplate<typename T>\nVec<T> revVec(const Vec<T>& vs)\n{\n    auto\
    \ ans = vs;\n    reverseAll(ans);\n    return ans;\n}\nconstexpr int popcount(const\
    \ u64 v)\n{\n    return v ? __builtin_popcountll(v) : 0;\n}\nconstexpr int log2p1(const\
    \ u64 v)\n{\n    return v ? 64 - __builtin_clzll(v) : 0;\n}\nconstexpr int lsbp1(const\
    \ u64 v)\n{\n    return __builtin_ffsll(v);\n}\nconstexpr int clog(const u64 v)\n\
    {\n    return v ? log2p1(v - 1) : 0;\n}\nconstexpr u64 ceil2(const u64 v)\n{\n\
    \    const int l = clog(v);\n    return (l == 64) ? 0_u64 : (1_u64 << l);\n}\n\
    constexpr u64 floor2(const u64 v)\n{\n    return v ? (1_u64 << (log2p1(v) - 1))\
    \ : 0_u64;\n}\nconstexpr bool ispow2(const u64 v)\n{\n    return (v > 0) and ((v\
    \ & (v - 1)) == 0);\n}\nconstexpr bool btest(const u64 mask, const int ind)\n\
    {\n    return (mask >> ind) & 1_u64;\n}\ntemplate<typename F>\nstruct Fix : F\n\
    {\n    Fix(F&& f) : F{std::forward<F>(f)} {}\n    template<typename... Args>\n\
    \    auto operator()(Args&&... args) const\n    {\n        return F::operator()(*this,\
    \ std::forward<Args>(args)...);\n    }\n};\nclass irange\n{\nprivate:\n    struct\
    \ itr\n    {\n        itr(i64 start = 0, i64 step = 1) : m_cnt{start}, m_step{step}\
    \ {}\n        bool operator!=(const itr& it) const\n        {\n            return\
    \ m_cnt != it.m_cnt;\n        }\n        int operator*()\n        {\n        \
    \    return m_cnt;\n        }\n        itr& operator++()\n        {\n        \
    \    m_cnt += m_step;\n            return *this;\n        }\n        i64 m_cnt,\
    \ m_step;\n    };\n    i64 m_start, m_end, m_step;\npublic:\n    irange(i64 start,\
    \ i64 end, i64 step = 1)\n    {\n        assert(step != 0);\n        const i64\
    \ d = std::abs(step);\n        const i64 l = (step > 0 ? start : end);\n     \
    \   const i64 r = (step > 0 ? end : start);\n        int n = (r - l) / d + ((r\
    \ - l) % d ? 1 : 0);\n        if (l >= r) { n = 0; }\n        m_start = start;\n\
    \        m_end = start + step * n;\n        m_step = step;\n    }\n    itr begin()\
    \ const\n    {\n        return itr{m_start, m_step};\n    }\n    itr end() const\n\
    \    {\n        return itr{m_end, m_step};\n    }\n};\nirange rep(int end)\n{\n\
    \    return irange(0, end, 1);\n}\nirange per(int rend)\n{\n    return irange(rend\
    \ - 1, -1, -1);\n}\n#pragma COMMENT(\"[REFS] Xoshiro: https://prng.di.unimi.it\"\
    )\nnamespace xoshiro_impl {\nu64 x;\nu64 next()\n{\n    uint64_t z = (x += 0x9e3779b97f4a7c15);\n\
    \    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;\n\
    \    return z ^ (z >> 31);\n}\n}\nclass Xoshiro32\n{\npublic:\n    using result_type\
    \ = u32;\n    using T = result_type;\n    Xoshiro32(T seed = 0)\n    {\n     \
    \   xoshiro_impl::x = seed;\n        s[0] = xoshiro_impl::next();\n        s[1]\
    \ = xoshiro_impl::next();\n        s[2] = xoshiro_impl::next();\n        s[3]\
    \ = xoshiro_impl::next();\n    }\n    static constexpr T min()\n    {\n      \
    \  return LIMMIN<T>;\n    }\n    static constexpr T max()\n    {\n        return\
    \ LIMMAX<T>;\n    }\n    T operator()()\n    {\n        return next();\n    }\n\
    private:\n    static constexpr T rotl(const T x, int k)\n    {\n        return\
    \ (x << k) | (x >> (32 - k));\n    }\n    T next()\n    {\n        const T ans\
    \ = rotl(s[1] * 5, 7) * 9;\n        const T t = s[1] << 9;\n        s[2] ^= s[0];\n\
    \        s[3] ^= s[1];\n        s[1] ^= s[2];\n        s[0] ^= s[3];\n       \
    \ s[2] ^= t;\n        s[3] = rotl(s[3], 11);\n        return ans;\n    }\n   \
    \ T s[4];\n};\nclass Xoshiro64\n{\npublic:\n    using result_type = u64;\n   \
    \ using T = result_type;\n    Xoshiro64(T seed = 0)\n    {\n        xoshiro_impl::x\
    \ = seed;\n        s[0] = xoshiro_impl::next();\n        s[1] = xoshiro_impl::next();\n\
    \        s[2] = xoshiro_impl::next();\n        s[3] = xoshiro_impl::next();\n\
    \    }\n    static constexpr T min()\n    {\n        return LIMMIN<T>;\n    }\n\
    \    static constexpr T max()\n    {\n        return LIMMAX<T>;\n    }\n    T\
    \ operator()()\n    {\n        return next();\n    }\nprivate:\n    static constexpr\
    \ T rotl(const T x, int k)\n    {\n        return (x << k) | (x >> (64 - k));\n\
    \    }\n    T next()\n    {\n        const T ans = rotl(s[1] * 5, 7) * 9;\n  \
    \      const T t = s[1] << 17;\n        s[2] ^= s[0];\n        s[3] ^= s[1];\n\
    \        s[1] ^= s[2];\n        s[0] ^= s[3];\n        s[2] ^= t;\n        s[3]\
    \ = rotl(s[3], 45);\n        return ans;\n    }\n    T s[4];\n};\ntemplate<typename\
    \ Rng>\nclass RNG\n{\npublic:\n    using result_type = typename Rng::result_type;\n\
    \    using T = result_type;\n    static constexpr T min()\n    {\n        return\
    \ Rng::min();\n    }\n    static constexpr T max()\n    {\n        return Rng::max();\n\
    \    }\n    RNG() : RNG(std::random_device{}()) {}\n    RNG(T seed) : m_rng(seed)\
    \ {}\n    T operator()()\n    {\n        return m_rng();\n    }\n    template<typename\
    \ T>\n    T val(T min, T max)\n    {\n        return std::uniform_int_distribution<T>(min,\
    \ max)(m_rng);\n    }\n    template<typename T>\n    Pair<T, T> pair(T min, T\
    \ max)\n    {\n        return std::minmax({val<T>(min, max), val<T>(min, max)});\n\
    \    }\n    template<typename T>\n    Vec<T> vec(int n, T min, T max)\n    {\n\
    \        return genVec<T>(n, [&]() { return val<T>(min, max); });\n    }\n   \
    \ template<typename T>\n    Vec<Vec<T>> vvec(int n, int m, T min, T max)\n   \
    \ {\n        return genVec<Vec<T>>(n, [&]() { return vec(m, min, max); });\n \
    \   }\nprivate:\n    Rng m_rng;\n};\nRNG<std::mt19937> rng;\nRNG<std::mt19937_64>\
    \ rng64;\nRNG<Xoshiro32> rng_xo;\nRNG<Xoshiro64> rng_xo64;\ntemplate<int block_size>\n\
    class Mo\n{\npublic:\n    Mo(const Vec<int>& xs, const Vec<int>& ys)\n       \
    \ : m_xs{xs}, m_ys{ys}, m_is{iotaVec(m_xs.size())}\n    {\n        sortAll(m_is,\
    \ [&](int i, int j) {\n            const int ib = m_xs[i] / block_size;\n    \
    \        const int jb = m_xs[j] / block_size;\n            return ib != jb ? ib\
    \ < jb\n                            : (ib % 2 ? m_ys[j] < m_ys[i] : m_ys[i] <\
    \ m_ys[j]);\n        });\n    }\n    template<typename R, typename L, typename\
    \ D, typename U>\n    int next(R right, L left, D down, U up)\n    {\n       \
    \ assert(m_ii < (int)m_is.size());\n        const int i = m_is[m_ii++];\n    \
    \    const int nx = m_xs[i], ny = m_ys[i];\n        for (; m_x < nx; m_x++) {\n\
    \            right(m_x, m_y);\n        }\n        for (; m_x > nx; m_x--) {\n\
    \            left(m_x, m_y);\n        }\n        for (; m_y < ny; m_y++) {\n \
    \           down(m_x, m_y);\n        }\n        for (; m_y > ny; m_y--) {\n  \
    \          up(m_x, m_y);\n        }\n        return i;\n    }\nprivate:\n    int\
    \ m_ii = 0;\n    int m_x = 0, m_y = 0;\n    Vec<int> m_xs, m_ys;\n    Vec<int>\
    \ m_is;\n};\n"
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<int block_size>\n\
    class Mo\n{\npublic:\n    Mo(const Vec<int>& xs, const Vec<int>& ys)\n       \
    \ : m_xs{xs}, m_ys{ys}, m_is{iotaVec(m_xs.size())}\n    {\n        sortAll(m_is,\
    \ [&](int i, int j) {\n            const int ib = m_xs[i] / block_size;\n    \
    \        const int jb = m_xs[j] / block_size;\n            return ib != jb ? ib\
    \ < jb\n                            : (ib % 2 ? m_ys[j] < m_ys[i] : m_ys[i] <\
    \ m_ys[j]);\n        });\n    }\n    template<typename R, typename L, typename\
    \ D, typename U>\n    int next(R right, L left, D down, U up)\n    {\n       \
    \ assert(m_ii < (int)m_is.size());\n        const int i = m_is[m_ii++];\n    \
    \    const int nx = m_xs[i], ny = m_ys[i];\n        for (; m_x < nx; m_x++) {\n\
    \            right(m_x, m_y);\n        }\n        for (; m_x > nx; m_x--) {\n\
    \            left(m_x, m_y);\n        }\n        for (; m_y < ny; m_y++) {\n \
    \           down(m_x, m_y);\n        }\n        for (; m_y > ny; m_y--) {\n  \
    \          up(m_x, m_y);\n        }\n        return i;\n    }\n\nprivate:\n  \
    \  int m_ii = 0;\n    int m_x = 0, m_y = 0;\n    Vec<int> m_xs, m_ys;\n    Vec<int>\
    \ m_is;\n};\n"
  dependsOn:
  - src/misc/common.hpp
  - src/misc/common/macros.hpp
  - src/misc/common/type_alias.hpp
  - src/misc/common/constants.hpp
  - src/misc/common/func_alias.hpp
  - src/misc/common/show.hpp
  - src/misc/common/print/int128_t.hpp
  - src/misc/common/operator_alias.hpp
  - src/misc/common/vec_utils.hpp
  - src/misc/common/bit_ops.hpp
  - src/misc/common/fixpoint.hpp
  - src/misc/common/irange.hpp
  - src/misc/common/rng.hpp
  - src/misc/common/xoshiro.hpp
  isVerificationFile: false
  path: src/ds/mo.hpp
  requiredBy: []
  timestamp: '2021-09-03 16:07:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifications/ds/mo.test.cpp
documentation_of: src/ds/mo.hpp
layout: document
title: Mo's Algorithm
---

## 概要

$N$ 個の 二次元格子点 $P _ i = (x _ i, y _ i)$ が与えられる。以下これをターミナルという。  
また $0 \le x _ i, y _ i \lt L$ であるとする。

$(0,0)$ からスタートして隣り合う格子点に移動することを繰り返して、ターミナル集合 $\lbrace P _ 0, \dots, P _ {N-1} \rbrace$ をすべてたどることを考える(たどる順番は何でも良い)。  
ブロックサイズ $B$ ごとにブロック分けして $\lbrace P _ 0, \dots, P _ {N-1} \rbrace$ をたどる順番をいい感じにすると、移動回数を $\mathrm{O}(BN+\frac{L^2}{B})$ にできる。  
$B = \sqrt{\frac{L^2}{N}}$ に設定することで、移動回数は $\mathrm{O}(L\sqrt{N})$ になる。

![Mo's algorithm](https://pachicobue.github.io/algolib/mo.png)

この話を応用すると、連続部分列に対する オフラインクエリ みたいなものに適用できる。  

### 例：静的数列の区間種類数クエリ

数列 $A = \lbrace A _ 0, \dots, A _ {N-1} \rbrace$ に対して、以下のようなクエリ $Q$ 個に答える(オフライン)。  

- $(l,r)$ : $\lbrace A _ l, \dots, A _ {r-1} \rbrace$ の値の種類数を出力

半開区間 $\lbrace A _ x, \dots, A _ {y-1}\rbrace$ を 格子点 $(y,x)$ と対応させると、隣の格子点に移動することは区間を1だけ伸縮させることに対応する。  
以下の4種類の移動を実装すればいい。

- $(x,y) \rightarrow (x+1, y)$: $A _ {x}$ を削除
- $(x,y) \rightarrow (x-1, y)$: $A _ {x-1}$ を挿入
- $(x,y) \rightarrow (x, y+1)$: $A _ {y}$ を挿入 
- $(x,y) \rightarrow (x, y-1)$: $A _ {y-1}$ を削除

(値，個数)の集合,値の種類数 を管理しつつ、要素の 挿入/削除 を捌けばいい。  
これは $\mathrm{O}(1)$ で更新できるので、この問題は $\mathrm{O}(N\sqrt{N})$ で解ける。

## I/F

### コンストラクタ

```cpp
Mo<B> mo(const Vec<int>& xs, const Vec<int>& ys)
```

ターミナル $P_i$ の $x$座標,$y$座標を初期化する。  
内部でたどるべき順番に並べ替えて保持する。

- `B`: ブロックサイズ( $L$ の値から適切に設定する)
  - 基本的に $\sqrt{L}$ 辺りに設定すればよい


#### 計算量

$\mathrm{O}(N \log N)$

### next

```cpp
int mo.next(R right, L left, D down, U up)
```

次のターミナルまで移動する。  
返り値は到達したターミナル番号

- right: $(x,y) \rightarrow (x+1,y)$ の移動処理
- left: $(x,y) \rightarrow (x-1,y)$ の移動処理
- down: $(x,y) \rightarrow (x,y+1)$ の移動処理
- up: $(x,y) \rightarrow (x,y-1)$ の移動処理

#### 計算量

最悪 $\mathrm{O}(L)$  
但し $N$ 回の移動で合計 $\mathrm{O}(BL+\frac{L^2}{B})$
