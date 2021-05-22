---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/misc/common/func_alias.hpp
    title: src/misc/common/func_alias.hpp
  - icon: ':warning:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  - icon: ':warning:'
    path: src/misc/common/xoshiro.hpp
    title: src/misc/common/xoshiro.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/ds_table.hpp
    title: Disjoint Sparse Table
  - icon: ':warning:'
    path: src/data_structure/dsu.hpp
    title: src/data_structure/dsu.hpp
  - icon: ':warning:'
    path: src/data_structure/dualseg.hpp
    title: Dual Segment Tree
  - icon: ':warning:'
    path: src/data_structure/fenwick.hpp
    title: Fenwick Tree
  - icon: ':warning:'
    path: src/data_structure/intdict.hpp
    title: src/data_structure/intdict.hpp
  - icon: ':warning:'
    path: src/data_structure/intset.hpp
    title: src/data_structure/intset.hpp
  - icon: ':warning:'
    path: src/data_structure/lazyseg.hpp
    title: Lazy Segment Tree
  - icon: ':warning:'
    path: src/data_structure/li_chao_tree.hpp
    title: Li Chao Tree
  - icon: ':warning:'
    path: src/data_structure/mo.hpp
    title: Mo's Algorithm
  - icon: ':warning:'
    path: src/data_structure/segments.hpp
    title: src/data_structure/segments.hpp
  - icon: ':warning:'
    path: src/data_structure/segtree.hpp
    title: src/data_structure/segtree.hpp
  - icon: ':warning:'
    path: src/data_structure/static_rmq.hpp
    title: src/data_structure/static_rmq.hpp
  - icon: ':warning:'
    path: src/data_structure/static_rsq.hpp
    title: src/data_structure/static_rsq.hpp
  - icon: ':warning:'
    path: src/data_structure/swag.hpp
    title: src/data_structure/swag.hpp
  - icon: ':warning:'
    path: src/data_structure/wavelet.hpp
    title: src/data_structure/wavelet.hpp
  - icon: ':warning:'
    path: src/flow/max_flow.hpp
    title: src/flow/max_flow.hpp
  - icon: ':warning:'
    path: src/flow/mincost_flow.hpp
    title: src/flow/mincost_flow.hpp
  - icon: ':warning:'
    path: src/graph/bcc.hpp
    title: src/graph/bcc.hpp
  - icon: ':warning:'
    path: src/graph/bellman_ford.hpp
    title: src/graph/bellman_ford.hpp
  - icon: ':warning:'
    path: src/graph/centroid_decomp.hpp
    title: src/graph/centroid_decomp.hpp
  - icon: ':warning:'
    path: src/graph/diameter.hpp
    title: src/graph/diameter.hpp
  - icon: ':warning:'
    path: src/graph/dijkstra.hpp
    title: src/graph/dijkstra.hpp
  - icon: ':warning:'
    path: src/graph/graph.hpp
    title: src/graph/graph.hpp
  - icon: ':warning:'
    path: src/graph/hld.hpp
    title: src/graph/hld.hpp
  - icon: ':warning:'
    path: src/graph/lca.hpp
    title: src/graph/lca.hpp
  - icon: ':warning:'
    path: src/graph/level_ancestor.hpp
    title: src/graph/level_ancestor.hpp
  - icon: ':warning:'
    path: src/graph/lowlink.hpp
    title: src/graph/lowlink.hpp
  - icon: ':warning:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  - icon: ':warning:'
    path: src/graph/top_sort.hpp
    title: src/graph/top_sort.hpp
  - icon: ':warning:'
    path: src/graph/warshall_floyd.hpp
    title: src/graph/warshall_floyd.hpp
  - icon: ':warning:'
    path: src/linear/array_matrix.hpp
    title: src/linear/array_matrix.hpp
  - icon: ':warning:'
    path: src/linear/bit_gauss_jordan.hpp
    title: src/linear/bit_gauss_jordan.hpp
  - icon: ':warning:'
    path: src/linear/bit_matrix.hpp
    title: src/linear/bit_matrix.hpp
  - icon: ':warning:'
    path: src/linear/gauss_jordan.hpp
    title: src/linear/gauss_jordan.hpp
  - icon: ':warning:'
    path: src/linear/matrix.hpp
    title: src/linear/matrix.hpp
  - icon: ':warning:'
    path: src/math/moddint.hpp
    title: src/math/moddint.hpp
  - icon: ':warning:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
  - icon: ':warning:'
    path: src/math/set_zeta.hpp
    title: src/math/set_zeta.hpp
  - icon: ':warning:'
    path: src/misc/common.hpp
    title: src/misc/common.hpp
  - icon: ':warning:'
    path: src/misc/fastio/printer.hpp
    title: src/misc/fastio/printer.hpp
  - icon: ':warning:'
    path: src/misc/fastio/scanner.hpp
    title: src/misc/fastio/scanner.hpp
  - icon: ':warning:'
    path: src/misc/printer.hpp
    title: src/misc/printer.hpp
  - icon: ':warning:'
    path: src/misc/scanner.hpp
    title: src/misc/scanner.hpp
  - icon: ':warning:'
    path: src/misc/stopwatch.hpp
    title: src/misc/stopwatch.hpp
  - icon: ':warning:'
    path: src/misc/zipper.hpp
    title: src/misc/zipper.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/misc/common/type_alias.hpp\"\n#include <bits/stdc++.h>\n\
    #pragma region TypeAlias\nusing i32 = int;\nusing u32 = unsigned int;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\nusing f64 = double;\nusing f80 = long double;\nusing f128\
    \ = __float128;\nconstexpr i32 operator\"\" _i32(u64 v)\n{\n    return v;\n}\n\
    constexpr u32 operator\"\" _u32(u64 v)\n{\n    return v;\n}\nconstexpr i64 operator\"\
    \" _i64(u64 v)\n{\n    return v;\n}\nconstexpr u64 operator\"\" _u64(u64 v)\n\
    {\n    return v;\n}\nconstexpr f64 operator\"\" _f64(f80 v)\n{\n    return v;\n\
    }\nconstexpr f80 operator\"\" _f80(f80 v)\n{\n    return v;\n}\nusing Istream\
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
    \ = std::priority_queue<T, Vec<T>, Gt<T>>;\n#pragma endregion\n#line 3 \"src/misc/common/func_alias.hpp\"\
    \n#pragma region FuncAlias\ntemplate<typename T>\nbool chmin(T& a, const T& b)\n\
    {\n    if (a > b) {\n        a = b;\n        return true;\n    } else {\n    \
    \    return false;\n    }\n}\ntemplate<typename T>\nbool chmax(T& a, const T&\
    \ b)\n{\n    if (a < b) {\n        a = b;\n        return true;\n    } else {\n\
    \        return false;\n    }\n}\ntemplate<typename T>\nT fdiv(T x, T y)\n{\n\
    \    if (y < T{}) { x = -x, y = -y; }\n    return x >= T{} ? x / y : (x - y +\
    \ 1) / y;\n}\ntemplate<typename T>\nT cdiv(T x, T y)\n{\n    if (y < T{}) { x\
    \ = -x, y = -y; }\n    return x >= T{} ? (x + y - 1) / y : x / y;\n}\ntemplate<typename\
    \ T, typename I>\nT power(T v, I n)\n{\n    T ans = 1;\n    for (; n > 0; n >>=\
    \ 1, v *= v) {\n        if (n % 2 == 1) { ans *= v; }\n    }\n    return ans;\n\
    }\ntemplate<typename T, typename I>\nT power(T v, I n, const T& e)\n{\n    T ans\
    \ = e;\n    for (; n > 0; n >>= 1, v *= v) {\n        if (n % 2 == 1) { ans *=\
    \ v; }\n    }\n    return ans;\n}\ntemplate<typename T>\nvoid fillAll(Vec<T>&\
    \ vs, const T& v)\n{\n    std::fill(vs.begin(), vs.end(), v);\n}\ntemplate<typename\
    \ T, typename C = Lt<T>>\nvoid sortAll(Vec<T>& vs, C comp = C{})\n{\n    std::sort(vs.begin(),\
    \ vs.end(), comp);\n}\ntemplate<typename T>\nvoid reverseAll(Vec<T>& vs)\n{\n\
    \    std::reverse(vs.begin(), vs.end());\n}\ntemplate<typename T>\nvoid uniqueAll(Vec<T>&\
    \ vs)\n{\n    sortAll(vs);\n    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());\n\
    }\ntemplate<typename T>\nvoid iotaAll(Vec<T>& vs, T offset = T{})\n{\n    std::iota(vs.begin(),\
    \ vs.end(), offset);\n}\ntemplate<typename T, typename V = T>\nV sumAll(const\
    \ Vec<T>& vs)\n{\n    return std::accumulate(vs.begin(), vs.end(), V{});\n}\n\
    template<typename T>\nint minInd(const Vec<T>& vs)\n{\n    return std::min_element(vs.begin(),\
    \ vs.end()) - vs.begin();\n}\ntemplate<typename T>\nint maxInd(const Vec<T>& vs)\n\
    {\n    return std::max_element(vs.begin(), vs.end()) - vs.begin();\n}\ntemplate<typename\
    \ T>\nint lbInd(const Vec<T>& vs, const T& v)\n{\n    return std::lower_bound(vs.begin(),\
    \ vs.end(), v) - vs.begin();\n}\ntemplate<typename T>\nint ubInd(const Vec<T>&\
    \ vs, const T& v)\n{\n    return std::lower_bound(vs.begin(), vs.end(), v) - vs.begin();\n\
    }\ntemplate<typename Vs, typename F>\nvoid eraseIf(Vs& vs, F f)\n{\n    vs.erase(std::remove_if(vs.begin(),\
    \ vs.end(), f), vs.end());\n}\ntemplate<typename T, typename F>\nVec<T> genVec(int\
    \ n, F gen)\n{\n    Vec<T> ans;\n    std::generate_n(std::back_insert_iterator(ans),\
    \ n, gen);\n    return ans;\n}\nVec<int> iotaVec(int n, int offset = 0)\n{\n \
    \   Vec<int> ans(n);\n    iotaAll(ans, offset);\n    return ans;\n}\ntemplate<typename\
    \ T, typename F = Lt<T>>\nVec<int> iotaVec(const Vec<T>& vs, F comp = F{})\n{\n\
    \    auto is = iotaVec(vs.size(), 0);\n    sortAll(is, [&](int i, int j) { return\
    \ comp(vs[i], vs[j]); });\n    return is;\n}\ntemplate<typename T>\nVec<T> operator+=(Vec<T>&\
    \ vs1, const Vec<T>& vs2)\n{\n    vs1.insert(vs1.end(), vs2.begin(), vs2.end());\n\
    \    return vs1;\n}\ntemplate<typename T>\nVec<T> operator+(const Vec<T>& vs1,\
    \ const Vec<T>& vs2)\n{\n    return Vec<T>{vs1} += vs2;\n}\n#pragma endregion\n\
    #line 3 \"src/misc/common/xoshiro.hpp\"\n#pragma COMMENT(\"[REFS] Xoshiro: https://prng.di.unimi.it\"\
    )\n#pragma region Xoshiro\nnamespace xoshiro_impl {\nu64 x;\nu64 next()\n{\n \
    \   uint64_t z = (x += 0x9e3779b97f4a7c15);\n    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;\n    return z ^ (z >> 31);\n}\n\
    }  // namespace xoshiro_impl\nclass Xoshiro32\n{\npublic:\n    using result_type\
    \ = u32;\n    using T = result_type;\n    Xoshiro32(T seed = 0)\n    {\n     \
    \   xoshiro_impl::x = seed;\n        s[0] = xoshiro_impl::next();\n        s[1]\
    \ = xoshiro_impl::next();\n        s[2] = xoshiro_impl::next();\n        s[3]\
    \ = xoshiro_impl::next();\n    }\n    static constexpr T min()\n    {\n      \
    \  return std::numeric_limits<T>::min();\n    }\n    static constexpr T max()\n\
    \    {\n        return std::numeric_limits<T>::max();\n    }\n    T operator()()\n\
    \    {\n        return next();\n    }\n\nprivate:\n    static constexpr T rotl(const\
    \ T x, int k)\n    {\n        return (x << k) | (x >> (32 - k));\n    }\n    T\
    \ next()\n    {\n        const T ans = rotl(s[1] * 5, 7) * 9;\n        const T\
    \ t = s[1] << 9;\n        s[2] ^= s[0];\n        s[3] ^= s[1];\n        s[1] ^=\
    \ s[2];\n        s[0] ^= s[3];\n        s[2] ^= t;\n        s[3] = rotl(s[3],\
    \ 11);\n        return ans;\n    }\n    T s[4];\n};\nclass Xoshiro64\n{\npublic:\n\
    \    using result_type = u64;\n    using T = result_type;\n    Xoshiro64(T seed\
    \ = 0)\n    {\n        xoshiro_impl::x = seed;\n        s[0] = xoshiro_impl::next();\n\
    \        s[1] = xoshiro_impl::next();\n        s[2] = xoshiro_impl::next();\n\
    \        s[3] = xoshiro_impl::next();\n    }\n    static constexpr T min()\n \
    \   {\n        return std::numeric_limits<T>::min();\n    }\n    static constexpr\
    \ T max()\n    {\n        return std::numeric_limits<T>::max();\n    }\n    T\
    \ operator()()\n    {\n        return next();\n    }\n\nprivate:\n    static constexpr\
    \ T rotl(const T x, int k)\n    {\n        return (x << k) | (x >> (64 - k));\n\
    \    }\n    T next()\n    {\n        const T ans = rotl(s[1] * 5, 7) * 9;\n  \
    \      const T t = s[1] << 17;\n        s[2] ^= s[0];\n        s[3] ^= s[1];\n\
    \        s[1] ^= s[2];\n        s[0] ^= s[3];\n        s[2] ^= t;\n        s[3]\
    \ = rotl(s[3], 45);\n        return ans;\n    }\n    T s[4];\n};\n#pragma endregion\n\
    #line 5 \"src/misc/common/rng.hpp\"\n#pragma region RNG\ntemplate<typename Rng>\n\
    class RNG\n{\npublic:\n    using result_type = typename Rng::result_type;\n  \
    \  using T = result_type;\n    static constexpr T min()\n    {\n        return\
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
    \ rng64;\nRNG<Xoshiro32> rng_xo;\nRNG<Xoshiro64> rng_xo64;\n#pragma endregion\n"
  code: "#pragma once\n#include \"type_alias.hpp\"\n#include \"func_alias.hpp\"\n\
    #include \"xoshiro.hpp\"\n#pragma region RNG\ntemplate<typename Rng>\nclass RNG\n\
    {\npublic:\n    using result_type = typename Rng::result_type;\n    using T =\
    \ result_type;\n    static constexpr T min()\n    {\n        return Rng::min();\n\
    \    }\n    static constexpr T max()\n    {\n        return Rng::max();\n    }\n\
    \    RNG() : RNG(std::random_device{}()) {}\n    RNG(T seed) : m_rng(seed) {}\n\
    \    T operator()()\n    {\n        return m_rng();\n    }\n    template<typename\
    \ T>\n    T val(T min, T max)\n    {\n        return std::uniform_int_distribution<T>(min,\
    \ max)(m_rng);\n    }\n    template<typename T>\n    Pair<T, T> pair(T min, T\
    \ max)\n    {\n        return std::minmax({val<T>(min, max), val<T>(min, max)});\n\
    \    }\n    template<typename T>\n    Vec<T> vec(int n, T min, T max)\n    {\n\
    \        return genVec<T>(n, [&]() { return val<T>(min, max); });\n    }\n   \
    \ template<typename T>\n    Vec<Vec<T>> vvec(int n, int m, T min, T max)\n   \
    \ {\n        return genVec<Vec<T>>(n, [&]() { return vec(m, min, max); });\n \
    \   }\nprivate:\n    Rng m_rng;\n};\nRNG<std::mt19937> rng;\nRNG<std::mt19937_64>\
    \ rng64;\nRNG<Xoshiro32> rng_xo;\nRNG<Xoshiro64> rng_xo64;\n#pragma endregion\n"
  dependsOn:
  - src/misc/common/type_alias.hpp
  - src/misc/common/func_alias.hpp
  - src/misc/common/xoshiro.hpp
  isVerificationFile: false
  path: src/misc/common/rng.hpp
  requiredBy:
  - src/misc/common.hpp
  - src/misc/stopwatch.hpp
  - src/misc/zipper.hpp
  - src/misc/printer.hpp
  - src/misc/fastio/printer.hpp
  - src/misc/fastio/scanner.hpp
  - src/misc/scanner.hpp
  - src/flow/mincost_flow.hpp
  - src/flow/max_flow.hpp
  - src/math/moddint.hpp
  - src/math/set_zeta.hpp
  - src/math/modint.hpp
  - src/linear/gauss_jordan.hpp
  - src/linear/bit_gauss_jordan.hpp
  - src/linear/bit_matrix.hpp
  - src/linear/matrix.hpp
  - src/linear/array_matrix.hpp
  - src/data_structure/li_chao_tree.hpp
  - src/data_structure/intset.hpp
  - src/data_structure/intdict.hpp
  - src/data_structure/dualseg.hpp
  - src/data_structure/wavelet.hpp
  - src/data_structure/static_rmq.hpp
  - src/data_structure/swag.hpp
  - src/data_structure/mo.hpp
  - src/data_structure/segtree.hpp
  - src/data_structure/lazyseg.hpp
  - src/data_structure/dsu.hpp
  - src/data_structure/fenwick.hpp
  - src/data_structure/static_rsq.hpp
  - src/data_structure/ds_table.hpp
  - src/data_structure/segments.hpp
  - src/graph/graph.hpp
  - src/graph/centroid_decomp.hpp
  - src/graph/top_sort.hpp
  - src/graph/level_ancestor.hpp
  - src/graph/warshall_floyd.hpp
  - src/graph/bellman_ford.hpp
  - src/graph/bcc.hpp
  - src/graph/dijkstra.hpp
  - src/graph/diameter.hpp
  - src/graph/scc.hpp
  - src/graph/hld.hpp
  - src/graph/lca.hpp
  - src/graph/lowlink.hpp
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/common/rng.hpp
layout: document
redirect_from:
- /library/src/misc/common/rng.hpp
- /library/src/misc/common/rng.hpp.html
title: src/misc/common/rng.hpp
---
