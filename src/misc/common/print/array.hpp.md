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
  bundledCode: "#include <array>\n#include <iostream>\ntemplate<typename T, int n>\n\
    std::ostream& operator<<(std::ostream& os, const std::array<T, n>& vs)\n{\n  \
    \  os << \"[\";\n    for (const auto& v : vs) { os << v << \",\"; }\n    return\
    \ (os << \"]\" << std::endl);\n}\n"
  code: "#pragma once\n#include <array>\n#include <iostream>\ntemplate<typename T,\
    \ int n>\nstd::ostream& operator<<(std::ostream& os, const std::array<T, n>& vs)\n\
    {\n    os << \"[\";\n    for (const auto& v : vs) { os << v << \",\"; }\n    return\
    \ (os << \"]\" << std::endl);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/common/print/array.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/common/print/array.hpp
layout: document
redirect_from:
- /library/src/misc/common/print/array.hpp
- /library/src/misc/common/print/array.hpp.html
title: src/misc/common/print/array.hpp
---
