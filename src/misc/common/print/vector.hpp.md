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
  bundledCode: "#line 2 \"src/misc/common/print/vector.hpp\"\n#include <iostream>\n\
    #include <vector>\ntemplate<typename... Ts>\nstd::ostream& operator<<(std::ostream&\
    \ os, const std::vector<Ts...>& vs)\n{\n    os << \"[\";\n    for (const auto&\
    \ v : vs) { os << v << \",\"; }\n    return (os << \"]\" << std::endl);\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\ntemplate<typename...\
    \ Ts>\nstd::ostream& operator<<(std::ostream& os, const std::vector<Ts...>& vs)\n\
    {\n    os << \"[\";\n    for (const auto& v : vs) { os << v << \",\"; }\n    return\
    \ (os << \"]\" << std::endl);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/common/print/vector.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/common/print/vector.hpp
layout: document
redirect_from:
- /library/src/misc/common/print/vector.hpp
- /library/src/misc/common/print/vector.hpp.html
title: src/misc/common/print/vector.hpp
---
