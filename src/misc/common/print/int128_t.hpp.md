---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
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
    path: src/misc/common/show.hpp
    title: src/misc/common/show.hpp
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
    \ = std::priority_queue<T, Vec<T>, Gt<T>>;\n#pragma endregion\n#line 3 \"src/misc/common/print/int128_t.hpp\"\
    \nOstream& operator<<(Ostream& os, i128 v)\n{\n    bool minus = false;\n    if\
    \ (v < 0) { minus = true, v = -v; }\n    Str ans;\n    if (v == 0) { ans = \"\
    0\"; }\n    while (v) {\n        ans.push_back('0' + v % 10), v /= 10;\n    }\n\
    \    std::reverse(ans.begin(), ans.end());\n    return os << (minus ? \"-\" :\
    \ \"\") << ans;\n}\nOstream& operator<<(Ostream& os, u128 v)\n{\n    Str ans;\n\
    \    if (v == 0) { ans = \"0\"; }\n    while (v) {\n        ans.push_back('0'\
    \ + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(), ans.end());\n    return\
    \ os << ans;\n}\n"
  code: "#pragma once\n#include \"../type_alias.hpp\"\nOstream& operator<<(Ostream&\
    \ os, i128 v)\n{\n    bool minus = false;\n    if (v < 0) { minus = true, v =\
    \ -v; }\n    Str ans;\n    if (v == 0) { ans = \"0\"; }\n    while (v) {\n   \
    \     ans.push_back('0' + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(),\
    \ ans.end());\n    return os << (minus ? \"-\" : \"\") << ans;\n}\nOstream& operator<<(Ostream&\
    \ os, u128 v)\n{\n    Str ans;\n    if (v == 0) { ans = \"0\"; }\n    while (v)\
    \ {\n        ans.push_back('0' + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(),\
    \ ans.end());\n    return os << ans;\n}\n"
  dependsOn:
  - src/misc/common/type_alias.hpp
  isVerificationFile: false
  path: src/misc/common/print/int128_t.hpp
  requiredBy:
  - src/misc/common.hpp
  - src/misc/stopwatch.hpp
  - src/misc/zipper.hpp
  - src/misc/printer.hpp
  - src/misc/common/show.hpp
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
documentation_of: src/misc/common/print/int128_t.hpp
layout: document
redirect_from:
- /library/src/misc/common/print/int128_t.hpp
- /library/src/misc/common/print/int128_t.hpp.html
title: src/misc/common/print/int128_t.hpp
---
