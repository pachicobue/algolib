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
  bundledCode: "#include <iostream>\n#include <queue>\ntemplate<typename... Ts>\n\
    std::ostream& operator<<(std::ostream& os, const std::priority_queue<Ts...>& vs)\n\
    {\n    auto q = vs;\n    os << \"[\";\n    while (not q.empty()) { os << q.top()\
    \ << \",\", q.pop(); }\n    return os << \"]\\n\";\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <queue>\ntemplate<typename...\
    \ Ts>\nstd::ostream& operator<<(std::ostream& os, const std::priority_queue<Ts...>&\
    \ vs)\n{\n    auto q = vs;\n    os << \"[\";\n    while (not q.empty()) { os <<\
    \ q.top() << \",\", q.pop(); }\n    return os << \"]\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/common/print/priority_queue.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/common/print/priority_queue.hpp
layout: document
redirect_from:
- /library/src/misc/common/print/priority_queue.hpp
- /library/src/misc/common/print/priority_queue.hpp.html
title: src/misc/common/print/priority_queue.hpp
---
