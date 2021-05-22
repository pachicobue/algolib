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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: misc/common.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"misc/common.hpp\"\ntemplate<typename T>\nclass RBST\n\
    {\n    struct Node\n    {\n        Node(const T& v) : val{v}, sz{1} {}\n     \
    \   T val;\n        int sz = 0;\n        int pi = -1;\n        Arr<int, 2> sons\
    \ = {-1, -1};\n    };\n    using P = Pair<int, int>;\npublic:\n    RBST() {}\n\
    \    const Node& operator[](int r) const\n    {\n        return m_nodes[r];\n\
    \    }\n    Node& operator[](int r)\n    {\n        return m_nodes[r];\n    }\n\
    \    int get(int r, int k)\n    {\n        const auto& [lr, R] = split(r, k);\n\
    \        const auto& [mr, rr] = split(R, 1);\n        return mr;\n    }\n    int\
    \ merge(int i, int j)\n    {\n        if (i == -1 or j == -1) { return i == -1\
    \ ? j : i; }\n        const auto& [li, ri] = m_nodes[i].sons;\n        if (rng_xo.val<int>(0,\
    \ size(i) + size(j) - 1) < size(i)) {\n            const int rr = merge(m_nodes[i].ri,\
    \ j);\n            return m_nodes[i].ri = rr, m_nodes[rr].pi = i, up(i);\n   \
    \     } else {\n            const int lr = merge(m_nodes[j].li, i);\n        \
    \    return m_nodes[j].li = lr, m_nodes[lr].pi = j, up(j);\n        }\n    }\n\
    \    P split(int i, int k)\n    {\n        auto& [li, ri] = m_nodes[i].sons;\n\
    \        if (size(i) == 0) { return {-1, -1}; }\n        if (size(li) >= k) {\n\
    \            const auto& [lli, lri] = split(li, k);\n            li = lri;\n \
    \           m_nodes[lri].pi = i;\n            up(i);\n            return P{lli,\
    \ i};\n        } else {\n            const auto& [rli, rri] = split(ri, k - size(li)\
    \ - 1);\n            ri = rri;\n            m_nodes[rri].pi = i;\n           \
    \ up(i);\n            return P{i, rri};\n        }\n    }\n    int size(int r)\
    \ const\n    {\n        return r == -1 ? 0 : m_nodes[r].sz;\n    }\n    Vec<Node>\
    \ subNodes(int i) const\n    {\n        if (i == -1) { return Vec<Node>{}; }\n\
    \        const auto& [li, ri] = m_nodes[i].sons;\n        return subNodes(li)\
    \ + Vec<Node>{m_nodes[i]} + subNodes(ri);\n    }\n\nprivate:\n    int isRight(int\
    \ i)\n    {\n        return m_nodes[i].pi != -1 and m_nodes[m_nodes[i].pi].ri\
    \ == i;\n    }\n    int isLeft(int i)\n    {\n        return m_nodes[i].pi !=\
    \ -1 and m_nodes[m_nodes[i].pi].li == i;\n    }\n    int up(int i)\n    {\n  \
    \      const auto& [li, ri] = m_nodes[i].sons;\n        m_nodes[i].sz = size(li)\
    \ + size(ri) + 1;\n        return i;\n    }\n    int alloc(const T& v)\n    {\n\
    \        m_nodes.push_back(Node(v));\n        return m_nodes.size() - 1;\n   \
    \ }\n    Vec<Node> m_nodes;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/rbstree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/rbstree.hpp
layout: document
redirect_from:
- /library/src/data_structure/rbstree.hpp
- /library/src/data_structure/rbstree.hpp.html
title: src/data_structure/rbstree.hpp
---
