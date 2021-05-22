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
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include \"../misc/common.hpp\"\
    \nstruct moddinfo\n{\n    u32 mod{1}, r2{1}, inv{1};\n    void set_mod(const u32\
    \ nmod)\n    {\n        assert(nmod < (1ULL << 30)), assert(nmod & 1);\n     \
    \   mod = nmod, r2 = -u64(mod) % mod;\n        inv = mod;\n        for (int i\
    \ = 0; i < 4; i++) { inv *= 2 - mod * inv; }\n        assert(inv * mod == 1);\n\
    \    }\n    u32 reduce(const u64 x) const { return (x + u64(u32(x) * u32(-inv))\
    \ * mod) >> 32; }\n};\ntemplate<const moddinfo& info>\nclass moddint\n{\npublic:\n\
    \    static constexpr const u32& mod = info.mod;\n    constexpr moddint() : m_val{0}\
    \ {}\n    constexpr moddint(const i64 v) : m_val{info.reduce(u64(v % mod + mod)\
    \ * info.r2)} {}\n    constexpr moddint operator-() const { return moddint{} -\
    \ (*this); }\n    constexpr moddint& operator+=(const moddint& m)\n    {\n   \
    \     if (i32(m_val += m.m_val - 2 * mod) < 0) { m_val += 2 * mod; }\n       \
    \ return *this;\n    }\n    constexpr moddint& operator-=(const moddint& m)\n\
    \    {\n        if (i32(m_val -= m.m_val) < 0) { m_val += 2 * mod; }\n       \
    \ return *this;\n    }\n    constexpr moddint& operator*=(const moddint& m) {\
    \ return m_val = info.reduce(u64(m_val) * m.m_val), *this; }\n    constexpr moddint&\
    \ operator/=(const moddint& m) { return *this *= m.inv(); }\n    constexpr moddint\
    \ operator+(const moddint& m) const { return moddint{*this} += m; }\n    constexpr\
    \ moddint operator-(const moddint& m) const { return moddint{*this} -= m; }\n\
    \    constexpr moddint operator*(const moddint& m) const { return moddint{*this}\
    \ *= m; }\n    constexpr moddint operator/(const moddint& m) const { return moddint{*this}\
    \ /= m; }\n    constexpr bool operator==(const moddint& m) const { return (m_val\
    \ >= mod ? m_val - mod : m_val) == (m.m_val >= mod ? m.m_val - mod : m.m_val);\
    \ }\n    constexpr bool operator!=(const moddint& m) const { return not(*this\
    \ == m); }\n    friend std::istream& operator>>(std::istream& is, moddint& m)\n\
    \    {\n        i64 v;\n        return is >> v, m = v, is;\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const moddint& m) { return os <<\
    \ m(); }\n    constexpr u32 get() const\n    {\n        const u32 m = info.reduce(m_val);\n\
    \        return m >= mod ? m - mod : m;\n    }\n    constexpr u32 operator()()\
    \ const { return get(); }\n    constexpr moddint pow(u64 n) const\n    {\n   \
    \     moddint ans = 1;\n        for (moddint x = *this; n > 0; n >>= 1, x *= x)\
    \ {\n            if (n & 1) { ans *= x; }\n        }\n        return ans;\n  \
    \  }\n    constexpr moddint inv() const { return pow(mod - 2); }\n\nprivate:\n\
    \    u32 m_val;\n};\n"
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
  path: src/math/moddint.hpp
  requiredBy: []
  timestamp: '2021-05-22 16:44:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/moddint.hpp
layout: document
redirect_from:
- /library/src/math/moddint.hpp
- /library/src/math/moddint.hpp.html
title: src/math/moddint.hpp
---
