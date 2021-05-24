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
    \ = std::priority_queue<T, Vec<T>, Gt<T>>;\n#pragma endregion\n#pragma region\
    \ FuncAlias\ntemplate<typename T>\nbool chmin(T& a, const T& b)\n{\n    if (a\
    \ > b) {\n        a = b;\n        return true;\n    } else {\n        return false;\n\
    \    }\n}\ntemplate<typename T>\nbool chmax(T& a, const T& b)\n{\n    if (a <\
    \ b) {\n        a = b;\n        return true;\n    } else {\n        return false;\n\
    \    }\n}\ntemplate<typename T>\nconstexpr T fdiv(T x, T y)\n{\n    if (y < T{})\
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
    \    }\n    return ans;\n}\ntemplate<typename T>\nvoid fillAll(Vec<T>& vs, const\
    \ T& v)\n{\n    std::fill(vs.begin(), vs.end(), v);\n}\ntemplate<typename T, typename\
    \ C = Lt<T>>\nvoid sortAll(Vec<T>& vs, C comp = C{})\n{\n    std::sort(vs.begin(),\
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
    struct C\n{\n    C() = default;\n    C(int v_) : v{v_} {}\n    friend bool operator<(const\
    \ C& c1, const C& c2)\n    {\n        return c1.v < c2.v;\n    }\n    friend bool\
    \ operator>(const C& c1, const C& c2)\n    {\n        return c1.v > c2.v;\n  \
    \  }\n    int v = 0;\n};\nvoid chminTest()\n{\n    int v = 10;\n    for (int i\
    \ = 100; i >= 0; i--) {\n        assert(chmin(v, i) == (i < 10));\n        assert(v\
    \ == std::min(i, 10));\n    }\n    C cls{10};\n    for (int i = 100; i >= 0; i--)\
    \ {\n        assert(chmin(cls, C{i}) == (i < 10));\n        assert(cls.v == std::min(i,\
    \ 10));\n    }\n}\nvoid chmaxTest()\n{\n    int v = 10;\n    for (int i = 0; i\
    \ < 100; i++) {\n        assert(chmax(v, i) == (i > 10));\n        assert(v ==\
    \ std::max(i, 10));\n    }\n    C cls{10};\n    for (int i = 0; i < 100; i++)\
    \ {\n        assert(chmax(cls, C{i}) == (i > 10));\n        assert(cls.v == std::max(i,\
    \ 10));\n    }\n}\nint main()\n{\n    chminTest();\n    chmaxTest();\n    std::cout\
    \ << \"Hello World\\n\";\n    return 0;\n}\n"
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
  isVerificationFile: true
  path: verifications/misc/common/func_alias.chminmax.test.cpp
  requiredBy: []
  timestamp: '2021-05-24 21:49:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verifications/misc/common/func_alias.chminmax.test.cpp
layout: document
redirect_from:
- /verify/verifications/misc/common/func_alias.chminmax.test.cpp
- /verify/verifications/misc/common/func_alias.chminmax.test.cpp.html
title: verifications/misc/common/func_alias.chminmax.test.cpp
---
