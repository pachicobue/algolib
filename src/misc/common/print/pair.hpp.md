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
  bundledCode: '#include <iostream>

    #include <utility>

    template<typename T1, typename T2>

    std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& v) { return
    (os << "(" << v.first << "," << v.second << ")"); }

    '
  code: '#pragma once

    #include <iostream>

    #include <utility>

    template<typename T1, typename T2>

    std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& v) { return
    (os << "(" << v.first << "," << v.second << ")"); }

    '
  dependsOn: []
  isVerificationFile: false
  path: src/misc/common/print/pair.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/common/print/pair.hpp
layout: document
redirect_from:
- /library/src/misc/common/print/pair.hpp
- /library/src/misc/common/print/pair.hpp.html
title: src/misc/common/print/pair.hpp
---
