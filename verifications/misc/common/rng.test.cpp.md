---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/misc/common/rng.hpp
    title: src/misc/common/rng.hpp
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
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
    using Sec = std::chrono::seconds;\ntemplate<typename T>\nvoid fillAll(Vec<T>&\
    \ vs, const T& v)\n{\n    std::fill(vs.begin(), vs.end(), v);\n}\ntemplate<typename\
    \ T, typename C = Lt<T>>\nvoid sortAll(Vec<T>& vs, C comp = C{})\n{\n    std::sort(vs.begin(),\
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
    \ ans = vs;\n    reverseAll(ans);\n    return ans;\n}\n#pragma COMMENT(\"[REFS]\
    \ Xoshiro: https://prng.di.unimi.it\")\nnamespace xoshiro_impl {\nu64 x;\nu64\
    \ next()\n{\n    uint64_t z = (x += 0x9e3779b97f4a7c15);\n    z = (z ^ (z >> 30))\
    \ * 0xbf58476d1ce4e5b9;\n    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;\n    return\
    \ z ^ (z >> 31);\n}\n}\nclass Xoshiro32\n{\npublic:\n    using result_type = u32;\n\
    \    using T = result_type;\n    Xoshiro32(T seed = 0)\n    {\n        xoshiro_impl::x\
    \ = seed;\n        s[0] = xoshiro_impl::next();\n        s[1] = xoshiro_impl::next();\n\
    \        s[2] = xoshiro_impl::next();\n        s[3] = xoshiro_impl::next();\n\
    \    }\n    static constexpr T min()\n    {\n        return std::numeric_limits<T>::min();\n\
    \    }\n    static constexpr T max()\n    {\n        return std::numeric_limits<T>::max();\n\
    \    }\n    T operator()()\n    {\n        return next();\n    }\nprivate:\n \
    \   static constexpr T rotl(const T x, int k)\n    {\n        return (x << k)\
    \ | (x >> (32 - k));\n    }\n    T next()\n    {\n        const T ans = rotl(s[1]\
    \ * 5, 7) * 9;\n        const T t = s[1] << 9;\n        s[2] ^= s[0];\n      \
    \  s[3] ^= s[1];\n        s[1] ^= s[2];\n        s[0] ^= s[3];\n        s[2] ^=\
    \ t;\n        s[3] = rotl(s[3], 11);\n        return ans;\n    }\n    T s[4];\n\
    };\nclass Xoshiro64\n{\npublic:\n    using result_type = u64;\n    using T = result_type;\n\
    \    Xoshiro64(T seed = 0)\n    {\n        xoshiro_impl::x = seed;\n        s[0]\
    \ = xoshiro_impl::next();\n        s[1] = xoshiro_impl::next();\n        s[2]\
    \ = xoshiro_impl::next();\n        s[3] = xoshiro_impl::next();\n    }\n    static\
    \ constexpr T min()\n    {\n        return std::numeric_limits<T>::min();\n  \
    \  }\n    static constexpr T max()\n    {\n        return std::numeric_limits<T>::max();\n\
    \    }\n    T operator()()\n    {\n        return next();\n    }\nprivate:\n \
    \   static constexpr T rotl(const T x, int k)\n    {\n        return (x << k)\
    \ | (x >> (64 - k));\n    }\n    T next()\n    {\n        const T ans = rotl(s[1]\
    \ * 5, 7) * 9;\n        const T t = s[1] << 17;\n        s[2] ^= s[0];\n     \
    \   s[3] ^= s[1];\n        s[1] ^= s[2];\n        s[0] ^= s[3];\n        s[2]\
    \ ^= t;\n        s[3] = rotl(s[3], 45);\n        return ans;\n    }\n    T s[4];\n\
    };\ntemplate<typename Rng>\nclass RNG\n{\npublic:\n    using result_type = typename\
    \ Rng::result_type;\n    using T = result_type;\n    static constexpr T min()\n\
    \    {\n        return Rng::min();\n    }\n    static constexpr T max()\n    {\n\
    \        return Rng::max();\n    }\n    RNG() : RNG(std::random_device{}()) {}\n\
    \    RNG(T seed) : m_rng(seed) {}\n    T operator()()\n    {\n        return m_rng();\n\
    \    }\n    template<typename T>\n    T val(T min, T max)\n    {\n        return\
    \ std::uniform_int_distribution<T>(min, max)(m_rng);\n    }\n    template<typename\
    \ T>\n    Pair<T, T> pair(T min, T max)\n    {\n        return std::minmax({val<T>(min,\
    \ max), val<T>(min, max)});\n    }\n    template<typename T>\n    Vec<T> vec(int\
    \ n, T min, T max)\n    {\n        return genVec<T>(n, [&]() { return val<T>(min,\
    \ max); });\n    }\n    template<typename T>\n    Vec<Vec<T>> vvec(int n, int\
    \ m, T min, T max)\n    {\n        return genVec<Vec<T>>(n, [&]() { return vec(m,\
    \ min, max); });\n    }\nprivate:\n    Rng m_rng;\n};\nRNG<std::mt19937> rng;\n\
    RNG<std::mt19937_64> rng64;\nRNG<Xoshiro32> rng_xo;\nRNG<Xoshiro64> rng_xo64;\n\
    void Test()\n{\n    const u64 v32_1 = rng();\n    const u64 v32_2 = rng_xo();\n\
    \    const u64 v64_1 = rng64();\n    const u64 v64_2 = rng_xo64();\n    assert(0_u64\
    \ <= v32_1 and v32_1 <= 0xFFFFFFFF_u64);\n    assert(0_u64 <= v32_2 and v32_2\
    \ <= 0xFFFFFFFF_u64);\n    assert(0_u64 <= v64_1 and v64_1 <= 0xFFFFFFFFFFFFFFFF_u64);\n\
    \    assert(0_u64 <= v64_2 and v64_2 <= 0xFFFFFFFFFFFFFFFF_u64);\n}\nvoid valTest()\n\
    {\n    int min = 10, max = 20;\n    const u64 v32_1 = rng.val(min, max);\n   \
    \ const u64 v32_2 = rng_xo.val(min, max);\n    const u64 v64_1 = rng64.val(min,\
    \ max);\n    const u64 v64_2 = rng_xo64.val(min, max);\n    assert(min <= v32_1\
    \ and v32_1 <= max);\n    assert(min <= v32_2 and v32_2 <= max);\n    assert(min\
    \ <= v64_1 and v64_1 <= max);\n    assert(min <= v64_2 and v64_2 <= max);\n}\n\
    void pairTest()\n{\n    int min = 10, max = 20;\n    const auto [l32_1, r32_1]\
    \ = rng.pair(min, max);\n    const auto [l32_2, r32_2] = rng_xo.pair(min, max);\n\
    \    const auto [l64_1, r64_1] = rng64.pair(min, max);\n    const auto [l64_2,\
    \ r64_2] = rng_xo64.pair(min, max);\n    assert(min <= l32_1 and l32_1 <= r32_1\
    \ and r32_1 <= max);\n    assert(min <= l32_2 and l32_2 <= r32_2 and r32_2 <=\
    \ max);\n    assert(min <= l64_1 and l64_1 <= r64_1 and r64_1 <= max);\n    assert(min\
    \ <= l64_2 and l64_2 <= r64_2 and r64_2 <= max);\n}\nvoid vecTest()\n{\n    int\
    \ n = 10;\n    int min = 10, max = 20;\n    const auto vs32_1 = rng.vec(n, min,\
    \ max);\n    const auto vs32_2 = rng_xo.vec(n, min, max);\n    const auto vs64_1\
    \ = rng64.vec(n, min, max);\n    const auto vs64_2 = rng_xo64.vec(n, min, max);\n\
    \    for (const auto v : vs32_1) {\n        assert(min <= v and v <= max);\n \
    \   }\n    for (const auto v : vs32_2) {\n        assert(min <= v and v <= max);\n\
    \    }\n    for (const auto v : vs64_1) {\n        assert(min <= v and v <= max);\n\
    \    }\n    for (const auto v : vs64_2) {\n        assert(min <= v and v <= max);\n\
    \    }\n}\nvoid vvecTest()\n{\n    int m = 3, n = 4;\n    int min = 10, max =\
    \ 20;\n    const auto vss32_1 = rng.vvec(m, n, min, max);\n    const auto vss32_2\
    \ = rng_xo.vvec(m, n, min, max);\n    const auto vss64_1 = rng64.vvec(m, n, min,\
    \ max);\n    const auto vss64_2 = rng_xo64.vvec(m, n, min, max);\n    for (const\
    \ auto vs : vss32_1) {\n        for (auto v : vs) {\n            assert(min <=\
    \ v and v <= max);\n        }\n    }\n    for (const auto vs : vss32_2) {\n  \
    \      for (auto v : vs) {\n            assert(min <= v and v <= max);\n     \
    \   }\n    }\n    for (const auto vs : vss64_1) {\n        for (auto v : vs) {\n\
    \            assert(min <= v and v <= max);\n        }\n    }\n    for (const\
    \ auto vs : vss64_2) {\n        for (auto v : vs) {\n            assert(min <=\
    \ v and v <= max);\n        }\n    }\n}\nint main()\n{\n    Test();\n    valTest();\n\
    \    pairTest();\n    vecTest();\n    vvecTest();\n    std::cout << \"Hello World\\\
    n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"../../../src/misc/common/rng.hpp\"\n\nvoid Test()\n{\n    const u64\
    \ v32_1 = rng();\n    const u64 v32_2 = rng_xo();\n    const u64 v64_1 = rng64();\n\
    \    const u64 v64_2 = rng_xo64();\n    assert(0_u64 <= v32_1 and v32_1 <= 0xFFFFFFFF_u64);\n\
    \    assert(0_u64 <= v32_2 and v32_2 <= 0xFFFFFFFF_u64);\n    assert(0_u64 <=\
    \ v64_1 and v64_1 <= 0xFFFFFFFFFFFFFFFF_u64);\n    assert(0_u64 <= v64_2 and v64_2\
    \ <= 0xFFFFFFFFFFFFFFFF_u64);\n}\n\nvoid valTest()\n{\n    int min = 10, max =\
    \ 20;\n    const u64 v32_1 = rng.val(min, max);\n    const u64 v32_2 = rng_xo.val(min,\
    \ max);\n    const u64 v64_1 = rng64.val(min, max);\n    const u64 v64_2 = rng_xo64.val(min,\
    \ max);\n    assert(min <= v32_1 and v32_1 <= max);\n    assert(min <= v32_2 and\
    \ v32_2 <= max);\n    assert(min <= v64_1 and v64_1 <= max);\n    assert(min <=\
    \ v64_2 and v64_2 <= max);\n}\n\nvoid pairTest()\n{\n    int min = 10, max = 20;\n\
    \n    const auto [l32_1, r32_1] = rng.pair(min, max);\n    const auto [l32_2,\
    \ r32_2] = rng_xo.pair(min, max);\n    const auto [l64_1, r64_1] = rng64.pair(min,\
    \ max);\n    const auto [l64_2, r64_2] = rng_xo64.pair(min, max);\n    assert(min\
    \ <= l32_1 and l32_1 <= r32_1 and r32_1 <= max);\n    assert(min <= l32_2 and\
    \ l32_2 <= r32_2 and r32_2 <= max);\n    assert(min <= l64_1 and l64_1 <= r64_1\
    \ and r64_1 <= max);\n    assert(min <= l64_2 and l64_2 <= r64_2 and r64_2 <=\
    \ max);\n}\n\nvoid vecTest()\n{\n    int n = 10;\n    int min = 10, max = 20;\n\
    \    const auto vs32_1 = rng.vec(n, min, max);\n    const auto vs32_2 = rng_xo.vec(n,\
    \ min, max);\n    const auto vs64_1 = rng64.vec(n, min, max);\n    const auto\
    \ vs64_2 = rng_xo64.vec(n, min, max);\n    for (const auto v : vs32_1) {\n   \
    \     assert(min <= v and v <= max);\n    }\n    for (const auto v : vs32_2) {\n\
    \        assert(min <= v and v <= max);\n    }\n    for (const auto v : vs64_1)\
    \ {\n        assert(min <= v and v <= max);\n    }\n    for (const auto v : vs64_2)\
    \ {\n        assert(min <= v and v <= max);\n    }\n}\n\nvoid vvecTest()\n{\n\
    \    int m = 3, n = 4;\n    int min = 10, max = 20;\n    const auto vss32_1 =\
    \ rng.vvec(m, n, min, max);\n    const auto vss32_2 = rng_xo.vvec(m, n, min, max);\n\
    \    const auto vss64_1 = rng64.vvec(m, n, min, max);\n    const auto vss64_2\
    \ = rng_xo64.vvec(m, n, min, max);\n    for (const auto vs : vss32_1) {\n    \
    \    for (auto v : vs) {\n            assert(min <= v and v <= max);\n       \
    \ }\n    }\n    for (const auto vs : vss32_2) {\n        for (auto v : vs) {\n\
    \            assert(min <= v and v <= max);\n        }\n    }\n    for (const\
    \ auto vs : vss64_1) {\n        for (auto v : vs) {\n            assert(min <=\
    \ v and v <= max);\n        }\n    }\n    for (const auto vs : vss64_2) {\n  \
    \      for (auto v : vs) {\n            assert(min <= v and v <= max);\n     \
    \   }\n    }\n}\n\nint main()\n{\n    Test();\n    valTest();\n    pairTest();\n\
    \    vecTest();\n    vvecTest();\n    std::cout << \"Hello World\\n\";\n    return\
    \ 0;\n}\n"
  dependsOn:
  - src/misc/common/rng.hpp
  - src/misc/common/type_alias.hpp
  - src/misc/common/vec_utils.hpp
  - src/misc/common/xoshiro.hpp
  isVerificationFile: true
  path: verifications/misc/common/rng.test.cpp
  requiredBy: []
  timestamp: '2021-06-02 01:47:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/misc/common/rng.test.cpp
layout: document
redirect_from:
- /verify/verifications/misc/common/rng.test.cpp
- /verify/verifications/misc/common/rng.test.cpp.html
title: verifications/misc/common/rng.test.cpp
---
