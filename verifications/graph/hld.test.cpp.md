---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 72, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 478, in update\n    self._update2(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 457, in _update2\n    subprocess.check_call(commands)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/subprocess.py\"\
    , line 373, in check_call\n    raise CalledProcessError(retcode, cmd)\nsubprocess.CalledProcessError:\
    \ Command '['g++', 'verifications/graph/hld.test.cpp', '-o', 'verifications/graph/hld.test.tmp',\
    \ '-E', '-P', '-I', '/home/runner/work/algolib/algolib/dummy_headers', '-I', '/home/runner/work/algolib/algolib']'\
    \ returned non-zero exit status 1.\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"../../src/data_structure/segtree.hpp\"\n#include \"../../src/graph/hld.hpp\"\
    \n#include \"../../src/math/modint.hpp\"\n#include \"../../src/misc/fastio/printer.hpp\"\
    \n#include \"../../src/misc/fastio/scanner.hpp\"\nint main()\n{\n    using mint\
    \ = modint_998244353;\n    const auto [N, Q] = in.tup<int, int>();\n    Graph\
    \ g(N);\n    using Func = Pair<mint, mint>;\n    struct Monoid\n    {\n      \
    \  using T = Func;\n        static const T e()\n        {\n            return\
    \ T{1, 0};\n        }\n        T operator()(const T& f2, const T& f1) const\n\
    \        {\n            return T{f1.first * f2.first, f1.first * f2.second + f1.second};\n\
    \        }\n    };\n    struct RMonoid\n    {\n        using T = Func;\n     \
    \   static const T e()\n        {\n            return T{1, 0};\n        }\n  \
    \      T operator()(const T& f1, const T& f2) const\n        {\n            return\
    \ T{f1.first * f2.first, f1.first * f2.second + f1.second};\n        }\n    };\n\
    \n    std::vector<mint> as(N), bs(N);\n    for (int i : rep(N)) {\n        std::tie(as[i],\
    \ bs[i]) = in.tup<mint, mint>();\n    }\n    for (int i : rep(N - 1)) {\n    \
    \    const auto [u, v] = in.tup<int, int>();\n        g.addEdge(u, v, true);\n\
    \    }\n    const HLD hld{g};\n    std::vector<Func> vs(N);\n    for (int i :\
    \ rep(N)) {\n        vs[hld.pos(i)] = Func{as[i], bs[i]};\n    }\n    auto seg\
    \ = SegTree<Monoid>(vs);\n    auto rseg = SegTree<RMonoid>(vs);\n    for (int\
    \ q : rep(Q)) {\n        const auto t = in.val<int>();\n        if (t == 0) {\n\
    \            const auto [p, c, d] = in.tup<int, mint, mint>();\n            seg.set(hld.pos(p),\
    \ {c, d}), rseg.set(hld.pos(p), {c, d});\n        } else {\n            const\
    \ auto [u, v, x] = in.tup<int, int, mint>();\n            const auto ps = hld.path(u,\
    \ v);\n            Func f{1, 0};\n            for (const auto& [a, b] : ps) {\n\
    \                f = Monoid{}(f,\n                             a <= b ? seg.fold(a,\
    \ b + 1) : rseg.fold(b, a + 1));\n            }\n            out.ln((f.first *\
    \ x + f.second).val());\n        }\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verifications/graph/hld.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verifications/graph/hld.test.cpp
layout: document
redirect_from:
- /verify/verifications/graph/hld.test.cpp
- /verify/verifications/graph/hld.test.cpp.html
title: verifications/graph/hld.test.cpp
---
