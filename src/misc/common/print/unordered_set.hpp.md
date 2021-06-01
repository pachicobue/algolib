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
  bundledCode: "#include <unordered_set>\n#include <iostream>\ntemplate<typename...\
    \ Ts>\nstd::ostream& operator<<(std::ostream& os, const std::unordered_set<Ts...>&\
    \ vs)\n{\n    os << \"[\";\n    for (const auto& v : vs) { os << v << \",\"; }\n\
    \    return (os << \"]\" << std::endl);\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <unordered_set>\ntemplate<typename...\
    \ Ts>\nstd::ostream& operator<<(std::ostream& os, const std::unordered_set<Ts...>&\
    \ vs)\n{\n    os << \"[\";\n    for (const auto& v : vs) { os << v << \",\"; }\n\
    \    return (os << \"]\" << std::endl);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/common/print/unordered_set.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/common/print/unordered_set.hpp
layout: document
redirect_from:
- /library/src/misc/common/print/unordered_set.hpp
- /library/src/misc/common/print/unordered_set.hpp.html
title: src/misc/common/print/unordered_set.hpp
---
