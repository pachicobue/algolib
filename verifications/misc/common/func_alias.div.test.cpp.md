---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/misc/common/func_alias.hpp
    title: src/misc/common/func_alias.hpp
  - icon: ':question:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#include <bits/stdc++.h>\n#pragma region TypeAlias\nusing i32 = int;\n\
    using u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\nusing f64 = double;\nusing\
    \ f80 = long double;\nusing f128 = __float128;\nconstexpr i32 operator\"\" _i32(u64\
    \ v)\n{\n    return v;\n}\nconstexpr i32 operator\"\" _u32(u64 v)\n{\n    return\
    \ v;\n}\nconstexpr i64 operator\"\" _i64(u64 v)\n{\n    return v;\n}\nconstexpr\
    \ u64 operator\"\" _u64(u64 v)\n{\n    return v;\n}\nconstexpr f64 operator\"\"\
    \ _f64(f80 v)\n{\n    return v;\n}\nconstexpr f80 operator\"\" _f80(f80 v)\n{\n\
    \    return v;\n}\nusing Istream = std::istream;\nusing Ostream = std::ostream;\n\
    using Str = std::string;\ntemplate<typename T>\nusing Lt = std::less<T>;\ntemplate<typename\
    \ T>\nusing Gt = std::greater<T>;\ntemplate<typename T>\nusing IList = std::initializer_list<T>;\n\
    template<int n>\nusing BSet = std::bitset<n>;\ntemplate<typename T1, typename\
    \ T2>\nusing Pair = std::pair<T1, T2>;\ntemplate<typename... Ts>\nusing Tup =\
    \ std::tuple<Ts...>;\ntemplate<typename T, int N>\nusing Arr = std::array<T, N>;\n\
    template<typename... Ts>\nusing Deq = std::deque<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing Set = std::set<Ts...>;\ntemplate<typename... Ts>\nusing MSet = std::multiset<Ts...>;\n\
    template<typename... Ts>\nusing USet = std::unordered_set<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing UMSet = std::unordered_multiset<Ts...>;\ntemplate<typename... Ts>\n\
    using Map = std::map<Ts...>;\ntemplate<typename... Ts>\nusing MMap = std::multimap<Ts...>;\n\
    template<typename... Ts>\nusing UMap = std::unordered_map<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing UMMap = std::unordered_multimap<Ts...>;\ntemplate<typename... Ts>\n\
    using Vec = std::vector<Ts...>;\ntemplate<typename... Ts>\nusing Stack = std::stack<Ts...>;\n\
    template<typename... Ts>\nusing Queue = std::queue<Ts...>;\ntemplate<typename\
    \ T>\nusing MaxHeap = std::priority_queue<T>;\ntemplate<typename T>\nusing MinHeap\
    \ = std::priority_queue<T, Vec<T>, Gt<T>>;\nusing NSec = std::chrono::nanoseconds;\n\
    using USec = std::chrono::microseconds;\nusing MSec = std::chrono::milliseconds;\n\
    using Sec = std::chrono::seconds;\n#pragma endregion\n#pragma region FuncAlias\n\
    template<typename T>\nbool chmin(T& a, const T& b)\n{\n    if (a > b) {\n    \
    \    a = b;\n        return true;\n    } else {\n        return false;\n    }\n\
    }\ntemplate<typename T>\nbool chmax(T& a, const T& b)\n{\n    if (a < b) {\n \
    \       a = b;\n        return true;\n    } else {\n        return false;\n  \
    \  }\n}\ntemplate<typename T>\nconstexpr T fdiv(T x, T y)\n{\n    if (y < T{})\
    \ { x = -x, y = -y; }\n    return x >= T{} ? x / y : (x - y + 1) / y;\n}\ntemplate<typename\
    \ T>\nconstexpr T cdiv(T x, T y)\n{\n    if (y < T{}) { x = -x, y = -y; }\n  \
    \  return x >= T{} ? (x + y - 1) / y : x / y;\n}\ntemplate<typename T, typename\
    \ I>\nconstexpr T modPower(T v, I n, T mod)\n{\n    T ans = 1 % mod;\n    for\
    \ (; n > 0; n >>= 1, (v *= v) %= mod) {\n        if (n % 2 == 1) { (ans *= v)\
    \ %= mod; }\n    }\n    return ans;\n}\ntemplate<typename T, typename I>\nconstexpr\
    \ T power(T v, I n)\n{\n    T ans = 1;\n    for (; n > 0; n >>= 1, v *= v) {\n\
    \        if (n % 2 == 1) { ans *= v; }\n    }\n    return ans;\n}\ntemplate<typename\
    \ T, typename I>\nconstexpr T power(T v, I n, const T& e)\n{\n    T ans = e;\n\
    \    for (; n > 0; n >>= 1, v *= v) {\n        if (n % 2 == 1) { ans *= v; }\n\
    \    }\n    return ans;\n}\n#pragma endregion\nvoid fdivTest()\n{\n    auto f\
    \ = [&](auto x, auto y) {\n        auto a = (decltype(x))std::floor((f80)x / y);\n\
    \        assert(fdiv(x, y) == a);\n    };\n    for (int x = -100; x <= 100; x++)\
    \ {\n        for (int y = -100; y <= 100; y++) {\n            if (y == 0) { continue;\
    \ }\n            f(x, y);\n        }\n    }\n}\nvoid cdivTest()\n{\n    auto c\
    \ = [&](auto x, auto y) {\n        auto a = (decltype(x))std::ceil((f80)x / y);\n\
    \        assert(cdiv(x, y) == a);\n    };\n    for (int x = -100; x <= 100; x++)\
    \ {\n        for (int y = -100; y <= 100; y++) {\n            if (y == 0) { continue;\
    \ }\n            c(x, y);\n        }\n    }\n}\nint main()\n{\n    fdivTest();\n\
    \    cdivTest();\n    std::cout << \"Hello World\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"../../../src/misc/common/func_alias.hpp\"\nvoid fdivTest()\n{\n \
    \   auto f = [&](auto x, auto y) {\n        auto a = (decltype(x))std::floor((f80)x\
    \ / y);\n        assert(fdiv(x, y) == a);\n    };\n    for (int x = -100; x <=\
    \ 100; x++) {\n        for (int y = -100; y <= 100; y++) {\n            if (y\
    \ == 0) { continue; }\n            f(x, y);\n        }\n    }\n}\n\nvoid cdivTest()\n\
    {\n    auto c = [&](auto x, auto y) {\n        auto a = (decltype(x))std::ceil((f80)x\
    \ / y);\n        assert(cdiv(x, y) == a);\n    };\n    for (int x = -100; x <=\
    \ 100; x++) {\n        for (int y = -100; y <= 100; y++) {\n            if (y\
    \ == 0) { continue; }\n            c(x, y);\n        }\n    }\n}\n\nint main()\n\
    {\n    fdivTest();\n    cdivTest();\n    std::cout << \"Hello World\\n\";\n  \
    \  return 0;\n}\n"
  dependsOn:
  - src/misc/common/func_alias.hpp
  - src/misc/common/type_alias.hpp
  isVerificationFile: true
  path: verifications/misc/common/func_alias.div.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 03:45:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verifications/misc/common/func_alias.div.test.cpp
layout: document
redirect_from:
- /verify/verifications/misc/common/func_alias.div.test.cpp
- /verify/verifications/misc/common/func_alias.div.test.cpp.html
title: verifications/misc/common/func_alias.div.test.cpp
---
