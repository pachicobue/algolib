---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/misc/common/irange.hpp
    title: src/misc/common/irange.hpp
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
    using Sec = std::chrono::seconds;\n#pragma endregion\n#pragma region Range\nclass\
    \ irange\n{\nprivate:\n    struct itr\n    {\n        itr(int start = 0, int step\
    \ = 1) : m_cnt{start}, m_step{step} {}\n        bool operator!=(const itr& it)\
    \ const\n        {\n            return m_cnt != it.m_cnt;\n        }\n       \
    \ int operator*()\n        {\n            return m_cnt;\n        }\n        itr&\
    \ operator++()\n        {\n            m_cnt += m_step;\n            return *this;\n\
    \        }\n        int m_cnt, m_step;\n    };\n    int m_start, m_end, m_step;\n\
    public:\n    irange(int start, int end, int step = 1)\n    {\n        assert(step\
    \ != 0);\n        const int d = std::abs(step);\n        const int l = (step >\
    \ 0 ? start : end);\n        const int r = (step > 0 ? end : start);\n       \
    \ int n = (r - l) / d + ((r - l) % d ? 1 : 0);\n        if (l >= r) { n = 0; }\n\
    \        m_start = start;\n        m_end = start + step * n;\n        m_step =\
    \ step;\n    }\n    itr begin() const\n    {\n        return itr{m_start, m_step};\n\
    \    }\n    itr end() const\n    {\n        return itr{m_end, m_step};\n    }\n\
    };\nirange rep(int end)\n{\n    return irange(0, end, 1);\n}\nirange per(int rend)\n\
    {\n    return irange(rend - 1, -1, -1);\n}\n#pragma endregion\nvoid repTest()\n\
    {\n    std::vector<int> is;\n    for (int i : rep(5)) {\n        is.push_back(i);\n\
    \    }\n    assert(is == std::vector<int>({0, 1, 2, 3, 4}));\n}\nvoid perTest()\n\
    {\n    std::vector<int> is;\n    for (int i : per(5)) {\n        is.push_back(i);\n\
    \    }\n    assert(is == std::vector<int>({4, 3, 2, 1, 0}));\n}\nvoid irangeTest1()\n\
    {\n    std::vector<int> is1;\n    for (int i : irange(2, 5)) {\n        is1.push_back(i);\n\
    \    }\n    assert(is1 == std::vector<int>({2, 3, 4}));\n    std::vector<int>\
    \ is2;\n    for (int i : irange(2, 10, 3)) {\n        is2.push_back(i);\n    }\n\
    \    assert(is2 == std::vector<int>({2, 5, 8}));\n    std::vector<int> is3;\n\
    \    for (int i : irange(2, 11, 3)) {\n        is3.push_back(i);\n    }\n    assert(is3\
    \ == std::vector<int>({2, 5, 8}));\n    std::vector<int> is4;\n    for (int i\
    \ : irange(2, 1, 3)) {\n        is4.push_back(i);\n    }\n    assert(is4.empty());\n\
    }\nvoid irangeTest2()\n{\n    std::vector<int> is2;\n    for (int i : irange(10,\
    \ 2, -3)) {\n        is2.push_back(i);\n    }\n    assert(is2 == std::vector<int>({10,\
    \ 7, 4}));\n    std::vector<int> is3;\n    for (int i : irange(11, 2, -3)) {\n\
    \        is3.push_back(i);\n    }\n    assert(is3 == std::vector<int>({11, 8,\
    \ 5}));\n    std::vector<int> is4;\n    for (int i : irange(1, 2, -3)) {\n   \
    \     is4.push_back(i);\n    }\n    assert(is4.empty());\n}\nint main()\n{\n \
    \   repTest();\n    perTest();\n    irangeTest1();\n    irangeTest2();\n    std::cout\
    \ << \"Hello World\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"../../../src/misc/common/irange.hpp\"\n\nvoid repTest()\n{\n    std::vector<int>\
    \ is;\n    for (int i : rep(5)) {\n        is.push_back(i);\n    }\n    assert(is\
    \ == std::vector<int>({0, 1, 2, 3, 4}));\n}\n\nvoid perTest()\n{\n    std::vector<int>\
    \ is;\n    for (int i : per(5)) {\n        is.push_back(i);\n    }\n    assert(is\
    \ == std::vector<int>({4, 3, 2, 1, 0}));\n}\n\nvoid irangeTest1()\n{\n    std::vector<int>\
    \ is1;\n    for (int i : irange(2, 5)) {\n        is1.push_back(i);\n    }\n \
    \   assert(is1 == std::vector<int>({2, 3, 4}));\n\n    std::vector<int> is2;\n\
    \    for (int i : irange(2, 10, 3)) {\n        is2.push_back(i);\n    }\n    assert(is2\
    \ == std::vector<int>({2, 5, 8}));\n\n    std::vector<int> is3;\n    for (int\
    \ i : irange(2, 11, 3)) {\n        is3.push_back(i);\n    }\n    assert(is3 ==\
    \ std::vector<int>({2, 5, 8}));\n\n    std::vector<int> is4;\n    for (int i :\
    \ irange(2, 1, 3)) {\n        is4.push_back(i);\n    }\n    assert(is4.empty());\n\
    }\n\nvoid irangeTest2()\n{\n    std::vector<int> is2;\n    for (int i : irange(10,\
    \ 2, -3)) {\n        is2.push_back(i);\n    }\n    assert(is2 == std::vector<int>({10,\
    \ 7, 4}));\n\n    std::vector<int> is3;\n    for (int i : irange(11, 2, -3)) {\n\
    \        is3.push_back(i);\n    }\n    assert(is3 == std::vector<int>({11, 8,\
    \ 5}));\n\n    std::vector<int> is4;\n    for (int i : irange(1, 2, -3)) {\n \
    \       is4.push_back(i);\n    }\n    assert(is4.empty());\n}\n\nint main()\n\
    {\n    repTest();\n    perTest();\n    irangeTest1();\n    irangeTest2();\n  \
    \  std::cout << \"Hello World\\n\";\n    return 0;\n}\n"
  dependsOn:
  - src/misc/common/irange.hpp
  - src/misc/common/type_alias.hpp
  isVerificationFile: true
  path: verifications/misc/common/irange.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 03:45:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verifications/misc/common/irange.test.cpp
layout: document
redirect_from:
- /verify/verifications/misc/common/irange.test.cpp
- /verify/verifications/misc/common/irange.test.cpp.html
title: verifications/misc/common/irange.test.cpp
---
