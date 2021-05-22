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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../misc/types.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include \"../misc/types.hpp\"\
    \nstruct moddinfo64\n{\n    u64 mod{1}, r2{1}, inv{1};\n    void set_mod(const\
    \ u64 nmod)\n    {\n        assert(nmod < (1ULL << 62)), assert(nmod & 1);\n \
    \       mod = nmod, r2 = -u128(mod) % mod;\n        inv = mod;\n        for (int\
    \ i = 0; i < 5; i++) { inv *= 2 - mod * inv; }\n        assert(inv * mod == 1);\n\
    \    }\n    u64 reduce(const u128& x) const { return (x + u128((u64)x * -inv)\
    \ * mod) >> 64; }\n};\ntemplate<const moddinfo64& info>\nclass moddint64\n{\n\
    public:\n    static constexpr const u64& mod = info.mod;\n    constexpr moddint64()\
    \ : m_val{0} {}\n    constexpr moddint64(const i64 v) : m_val{info.reduce((u128(v)\
    \ + mod) * info.r2)} {}\n    constexpr moddint64 operator-() const { return moddint64{}\
    \ - (*this); }\n    constexpr moddint64& operator+=(const moddint64& m)\n    {\n\
    \        if (i64(m_val += m.m_val - 2 * mod) < 0) { m_val += 2 * mod; }\n    \
    \    return *this;\n    }\n    constexpr moddint64& operator-=(const moddint64&\
    \ m)\n    {\n        if (i64(m_val -= m.m_val) < 0) { m_val += 2 * mod; }\n  \
    \      return *this;\n    }\n    constexpr moddint64& operator*=(const moddint64&\
    \ m) { return m_val = info.reduce(u128(m_val) * m.m_val), *this; }\n    constexpr\
    \ moddint64& operator/=(const moddint64& m) { return *this *= m.inv(); }\n   \
    \ constexpr moddint64 operator+(const moddint64& m) const { return moddint64{*this}\
    \ += m; }\n    constexpr moddint64 operator-(const moddint64& m) const { return\
    \ moddint64{*this} -= m; }\n    constexpr moddint64 operator*(const moddint64&\
    \ m) const { return moddint64{*this} *= m; }\n    constexpr moddint64 operator/(const\
    \ moddint64& m) const { return moddint64{*this} /= m; }\n    constexpr bool operator==(const\
    \ moddint64& m) const { return (m_val >= mod ? m_val - mod : m_val) == (m.m_val\
    \ >= mod ? m.m_val - mod : m.m_val); }\n    constexpr bool operator!=(const moddint64&\
    \ m) const { return not(*this == m); }\n    friend std::istream& operator>>(std::istream&\
    \ is, moddint64& m)\n    {\n        i64 v;\n        return is >> v, m = v, is;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const moddint64&\
    \ m) { return os << m(); }\n    constexpr u64 get() const\n    {\n        const\
    \ u64 m = info.reduce(m_val);\n        return m >= mod ? m - mod : m;\n    }\n\
    \    constexpr u64 operator()() const { return get(); }\n    constexpr moddint64\
    \ pow(u128 n) const\n    {\n        moddint64 ans = 1;\n        for (moddint64\
    \ x = *this; n > 0; n >>= 1, x *= x) {\n            if (n & 1) { ans *= x; }\n\
    \        }\n        return ans;\n    }\n    constexpr moddint64 inv() const {\
    \ return pow(mod - 2); }\n\nprivate:\n    u64 m_val;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/moddint64.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/moddint64.hpp
layout: document
redirect_from:
- /library/src/math/moddint64.hpp
- /library/src/math/moddint64.hpp.html
title: src/math/moddint64.hpp
---
