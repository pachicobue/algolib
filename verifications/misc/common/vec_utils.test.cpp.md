---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  - icon: ':question:'
    path: src/misc/common/vec_utils.hpp
    title: src/misc/common/vec_utils.hpp
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
    using Sec = std::chrono::seconds;\n#pragma endregion\n#pragma region VecUtils\n\
    template<typename T>\nvoid fillAll(Vec<T>& vs, const T& v)\n{\n    std::fill(vs.begin(),\
    \ vs.end(), v);\n}\ntemplate<typename T, typename C = Lt<T>>\nvoid sortAll(Vec<T>&\
    \ vs, C comp = C{})\n{\n    std::sort(vs.begin(), vs.end(), comp);\n}\ntemplate<typename\
    \ T>\nvoid reverseAll(Vec<T>& vs)\n{\n    std::reverse(vs.begin(), vs.end());\n\
    }\ntemplate<typename T>\nvoid uniqueAll(Vec<T>& vs)\n{\n    sortAll(vs);\n   \
    \ vs.erase(std::unique(vs.begin(), vs.end()), vs.end());\n}\ntemplate<typename\
    \ T, typename V = T>\nV sumAll(const Vec<T>& vs)\n{\n    return std::accumulate(vs.begin(),\
    \ vs.end(), V{});\n}\ntemplate<typename T>\nint minInd(const Vec<T>& vs)\n{\n\
    \    return std::min_element(vs.begin(), vs.end()) - vs.begin();\n}\ntemplate<typename\
    \ T>\nint maxInd(const Vec<T>& vs)\n{\n    return std::max_element(vs.begin(),\
    \ vs.end()) - vs.begin();\n}\ntemplate<typename T>\nint lbInd(const Vec<T>& vs,\
    \ const T& v)\n{\n    return std::lower_bound(vs.begin(), vs.end(), v) - vs.begin();\n\
    }\ntemplate<typename T>\nint ubInd(const Vec<T>& vs, const T& v)\n{\n    return\
    \ std::upper_bound(vs.begin(), vs.end(), v) - vs.begin();\n}\ntemplate<typename\
    \ T, typename F>\nVec<T> genVec(int n, F gen)\n{\n    Vec<T> ans;\n    std::generate_n(std::back_insert_iterator(ans),\
    \ n, gen);\n    return ans;\n}\nVec<int> iotaVec(int n, int offset = 0)\n{\n \
    \   Vec<int> ans(n);\n    std::iota(ans.begin(), ans.end(), offset);\n    return\
    \ ans;\n}\ntemplate<typename T>\nVec<T> revVec(const Vec<T>& vs)\n{\n    auto\
    \ ans = vs;\n    reverseAll(ans);\n    return ans;\n}\n#pragma endregion\nvoid\
    \ fillAllTest()\n{\n    std::vector<int> vs{1, 3, 5, 2, 4};\n    fillAll(vs, 1);\n\
    \    assert(vs == std::vector<int>({1, 1, 1, 1, 1}));\n}\nvoid sortAllTest()\n\
    {\n    std::vector<int> vs{1, 3, 5, 2, 4};\n    sortAll(vs);\n    assert(vs ==\
    \ std::vector<int>({1, 2, 3, 4, 5}));\n}\nvoid reverseAllTest()\n{\n    std::vector<int>\
    \ vs{1, 3, 5, 2, 4};\n    reverseAll(vs);\n    assert(vs == std::vector<int>({4,\
    \ 2, 5, 3, 1}));\n}\nvoid uniqueAllTest()\n{\n    std::vector<int> vs{1, 2, 1,\
    \ 3, 3, 2};\n    uniqueAll(vs);\n    assert(vs == std::vector<int>({1, 2, 3}));\n\
    }\nvoid sumAllTest()\n{\n    std::vector<int> vs{1, 2, 1, 3, 3, 2};\n    assert(sumAll(vs)\
    \ == 12);\n}\nvoid minIndTest()\n{\n    std::vector<int> vs{2, 1, 1, 3, 3, 2};\n\
    \    assert(minInd(vs) == 1);\n}\nvoid maxIndTest()\n{\n    std::vector<int> vs{2,\
    \ 1, 1, 3, 3, 2};\n    assert(maxInd(vs) == 3);\n}\nvoid lbIndTest()\n{\n    std::vector<int>\
    \ vs{1, 1, 3, 3, 3, 5, 5};\n    assert(lbInd(vs, 0) == 0);\n    assert(lbInd(vs,\
    \ 1) == 0);\n    assert(lbInd(vs, 5) == 5);\n    assert(lbInd(vs, 6) == 7);\n\
    }\nvoid ubIndTest()\n{\n    std::vector<int> vs{1, 1, 3, 3, 3, 5, 5};\n    assert(ubInd(vs,\
    \ 0) == 0);\n    assert(ubInd(vs, 1) == 2);\n    assert(ubInd(vs, 5) == 7);\n\
    \    assert(ubInd(vs, 6) == 7);\n}\nvoid genVecTest()\n{\n    int x = 1;\n   \
    \ auto gen = [&]() {\n        const int y = x;\n        x *= 2;\n        return\
    \ y;\n    };\n    auto vs = genVec<int>(5, gen);\n    assert(vs == std::vector<int>({1,\
    \ 2, 4, 8, 16}));\n}\nvoid iotaVecTest()\n{\n    auto vs = iotaVec(5, 2);\n  \
    \  assert(vs == std::vector<int>({2, 3, 4, 5, 6}));\n}\nvoid revVecTest()\n{\n\
    \    std::vector<int> vs{1, 2, 1, 3, 3, 2};\n    assert(revVec(vs) == std::vector<int>({2,\
    \ 3, 3, 1, 2, 1}));\n}\nint main()\n{\n    fillAllTest();\n    sortAllTest();\n\
    \    reverseAllTest();\n    uniqueAllTest();\n    sumAllTest();\n    minIndTest();\n\
    \    maxIndTest();\n    lbIndTest();\n    ubIndTest();\n    genVecTest();\n  \
    \  iotaVecTest();\n    revVecTest();\n    std::cout << \"Hello World\\n\";\n \
    \   return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"../../../src/misc/common/vec_utils.hpp\"\n\nvoid fillAllTest()\n\
    {\n    std::vector<int> vs{1, 3, 5, 2, 4};\n    fillAll(vs, 1);\n    assert(vs\
    \ == std::vector<int>({1, 1, 1, 1, 1}));\n}\n\nvoid sortAllTest()\n{\n    std::vector<int>\
    \ vs{1, 3, 5, 2, 4};\n    sortAll(vs);\n    assert(vs == std::vector<int>({1,\
    \ 2, 3, 4, 5}));\n}\n\nvoid reverseAllTest()\n{\n    std::vector<int> vs{1, 3,\
    \ 5, 2, 4};\n    reverseAll(vs);\n    assert(vs == std::vector<int>({4, 2, 5,\
    \ 3, 1}));\n}\n\nvoid uniqueAllTest()\n{\n    std::vector<int> vs{1, 2, 1, 3,\
    \ 3, 2};\n    uniqueAll(vs);\n    assert(vs == std::vector<int>({1, 2, 3}));\n\
    }\n\nvoid sumAllTest()\n{\n    std::vector<int> vs{1, 2, 1, 3, 3, 2};\n    assert(sumAll(vs)\
    \ == 12);\n}\n\nvoid minIndTest()\n{\n    std::vector<int> vs{2, 1, 1, 3, 3, 2};\n\
    \    assert(minInd(vs) == 1);\n}\n\nvoid maxIndTest()\n{\n    std::vector<int>\
    \ vs{2, 1, 1, 3, 3, 2};\n    assert(maxInd(vs) == 3);\n}\n\nvoid lbIndTest()\n\
    {\n    std::vector<int> vs{1, 1, 3, 3, 3, 5, 5};\n    assert(lbInd(vs, 0) == 0);\n\
    \    assert(lbInd(vs, 1) == 0);\n    assert(lbInd(vs, 5) == 5);\n    assert(lbInd(vs,\
    \ 6) == 7);\n}\n\nvoid ubIndTest()\n{\n    std::vector<int> vs{1, 1, 3, 3, 3,\
    \ 5, 5};\n    assert(ubInd(vs, 0) == 0);\n    assert(ubInd(vs, 1) == 2);\n   \
    \ assert(ubInd(vs, 5) == 7);\n    assert(ubInd(vs, 6) == 7);\n}\n\nvoid genVecTest()\n\
    {\n    int x = 1;\n    auto gen = [&]() {\n        const int y = x;\n        x\
    \ *= 2;\n        return y;\n    };\n    auto vs = genVec<int>(5, gen);\n    assert(vs\
    \ == std::vector<int>({1, 2, 4, 8, 16}));\n}\n\nvoid iotaVecTest()\n{\n    auto\
    \ vs = iotaVec(5, 2);\n    assert(vs == std::vector<int>({2, 3, 4, 5, 6}));\n\
    }\n\nvoid revVecTest()\n{\n    std::vector<int> vs{1, 2, 1, 3, 3, 2};\n    assert(revVec(vs)\
    \ == std::vector<int>({2, 3, 3, 1, 2, 1}));\n}\n\nint main()\n{\n    fillAllTest();\n\
    \    sortAllTest();\n    reverseAllTest();\n    uniqueAllTest();\n    sumAllTest();\n\
    \    minIndTest();\n    maxIndTest();\n    lbIndTest();\n    ubIndTest();\n  \
    \  genVecTest();\n    iotaVecTest();\n    revVecTest();\n\n    std::cout << \"\
    Hello World\\n\";\n    return 0;\n}\n"
  dependsOn:
  - src/misc/common/vec_utils.hpp
  - src/misc/common/type_alias.hpp
  isVerificationFile: true
  path: verifications/misc/common/vec_utils.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 03:45:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/misc/common/vec_utils.test.cpp
layout: document
redirect_from:
- /verify/verifications/misc/common/vec_utils.test.cpp
- /verify/verifications/misc/common/vec_utils.test.cpp.html
title: verifications/misc/common/vec_utils.test.cpp
---
