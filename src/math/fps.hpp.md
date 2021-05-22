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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/bit_ops.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include \"../misc/bit_ops.hpp\"\n#include \"../misc/range.hpp\"\n#include \"\
    modint.hpp\"\n\ntemplate<typename mint>\nclass fps : public std::vector<mint>\n\
    {\npublic:\n    using std::vector<mint>::vector;\n    using std::vector<mint>::resize;\n\
    \    fps(const std::vector<mint>& vs) : std::vector<mint>{vs} {}\n    int size()\
    \ const { return std::vector<mint>::size(); }\n    int deg() const { return size()\
    \ - 1; }\n    fps low(const int n) const { return fps{this->begin(), this->begin()\
    \ + std::min(n, size())}; }\n    fps rev() const\n    {\n        fps ans = *this;\n\
    \        std::reverse(ans.begin(), ans.end());\n        return ans;\n    }\n \
    \   mint eval(const mint& x) const\n    {\n        mint ans   = 0;\n        mint\
    \ power = 1;\n        for (int i = 0; i < size(); i++, power *= x) { ans += power\
    \ * (*this)[i]; }\n        return ans;\n    }\n    mint& operator[](const int\
    \ n)\n    {\n        if (size() < n + 1) { resize(n + 1); }\n        return std::vector<mint>::operator[](n);\n\
    \    }\n    const mint& operator[](const int n) const { return std::vector<mint>::operator[](n);\
    \ }\n    mint at(const int n) const { return (n < size() ? (*this)[n] : mint{0});\
    \ }\n    fps operator-() const\n    {\n        fps ans = *this;\n        for (auto&\
    \ v : ans) { v = -v; }\n        return ans;\n    }\n    fps& operator+=(const\
    \ fps& f)\n    {\n        for (int i = 0; i < f.size(); i++) { (*this)[i] += f[i];\
    \ }\n        return *this;\n    }\n    fps& operator-=(const fps& f)\n    {\n\
    \        for (int i = 0; i < f.size(); i++) { (*this)[i] -= f[i]; }\n        return\
    \ *this;\n    }\n    fps& operator*=(const fps& f) { return (*this) = (*this)\
    \ * f; }\n    fps& operator<<=(const int s) { return *this = (*this << s); }\n\
    \    fps& operator>>=(const int s) { return *this = (*this >> s); }\n    fps operator+(const\
    \ fps& f) const { return fps(*this) += f; }\n    fps operator-(const fps& f) const\
    \ { return fps(*this) -= f; }\n    fps operator*(const fps& f) const { return\
    \ mult(f, size() + f.size() - 1); }\n    fps operator<<(const int s) const\n \
    \   {\n        fps ans(size() + s);\n        for (int i = 0; i < size(); i++)\
    \ { ans[i + s] = (*this)[i]; }\n        return ans;\n    }\n    fps operator>>(const\
    \ int s) const\n    {\n        fps ans;\n        for (int i = s; i < size(); i++)\
    \ { ans[i - s] = (*this)[i]; }\n        return ans;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const fps& f) { return os << static_cast<std::vector<mint>>(f);\
    \ }\n\n    fps derivative() const\n    {\n        fps ans;\n        for (int i\
    \ = 1; i < size(); i++) { ans[i - 1] = (*this)[i] * i; }\n        return ans;\n\
    \    }\n    fps integral() const\n    {\n        fps ans;\n        for (int i\
    \ = 1; i <= size(); i++) { ans[i] = (*this)[i - 1] * mint::sinv(i); }\n      \
    \  return ans;\n    }\n    fps mult(const fps& f, const int sz) const\n    {\n\
    \        if (sz == 0) { return fps{}; }\n        const int N = std::min(size(),\
    \ sz) + std::min(f.size(), sz) - 1;\n        if (N <= 16) {\n            fps ans(sz);\n\
    \            for (int i = 0; i < std::min(size(), sz); i++) {\n              \
    \  for (int j = 0; j < f.size() and i + j < sz; j++) { ans[i + j] += (*this)[i]\
    \ * f[j]; }\n            }\n            return ans;\n        } else if (N <= (1\
    \ << mint::max2p)) {\n            auto ans = conv<mint>(*this, f, sz);\n     \
    \       return ans;\n        } else {\n            const auto cs1 = conv<submint1>(*this,\
    \ f, sz);\n            const auto cs2 = conv<submint2>(*this, f, sz);\n      \
    \      const auto cs3 = conv<submint3>(*this, f, sz);\n            fps ans((int)cs1.size());\n\
    \            for (int i = 0; i < (int)cs1.size(); i++) { ans[i] = restore(cs1[i](),\
    \ cs2[i](), cs3[i]()); }\n            return ans;\n        }\n    }\n    fps smult(const\
    \ int p, const mint a, const int sz)  // *(1+ax^p) (mod x^sz)\n    {\n       \
    \ fps ans = low(sz);\n        for (int i = 0; i + p < sz; i++) { ans[i + p] +=\
    \ (*this)[i] * a; }\n        return ans;\n    }\n    fps sdiv(const int p, const\
    \ mint a, const int sz)  // *(1+ax^p)^(-1) (mod x^sz)\n    {\n        fps ans\
    \ = low(sz);\n        for (int i = 0; i + p < sz; i++) { ans[i + p] -= ans[i]\
    \ * a; }\n        return ans;\n    }\n    fps inv(const int sz) const\n    {\n\
    \        const int n = size();\n        assert((*this)[0]() != 0);\n        const\
    \ int N = n * 2 - 1;\n        if (N <= (1 << mint::max2p)) {\n            fps\
    \ r{(*this)[0].inv()};\n            for (int lg = 0, m = 1; m < sz; m <<= 1, lg++)\
    \ {\n                fps f{this->begin(), this->begin() + std::min(n, 2 * m)};\n\
    \                fps g = r;\n                f.resize(2 * m), g.resize(2 * m);\n\
    \                trans(f, lg + 1, false), trans(g, lg + 1, false);\n         \
    \       for (int i = 0; i < 2 * m; i++) { f[i] *= g[i]; }\n                trans(f,\
    \ lg + 1, true);\n                std::fill(f.begin(), f.begin() + m, 0);\n  \
    \              trans(f, lg + 1, false);\n                for (int i = 0; i < 2\
    \ * m; i++) { f[i] *= g[i]; }\n                trans(f, lg + 1, true);\n     \
    \           for (int i = m; i < std::min(2 * m, sz); i++) { r[i] = -f[i]; }\n\
    \            }\n            return r;\n        } else {\n            fps g{(*this)[0].inv()};\n\
    \            for (int lg = 0, m = 1; m < sz; m <<= 1, lg++) { g = fps{2} * g -\
    \ this->mult(g.mult(g, 2 * m), 2 * m); }\n            return g.low(sz);\n    \
    \    }\n    }\n    fps log(const int sz) const\n    {\n        assert((*this)[0]()\
    \ == 1);\n        auto ans = derivative().mult(inv(sz), sz).integral();\n    \
    \    ans.resize(sz);\n        return ans;\n    }\n    fps exp(const int sz) const\n\
    \    {\n        const int l = lsb(sz);\n        if (l == -1) { return fps{1}.low(sz);\
    \ }\n        assert((*this)[0]() == 0);\n\n        const int n = size();\n   \
    \     const int N = n * 2 - 1;\n        if (N <= (1 << mint::max2p)) {\n     \
    \       fps f = {1, (*this)[1]}, g{1}, G{1, 1};\n            for (int m = 2, lg\
    \ = 1; m < sz; m <<= 1, lg++) {\n                auto F = f;\n               \
    \ F.resize(2 * m), trans(F, lg + 1, false);\n                fps z(m);\n     \
    \           for (int i = 0; i < m; i++) { z[i] = F[i] * G[i]; }\n            \
    \    trans(z, lg, true);\n                std::fill(z.begin(), z.begin() + m /\
    \ 2, 0);\n                trans(z, lg, false);\n                for (int i = 0;\
    \ i < m; i++) { z[i] *= G[i]; }\n                trans(z, lg, true);\n       \
    \         for (int i = m / 2; i < m; i++) { g[i] = -z[i]; }\n                G\
    \      = g, G.resize(m * 2), trans(G, lg + 1, false);\n                auto q\
    \ = low(m).derivative();\n                q.resize(m), trans(q, lg, false);\n\
    \                for (int i = 0; i < m; i++) { q[i] *= F[i]; }\n             \
    \   trans(q, lg, true);\n                const auto df = f.derivative();\n   \
    \             for (int i = 0; i < m - 1; i++) { q[i] -= df[i]; }\n           \
    \     q.resize(m * 2);\n                for (int i = 0; i < m - 1; i++) { q[m\
    \ + i] = q[i], q[i] = 0; }\n                trans(q, lg + 1, false);\n       \
    \         for (int i = 0; i < m * 2; i++) { q[i] *= G[i]; }\n                trans(q,\
    \ lg + 1, true), q.pop_back(), q = q.integral();\n                for (int i =\
    \ m; i < std::min(size(), m * 2); i++) { q[i] += (*this)[i]; }\n             \
    \   std::fill(q.begin(), q.begin() + m, 0), trans(q, lg + 1, false);\n       \
    \         for (int i = 0; i < m * 2; i++) { q[i] *= F[i]; }\n                trans(q,\
    \ lg + 1, true);\n                for (int i = m; i < 2 * m; i++) { f[i] = q[i];\
    \ }\n            }\n            return f.low(sz);\n        } else {\n        \
    \    fps f{1};\n            for (int m = 1; m < sz; m <<= 1) {\n             \
    \   auto g = low(2 * m);\n                g[0] += 1;\n                f.resize(2\
    \ * m);\n                g -= f.log(2 * m);\n                g = f.mult(g, 2 *\
    \ m);\n                for (int i = m; i < std::min(2 * m, g.size()); i++) { f[i]\
    \ = g[i]; }\n            }\n            return f.low(sz);\n        }\n    }\n\
    \    fps pow(const int n, int sz = -1) const\n    {\n        if (sz == -1) { sz\
    \ = deg() * n + 1; }\n        if (n == 0) { return fps{1}.low(sz); }\n       \
    \ if (size() == 0) { return fps{}; }\n        const int p = lsb((size() - 1) /\
    \ n);\n        if (p == -1) { return fps{}; }\n        const mint a = (*this)[p];\n\
    \        fps f        = (*this) >> p;\n        for (auto& c : f) { c /= a; }\n\
    \        f = f.log(sz - p * n);\n        for (auto& c : f) { c *= n; }\n     \
    \   f = f.exp(sz - p * n);\n        fps g;\n        for (int i = 0; i < f.size();\
    \ i++) { g[i + p * n] = f[i] * a.pow(n); }\n        return g;\n    }\n    fps\
    \ tshift(const mint c) const\n    {\n        const int N = size();\n        fps\
    \ f(N), d(N);\n        for (int i = 0; i < N; i++) { d[i] = c.pow(N - 1 - i) *\
    \ mint::ifact(N - 1 - i); }\n        for (int i = 0; i < N; i++) { f[i] = (*this)[i]\
    \ * mint::fact(i); }\n        f = f * d;\n        fps g(N);\n        for (int\
    \ i = 0; i < N; i++) { g[i] = f[i + N - 1] * mint::ifact(i); }\n        return\
    \ g;\n    }\n    fps quot(const fps& g) const\n    {\n        const int N = size(),\
    \ M = g.size();\n        if (N < M) { return fps{}; }\n        const auto fR =\
    \ rev(), gR = g.rev();\n        return fR.mult(gR.inv(N - M + 1), N - M + 1).rev();\n\
    \    }\n    fps rem(const fps& g) const { return (*this) - g * quot(g); }\n\n\
    private:\n    int lsb(int sz = -1) const\n    {\n        if (sz == -1) { sz =\
    \ size() - 1; }\n        for (int p = 0; p <= sz; p++) {\n            if ((*this)[p]()\
    \ != 0) { return p; }\n        }\n        return -1;\n    }\n\n    static constexpr\
    \ modinfo info1 = {469762049, 3, 26};\n    static constexpr modinfo info2 = {167772161,\
    \ 3, 25};\n    static constexpr modinfo info3 = {754974721, 11, 24};\n    using\
    \ submint1                 = modint<info1>;\n    using submint2              \
    \   = modint<info2>;\n    using submint3                 = modint<info3>;\n  \
    \  template<typename submint>\n    static void trans(std::vector<submint>& as,\
    \ const int lg, const bool rev)\n    {\n        const int N = 1 << lg;\n     \
    \   assert((int)as.size() == N);\n        std::vector<submint> rs, irs;\n    \
    \    if (rs.empty()) {\n            const submint r = submint(submint::root),\
    \ ir = r.inv();\n            rs.resize(submint::max2p + 1), irs.resize(submint::max2p\
    \ + 1);\n            rs.back() = -r.pow((submint::mod - 1) >> submint::max2p),\
    \ irs.back() = -ir.pow((submint::mod - 1) >> submint::max2p);\n            for\
    \ (uint i = submint::max2p; i >= 1; i--) { rs[i - 1] = -(rs[i] * rs[i]), irs[i\
    \ - 1] = -(irs[i] * irs[i]); }\n        }\n        const auto drange = (rev ?\
    \ range(0, lg, 1) : range(lg - 1, -1, -1));\n        for (const int d : drange)\
    \ {\n            const int width = 1 << d;\n            submint e       = 1;\n\
    \            for (int i = 0, j = 1; i < N; i += width * 2, j++) {\n          \
    \      for (int l = i, r = i + width; l < i + width; l++, r++) {\n           \
    \         const submint x = as[l], y = (rev ? as[r] : as[r] * e);\n          \
    \          as[l] = x + y, as[r] = (rev ? (x - y) * e : x - y);\n             \
    \   }\n                e *= (rev ? irs : rs)[lsbp1(j) + 1];\n            }\n \
    \       }\n        if (rev) {\n            const submint iN = submint{N}.inv();\n\
    \            for (auto& a : as) { a *= iN; }\n        }\n    }\n    template<typename\
    \ submint>\n    static std::vector<submint> conv(const std::vector<mint>& as,\
    \ const std::vector<mint>& bs, const int sz)\n    {\n        const int M = std::min((int)as.size(),\
    \ sz) + std::min((int)bs.size(), sz) - 1, lg = clog(M);\n        const int L =\
    \ 1 << lg;\n        std::vector<submint> As(L), Bs(L);\n        for (int i = 0;\
    \ i < std::min((int)as.size(), sz); i++) { As[i] = as[i](); }\n        for (int\
    \ i = 0; i < std::min((int)bs.size(), sz); i++) { Bs[i] = bs[i](); }\n       \
    \ trans(As, lg, false), trans(Bs, lg, false);\n        for (int i = 0; i < L;\
    \ i++) { As[i] *= Bs[i]; }\n        trans(As, lg, true);\n        const int N\
    \ = std::min(sz, (int)as.size() + (int)bs.size() - 1);\n        As.resize(N);\n\
    \        return As;\n    }\n    static constexpr submint2 ip1   = submint2{submint1::mod}.inv();\n\
    \    static constexpr submint3 ip2   = submint3{submint2::mod}.inv();\n    static\
    \ constexpr submint3 ip1p2 = submint3{submint1::mod}.inv() * submint3{submint2::mod}.inv();\n\
    \    static constexpr mint p1        = mint{submint1::mod};\n    static constexpr\
    \ mint p1p2      = mint{submint1::mod} * mint{submint2::mod};\n    static constexpr\
    \ mint restore(const int x1, const int x2, const int x3)\n    {\n        const\
    \ int k0 = x1, k1 = (ip1 * (x2 - k0))(), k2 = (ip1p2 * (x3 - k0) - ip2 * k1)();\n\
    \        return p1p2 * k2 + p1 * k1 + k0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/fps.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/fps.hpp
layout: document
redirect_from:
- /library/src/math/fps.hpp
- /library/src/math/fps.hpp.html
title: src/math/fps.hpp
---
