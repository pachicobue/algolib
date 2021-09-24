---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/misc/common/bit_ops.hpp
    title: src/misc/common/bit_ops.hpp
  - icon: ':question:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
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
    using Sec = std::chrono::seconds;\nconstexpr int popcount(const u64 v)\n{\n  \
    \  return v ? __builtin_popcountll(v) : 0;\n}\nconstexpr int log2p1(const u64\
    \ v)\n{\n    return v ? 64 - __builtin_clzll(v) : 0;\n}\nconstexpr int lsbp1(const\
    \ u64 v)\n{\n    return __builtin_ffsll(v);\n}\nconstexpr int clog(const u64 v)\n\
    {\n    return v ? log2p1(v - 1) : 0;\n}\nconstexpr u64 ceil2(const u64 v)\n{\n\
    \    const int l = clog(v);\n    return (l == 64) ? 0_u64 : (1_u64 << l);\n}\n\
    constexpr u64 floor2(const u64 v)\n{\n    return v ? (1_u64 << (log2p1(v) - 1))\
    \ : 0_u64;\n}\nconstexpr bool ispow2(const u64 v)\n{\n    return (v > 0) and ((v\
    \ & (v - 1)) == 0);\n}\nconstexpr bool btest(const u64 mask, const int ind)\n\
    {\n    return (mask >> ind) & 1_u64;\n}\nvoid popcountTest()\n{\n    assert(popcount(0x0123456789ABCDEF)\
    \ == 32);\n    assert(popcount(0x0) == 0);\n}\nvoid log2p1Test()\n{\n    assert(log2p1(0x0123456789ABCDEF)\
    \ == 57);\n    assert(log2p1(0x8000000000000000) == 64);\n    assert(log2p1(0xFFFFFFFFFFFFFFFF)\
    \ == 64);\n    assert(log2p1(0x1) == 1);\n    assert(log2p1(0x0) == 0);\n}\nvoid\
    \ lsbp1Test()\n{\n    assert(lsbp1(0x0123456789ABCDEF) == 1);\n    assert(lsbp1(0x8000000000000000)\
    \ == 64);\n    assert(lsbp1(0x0) == 0);\n}\nvoid clogTest()\n{\n    assert(clog(0x0123456789ABCDEF)\
    \ == 57);\n    assert(clog(0x8000000000000000) == 63);\n    assert(clog(0x0) ==\
    \ 0);\n}\nvoid ceil2Test()\n{\n    assert(ceil2(0x0123456789ABCDEF) == 0x0200000000000000);\n\
    \    assert(ceil2(0x8000000000000000) == 0x8000000000000000);\n    assert(ceil2(0x8000000000000001)\
    \ == 0x0);\n    assert(ceil2(0x0) == 1);\n}\nvoid floor2Test()\n{\n    assert(floor2(0x0123456789ABCDEF)\
    \ == 0x0100000000000000);\n    assert(floor2(0x8000000000000000) == 0x8000000000000000);\n\
    \    assert(floor2(0x8000000000000001) == 0x8000000000000000);\n    assert(floor2(0x1)\
    \ == 1);\n    assert(floor2(0x0) == 0);\n}\nvoid ispow2Test()\n{\n    assert(ispow2(0x0123456789ABCDEF)\
    \ == false);\n    assert(ispow2(0x8000000000000000) == true);\n    assert(ispow2(0x8000000000000001)\
    \ == false);\n    assert(ispow2(0x1) == true);\n    assert(ispow2(0x0) == false);\n\
    }\nvoid btestTest()\n{\n    const i64 v = 0x3333333333333333;\n    for (int i\
    \ = 0; i < 64; i++) {\n        assert(btest(v, i) == ((i % 4) < 2));\n    }\n\
    }\nint main()\n{\n    popcountTest();\n    log2p1Test();\n    lsbp1Test();\n \
    \   clogTest();\n    ceil2Test();\n    floor2Test();\n    ispow2Test();\n    btestTest();\n\
    \    std::cout << \"Hello World\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"../../../src/misc/common/bit_ops.hpp\"\n\nvoid popcountTest()\n{\n\
    \    assert(popcount(0x0123456789ABCDEF) == 32);\n    assert(popcount(0x0) ==\
    \ 0);\n}\n\nvoid log2p1Test()\n{\n    assert(log2p1(0x0123456789ABCDEF) == 57);\n\
    \    assert(log2p1(0x8000000000000000) == 64);\n    assert(log2p1(0xFFFFFFFFFFFFFFFF)\
    \ == 64);\n    assert(log2p1(0x1) == 1);\n    assert(log2p1(0x0) == 0);\n}\n\n\
    void lsbp1Test()\n{\n    assert(lsbp1(0x0123456789ABCDEF) == 1);\n    assert(lsbp1(0x8000000000000000)\
    \ == 64);\n    assert(lsbp1(0x0) == 0);\n}\n\nvoid clogTest()\n{\n    assert(clog(0x0123456789ABCDEF)\
    \ == 57);\n    assert(clog(0x8000000000000000) == 63);\n    assert(clog(0x0) ==\
    \ 0);\n}\n\nvoid ceil2Test()\n{\n    assert(ceil2(0x0123456789ABCDEF) == 0x0200000000000000);\n\
    \    assert(ceil2(0x8000000000000000) == 0x8000000000000000);\n    assert(ceil2(0x8000000000000001)\
    \ == 0x0);\n    assert(ceil2(0x0) == 1);\n}\n\nvoid floor2Test()\n{\n    assert(floor2(0x0123456789ABCDEF)\
    \ == 0x0100000000000000);\n    assert(floor2(0x8000000000000000) == 0x8000000000000000);\n\
    \    assert(floor2(0x8000000000000001) == 0x8000000000000000);\n    assert(floor2(0x1)\
    \ == 1);\n    assert(floor2(0x0) == 0);\n}\n\nvoid ispow2Test()\n{\n    assert(ispow2(0x0123456789ABCDEF)\
    \ == false);\n    assert(ispow2(0x8000000000000000) == true);\n    assert(ispow2(0x8000000000000001)\
    \ == false);\n    assert(ispow2(0x1) == true);\n    assert(ispow2(0x0) == false);\n\
    }\n\nvoid btestTest()\n{\n    const i64 v = 0x3333333333333333;\n    for (int\
    \ i = 0; i < 64; i++) {\n        assert(btest(v, i) == ((i % 4) < 2));\n    }\n\
    }\n\nint main()\n{\n    popcountTest();\n    log2p1Test();\n    lsbp1Test();\n\
    \    clogTest();\n    ceil2Test();\n    floor2Test();\n    ispow2Test();\n   \
    \ btestTest();\n    std::cout << \"Hello World\\n\";\n    return 0;\n}\n"
  dependsOn:
  - src/misc/common/bit_ops.hpp
  - src/misc/common/type_alias.hpp
  isVerificationFile: true
  path: verifications/misc/common/bit_ops.test.cpp
  requiredBy: []
  timestamp: '2021-06-02 01:47:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/misc/common/bit_ops.test.cpp
layout: document
redirect_from:
- /verify/verifications/misc/common/bit_ops.test.cpp
- /verify/verifications/misc/common/bit_ops.test.cpp.html
title: verifications/misc/common/bit_ops.test.cpp
---
