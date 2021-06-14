---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/misc/common/func_alias.hpp
    title: src/misc/common/func_alias.hpp
  - icon: ':question:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
  - icon: ':question:'
    path: src/misc/common/show.hpp
    title: src/misc/common/show.hpp
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
    using Sec = std::chrono::seconds;\nOstream& operator<<(Ostream& os, i128 v)\n\
    {\n    bool minus = false;\n    if (v < 0) { minus = true, v = -v; }\n    Str\
    \ ans;\n    if (v == 0) { ans = \"0\"; }\n    while (v) {\n        ans.push_back('0'\
    \ + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(), ans.end());\n    return\
    \ os << (minus ? \"-\" : \"\") << ans;\n}\nOstream& operator<<(Ostream& os, u128\
    \ v)\n{\n    Str ans;\n    if (v == 0) { ans = \"0\"; }\n    while (v) {\n   \
    \     ans.push_back('0' + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(),\
    \ ans.end());\n    return os << ans;\n}\ntemplate<typename T>\nbool chmin(T& a,\
    \ const T& b)\n{\n    if (a > b) {\n        a = b;\n        return true;\n   \
    \ } else {\n        return false;\n    }\n}\ntemplate<typename T>\nbool chmax(T&\
    \ a, const T& b)\n{\n    if (a < b) {\n        a = b;\n        return true;\n\
    \    } else {\n        return false;\n    }\n}\ntemplate<typename T>\nconstexpr\
    \ T fdiv(T x, T y)\n{\n    if (y < T{}) { x = -x, y = -y; }\n    return x >= T{}\
    \ ? x / y : (x - y + 1) / y;\n}\ntemplate<typename T>\nconstexpr T cdiv(T x, T\
    \ y)\n{\n    if (y < T{}) { x = -x, y = -y; }\n    return x >= T{} ? (x + y -\
    \ 1) / y : x / y;\n}\ntemplate<typename T, typename I>\nconstexpr T modPower(T\
    \ v, I n, T mod)\n{\n    T ans = 1 % mod;\n    for (; n > 0; n >>= 1, (v *= v)\
    \ %= mod) {\n        if (n % 2 == 1) { (ans *= v) %= mod; }\n    }\n    return\
    \ ans;\n}\ntemplate<typename T, typename I>\nconstexpr T power(T v, I n)\n{\n\
    \    T ans = 1;\n    for (; n > 0; n >>= 1, v *= v) {\n        if (n % 2 == 1)\
    \ { ans *= v; }\n    }\n    return ans;\n}\ntemplate<typename T, typename I>\n\
    constexpr T power(T v, I n, const T& e)\n{\n    T ans = e;\n    for (; n > 0;\
    \ n >>= 1, v *= v) {\n        if (n % 2 == 1) { ans *= v; }\n    }\n    return\
    \ ans;\n}\nstruct C\n{\n    C() = default;\n    C(int v_) : v{v_} {}\n    friend\
    \ bool operator<(const C& c1, const C& c2)\n    {\n        return c1.v < c2.v;\n\
    \    }\n    friend bool operator>(const C& c1, const C& c2)\n    {\n        return\
    \ c1.v > c2.v;\n    }\n    int v = 0;\n};\nvoid chminTest()\n{\n    int v = 10;\n\
    \    for (int i = 100; i >= 0; i--) {\n        assert(chmin(v, i) == (i < 10));\n\
    \        assert(v == std::min(i, 10));\n    }\n    C cls{10};\n    for (int i\
    \ = 100; i >= 0; i--) {\n        assert(chmin(cls, C{i}) == (i < 10));\n     \
    \   assert(cls.v == std::min(i, 10));\n    }\n}\nvoid chmaxTest()\n{\n    int\
    \ v = 10;\n    for (int i = 0; i < 100; i++) {\n        assert(chmax(v, i) ==\
    \ (i > 10));\n        assert(v == std::max(i, 10));\n    }\n    C cls{10};\n \
    \   for (int i = 0; i < 100; i++) {\n        assert(chmax(cls, C{i}) == (i > 10));\n\
    \        assert(cls.v == std::max(i, 10));\n    }\n}\nint main()\n{\n    chminTest();\n\
    \    chmaxTest();\n    std::cout << \"Hello World\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"../../../src/misc/common/func_alias.hpp\"\n\nstruct C\n{\n    C()\
    \ = default;\n    C(int v_) : v{v_} {}\n    friend bool operator<(const C& c1,\
    \ const C& c2)\n    {\n        return c1.v < c2.v;\n    }\n    friend bool operator>(const\
    \ C& c1, const C& c2)\n    {\n        return c1.v > c2.v;\n    }\n    int v =\
    \ 0;\n};\n\nvoid chminTest()\n{\n    int v = 10;\n    for (int i = 100; i >= 0;\
    \ i--) {\n        assert(chmin(v, i) == (i < 10));\n        assert(v == std::min(i,\
    \ 10));\n    }\n\n    C cls{10};\n    for (int i = 100; i >= 0; i--) {\n     \
    \   assert(chmin(cls, C{i}) == (i < 10));\n        assert(cls.v == std::min(i,\
    \ 10));\n    }\n}\n\nvoid chmaxTest()\n{\n    int v = 10;\n    for (int i = 0;\
    \ i < 100; i++) {\n        assert(chmax(v, i) == (i > 10));\n        assert(v\
    \ == std::max(i, 10));\n    }\n\n    C cls{10};\n    for (int i = 0; i < 100;\
    \ i++) {\n        assert(chmax(cls, C{i}) == (i > 10));\n        assert(cls.v\
    \ == std::max(i, 10));\n    }\n}\n\nint main()\n{\n    chminTest();\n    chmaxTest();\n\
    \    std::cout << \"Hello World\\n\";\n    return 0;\n}\n"
  dependsOn:
  - src/misc/common/func_alias.hpp
  - src/misc/common/type_alias.hpp
  - src/misc/common/show.hpp
  - src/misc/common/print/int128_t.hpp
  isVerificationFile: true
  path: verifications/misc/common/func_alias.chminmax.test.cpp
  requiredBy: []
  timestamp: '2021-06-13 23:28:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/misc/common/func_alias.chminmax.test.cpp
layout: document
redirect_from:
- /verify/verifications/misc/common/func_alias.chminmax.test.cpp
- /verify/verifications/misc/common/func_alias.chminmax.test.cpp.html
title: verifications/misc/common/func_alias.chminmax.test.cpp
---
