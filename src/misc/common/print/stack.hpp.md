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
  bundledCode: "#include <stack>\n#include <iostream>\ntemplate<typename... Ts>\n\
    std::ostream& operator<<(std::ostream& os, const std::stack<Ts...>& vs)\n{\n \
    \   auto q = vs;\n    os << \"[\";\n    while (not q.empty()) { os << q.top()\
    \ << \",\", q.pop(); }\n    return os << \"]\\n\";\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <stack>\ntemplate<typename...\
    \ Ts>\nstd::ostream& operator<<(std::ostream& os, const std::stack<Ts...>& vs)\n\
    {\n    auto q = vs;\n    os << \"[\";\n    while (not q.empty()) { os << q.top()\
    \ << \",\", q.pop(); }\n    return os << \"]\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/common/print/stack.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/common/print/stack.hpp
layout: document
redirect_from:
- /library/src/misc/common/print/stack.hpp
- /library/src/misc/common/print/stack.hpp.html
title: src/misc/common/print/stack.hpp
---
