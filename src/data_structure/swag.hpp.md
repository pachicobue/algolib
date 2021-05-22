---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/misc/common.hpp
    title: src/misc/common.hpp
  - icon: ':warning:'
    path: src/misc/common/bit_ops.hpp
    title: src/misc/common/bit_ops.hpp
  - icon: ':warning:'
    path: src/misc/common/constants.hpp
    title: src/misc/common/constants.hpp
  - icon: ':warning:'
    path: src/misc/common/fixpoint.hpp
    title: src/misc/common/fixpoint.hpp
  - icon: ':warning:'
    path: src/misc/common/func_alias.hpp
    title: src/misc/common/func_alias.hpp
  - icon: ':warning:'
    path: src/misc/common/nd_vec.hpp
    title: src/misc/common/nd_vec.hpp
  - icon: ':warning:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
  - icon: ':warning:'
    path: src/misc/common/range.hpp
    title: src/misc/common/range.hpp
  - icon: ':warning:'
    path: src/misc/common/rng.hpp
    title: src/misc/common/rng.hpp
  - icon: ':warning:'
    path: src/misc/common/show.hpp
    title: src/misc/common/show.hpp
  - icon: ':warning:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  - icon: ':warning:'
    path: src/misc/common/xoshiro.hpp
    title: src/misc/common/xoshiro.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/misc/common/show.hpp: line 5: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename SemiGroup>\n\
    class SWAG\n{\n    using T = typename SemiGroup::T;\npublic:\n    SWAG() : m_merge{}\
    \ {}\n    void pushBack(const T& x)\n    {\n        m_backs.push_back(x);\n  \
    \      m_Backs.push_back(m_Backs.empty() ? x : m_merge(m_Backs.back(), x));\n\
    \    }\n    void pushFront(const T& x)\n    {\n        m_fronts.push_back(x);\n\
    \        m_Fronts.push_back(m_Fronts.empty() ? x : m_merge(x, m_Fronts.back()));\n\
    \    }\n    void popBack()\n    {\n        if (m_Backs.empty()) {\n          \
    \  Vec<T> as = m_fronts;\n            m_fronts.clear(), m_Fronts.clear();\n  \
    \          reverseAll(as);\n            const int f = (int)as.size() / 2;\n  \
    \          for (int i : per(f)) {\n                m_fronts.push_back(as[i]);\n\
    \            }\n            for (int i : range(f, (int)as.size())) {\n       \
    \         m_backs.push_back(as[i]);\n            }\n            calc();\n    \
    \    } else {\n            m_backs.pop_back(), m_Backs.pop_back();\n        }\n\
    \    }\n    void popFront()\n    {\n        if (m_Fronts.empty()) {\n        \
    \    Vec<T> as = m_backs;\n            m_backs.clear(), m_Backs.clear();\n   \
    \         const int f = ((int)as.size() + 1) / 2;\n            for (int i : per(f))\
    \ {\n                m_fronts.push_back(as[i]);\n            }\n            for\
    \ (int i : range(f, (int)as.size())) {\n                m_backs.push_back(as[i]);\n\
    \            }\n            calc();\n        } else {\n            m_fronts.pop_back(),\
    \ m_Fronts.pop_back();\n        }\n    }\n    T fold() const\n    {\n        return\
    \ m_fronts.empty()\n                   ? m_Backs.back()\n                   :\
    \ (m_backs.empty()\n                          ? m_Fronts.back()\n            \
    \              : m_merge(m_Fronts.back(), m_Backs.back()));\n    }\n    friend\
    \ Ostream& operator<<(Ostream& os, const SWAG& sw)\n    {\n        Vec<T> as =\
    \ sw.fs;\n        reverseAll(as);\n        as += sw.bs;\n        os << \"vs =\
    \ [\";\n        for (const T& a : as) {\n            os << a << \",\";\n     \
    \   }\n        return os << \"]\";\n    }\n    int size() const\n    {\n     \
    \   return (int)m_fronts.size() + (int)m_backs.size();\n    }\n    bool empty()\
    \ const\n    {\n        return m_fronts.empty() and m_backs.empty();\n    }\n\
    private:\n    void calc()\n    {\n        if (not m_fronts.empty()) {\n      \
    \      m_Fronts.push_back(m_fronts[0]);\n            for (int i : range(1, m_fronts.size()))\
    \ {\n                m_Fronts.push_back(m_merge(m_fronts[i], m_Fronts.back()));\n\
    \            }\n        }\n        if (not m_backs.empty()) {\n            m_Backs.push_back(m_backs[0]);\n\
    \            for (int i : range(1, m_backs.size())) {\n                m_Backs.push_back(m_merge(m_Backs.back(),\
    \ m_backs[i]));\n            }\n        }\n    }\n    Vec<T> m_fronts, m_backs;\n\
    \    Vec<T> m_Fronts, m_Backs;\n    SemiGroup m_merge;\n};\n"
  dependsOn:
  - src/misc/common.hpp
  - src/misc/common/type_alias.hpp
  - src/misc/common/constants.hpp
  - src/misc/common/func_alias.hpp
  - src/misc/common/show.hpp
  - src/misc/common/print/int128_t.hpp
  - src/misc/common/bit_ops.hpp
  - src/misc/common/fixpoint.hpp
  - src/misc/common/nd_vec.hpp
  - src/misc/common/range.hpp
  - src/misc/common/rng.hpp
  - src/misc/common/xoshiro.hpp
  isVerificationFile: false
  path: src/data_structure/swag.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/swag.hpp
layout: document
redirect_from:
- /library/src/data_structure/swag.hpp
- /library/src/data_structure/swag.hpp.html
title: src/data_structure/swag.hpp
---
