---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <tuple>\n#include <iostream>\nnamespace print_tuple_impl\
    \ {\ntemplate<int n = 0, typename... Ts>\nvoid dump(std::ostream& os, const std::tuple<Ts...>&\
    \ v)\n{\n    constexpr int N = std::tuple_size<std::tuple<Ts...>>::value;\n  \
    \  if constexpr (n < N) { os << std::get<n>(v) << (n == N - 1 ? \"\" : \",\"),\
    \ dump<n + 1>(os, v); }\n}\n}\ntemplate<typename... Ts>\nstd::ostream& operator<<(std::ostream&\
    \ os, const std::tuple<Ts...>& v) { return (os << \"(\"), print_tuple_impl::dump(os,\
    \ v), (os << \")\"); }\n"
  code: "#pragma once\n#include <iostream>\n#include <tuple>\nnamespace print_tuple_impl\
    \ {\ntemplate<int n = 0, typename... Ts>\nvoid dump(std::ostream& os, const std::tuple<Ts...>&\
    \ v)\n{\n    constexpr int N = std::tuple_size<std::tuple<Ts...>>::value;\n  \
    \  if constexpr (n < N) { os << std::get<n>(v) << (n == N - 1 ? \"\" : \",\"),\
    \ dump<n + 1>(os, v); }\n}\n}  // namespace print_tuple_impl\ntemplate<typename...\
    \ Ts>\nstd::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& v)\
    \ { return (os << \"(\"), print_tuple_impl::dump(os, v), (os << \")\"); }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/common/print/tuple.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/common/print/tuple.hpp
layout: document
redirect_from:
- /library/src/misc/common/print/tuple.hpp
- /library/src/misc/common/print/tuple.hpp.html
title: src/misc/common/print/tuple.hpp
---
