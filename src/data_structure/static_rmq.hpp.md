---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data_structure/ds_table.hpp
    title: Disjoint Sparse Table
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/lca.hpp
    title: src/graph/lca.hpp
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
  code: "#pragma once\n#include \"../misc/common.hpp\"\n#include \"ds_table.hpp\"\n\
    template<typename TotalOrd, typename B = u64>\nclass StaticRMQ\n{\n    using T\
    \ = typename TotalOrd::T;\npublic:\n    StaticRMQ(const Vec<T>& vs)\n        :\
    \ m_size(vs.size()),\n          m_bn(wind(m_size + bs - 1)),\n          m_vals{vs},\n\
    \          m_bucket_vals([&]() {\n              Vec<T> ans(m_bn);\n          \
    \    for (int i = 0; i < m_size; i++) {\n                  ans[wind(i)] = i %\
    \ bs == 0\n                                     ? m_vals[i]\n                \
    \                     : std::min(ans[wind(i)], m_vals[i], comp);\n           \
    \   }\n              return ans;\n          }()),\n          m_masks(m_size, 0),\n\
    \          m_st(m_bucket_vals)\n    {\n        for (int i : rep(m_bn)) {\n   \
    \         Vec<int> g(bs, m_size), stack;\n            for (const int j : rep(bs))\
    \ {\n                if (ind(i, j) >= m_size) { break; }\n                for\
    \ (; not stack.empty()\n                       and not comp(m_vals[stack.back()],\
    \ m_vals[ind(i, j)]);\n                     stack.pop_back()) {}\n           \
    \     g[j] = stack.empty() ? m_size : stack.back(),\n                stack.push_back(ind(i,\
    \ j));\n            }\n            for (int j : rep(bs)) {\n                if\
    \ (ind(i, j) >= m_size) { break; }\n                m_masks[ind(i, j)]\n     \
    \               = g[j] == m_size ? static_cast<B>(0)\n                       \
    \              : (m_masks[g[j]]\n                                        | static_cast<B>(1)\
    \ << (g[j] - i * bs));\n            }\n        }\n    }\n    T fold(int l, int\
    \ r) const\n    {\n        assert(0 <= l and l < r and r <= m_size);\n       \
    \ const int lb = (l + bs - 1) / bs, rb = r / bs;\n        if (lb > rb) {\n   \
    \         return brmq(l, r);\n        } else {\n            return lb < rb\n \
    \                      ? (l < bs * lb\n                              ? (bs * rb\
    \ < r ? std::min({m_st.fold(lb, rb),\n                                       \
    \                  brmq(l, bs * lb),\n                                       \
    \                  brmq(bs * rb, r)},\n                                      \
    \                  comp)\n                                             : std::min(m_st.fold(lb,\
    \ rb),\n                                                        brmq(l, bs * lb),\n\
    \                                                        comp))\n            \
    \                  : (bs * rb < r ? std::min(\n                              \
    \       m_st.fold(lb, rb), brmq(bs * rb, r), comp)\n                         \
    \                    : m_st.fold(lb, rb)))\n                       : (l < bs *\
    \ lb\n                              ? (bs * rb < r ? std::min(\n             \
    \                        brmq(l, bs * lb), brmq(bs * rb, r), comp)\n         \
    \                                    : brmq(l, bs * lb))\n                   \
    \           : (bs * rb < r ? brmq(bs * rb, r) : T{}));\n        }\n    }\nprivate:\n\
    \    static constexpr int bs = sizeof(B) * 8;\n    static constexpr int bslog\
    \ = log2p1(bs) - 1;\n    static constexpr int wind(const int n)\n    {\n     \
    \   return n >> (bslog);\n    }\n    static constexpr int bind(const int n)\n\
    \    {\n        return n ^ (wind(n) << bslog);\n    }\n    static constexpr int\
    \ ind(const int w, const int b)\n    {\n        return (w << bslog) | b;\n   \
    \ }\n    T brmq(int l, int r) const\n    {\n        const B w = m_masks[r - 1]\
    \ >> (l % bs);\n        return w == 0 ? m_vals[r - 1] : m_vals[l + lsbp1(w) -\
    \ 1];\n    }\n    struct SemiGroup\n    {\n        using T = typename TotalOrd::T;\n\
    \        T operator()(const T& x1, const T& x2) const\n        {\n           \
    \ return std::min(x1, x2, comp);\n        }\n    };\n    static inline TotalOrd\
    \ comp;\n    int m_size, m_bn;\n    Vec<T> m_vals, m_bucket_vals;\n    Vec<B>\
    \ m_masks;\n    DSTable<SemiGroup> m_st;\n};\n"
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
  - src/data_structure/ds_table.hpp
  isVerificationFile: false
  path: src/data_structure/static_rmq.hpp
  requiredBy:
  - src/graph/lca.hpp
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/static_rmq.hpp
layout: document
redirect_from:
- /library/src/data_structure/static_rmq.hpp
- /library/src/data_structure/static_rmq.hpp.html
title: src/data_structure/static_rmq.hpp
---
