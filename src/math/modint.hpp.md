---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/misc/common.hpp
    title: src/misc/common.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/bit_ops.hpp
    title: src/misc/common/bit_ops.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/constants.hpp
    title: src/misc/common/constants.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/fixpoint.hpp
    title: src/misc/common/fixpoint.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/func_alias.hpp
    title: src/misc/common/func_alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/macros.hpp
    title: src/misc/common/macros.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/nd_vec.hpp
    title: src/misc/common/nd_vec.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/range.hpp
    title: src/misc/common/range.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/rng.hpp
    title: src/misc/common/rng.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/show.hpp
    title: src/misc/common/show.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/xoshiro.hpp
    title: src/misc/common/xoshiro.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/fft.hpp
    title: src/math/fft.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/fps.hpp
    title: src/math/fps.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/fps_div_nth.hpp
    title: src/math/fps_div_nth.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/is_prime.hpp
    title: src/math/is_prime.hpp
  - icon: ':warning:'
    path: src/math/lagrange_interpolation.hpp
    title: src/math/lagrange_interpolation.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/mod_nthroot.hpp
    title: src/math/mod_nthroot.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/nth_term.hpp
    title: src/math/nth_term.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/prime_factors.hpp
    title: src/math/prime_factors.hpp
  - icon: ':warning:'
    path: src/math/primitive_root.hpp
    title: src/math/primitive_root.hpp
  - icon: ':warning:'
    path: verifications/math/mod_nthroot.yuki981.cpp
    title: verifications/math/mod_nthroot.yuki981.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifications/data_structure/lazyseg.test.cpp
    title: verifications/data_structure/lazyseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/data_structure/segtree.test.cpp
    title: verifications/data_structure/segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/data_structure/swag.test.cpp
    title: verifications/data_structure/swag.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/graph/hld.test.cpp
    title: verifications/graph/hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/and_convolution.test.cpp
    title: verifications/math/and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/berlekamp_massey.test.cpp
    title: verifications/math/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/fps.convolution.test.cpp
    title: verifications/math/fps.convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/fps.convolution1000000007.test.cpp
    title: verifications/math/fps.convolution1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/fps.div_nth.test.cpp
    title: verifications/math/fps.div_nth.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/fps.exp.test.cpp
    title: verifications/math/fps.exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/fps.inv.test.cpp
    title: verifications/math/fps.inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/fps.log.test.cpp
    title: verifications/math/fps.log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/fps.nth.test.cpp
    title: verifications/math/fps.nth.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/fps.pow.test.cpp
    title: verifications/math/fps.pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/fps.tshift.test.cpp
    title: verifications/math/fps.tshift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/gcd_convolution.test.cpp
    title: verifications/math/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/mod_nthroot.test.cpp
    title: verifications/math/mod_nthroot.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/mod_sqrt.test.cpp
    title: verifications/math/mod_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/multiplicative_sum.test.cpp
    title: verifications/math/multiplicative_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/prime_factors.test.cpp
    title: verifications/math/prime_factors.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/math/xor_convolution.test.cpp
    title: verifications/math/xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\n#include <iostream>\n#pragma region Macros\n\
    #pragma endregion\n#pragma region TypeAlias\nusing i32 = int;\nusing u32 = unsigned\
    \ int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\nusing f64 = double;\nusing f80 = long\
    \ double;\nusing f128 = __float128;\nconstexpr i32 operator\"\" _i32(u64 v)\n\
    {\n    return v;\n}\nconstexpr i32 operator\"\" _u32(u64 v)\n{\n    return v;\n\
    }\nconstexpr i64 operator\"\" _i64(u64 v)\n{\n    return v;\n}\nconstexpr u64\
    \ operator\"\" _u64(u64 v)\n{\n    return v;\n}\nconstexpr f64 operator\"\" _f64(f80\
    \ v)\n{\n    return v;\n}\nconstexpr f80 operator\"\" _f80(f80 v)\n{\n    return\
    \ v;\n}\nusing Istream = std::istream;\nusing Ostream = std::ostream;\nusing Str\
    \ = std::string;\ntemplate<typename T>\nusing Lt = std::less<T>;\ntemplate<typename\
    \ T>\nusing Gt = std::greater<T>;\ntemplate<typename T>\nusing IList = std::initializer_list<T>;\n\
    template<int n>\nusing BSet = std::bitset<n>;\ntemplate<typename T1, typename\
    \ T2>\nusing Pair = std::pair<T1, T2>;\ntemplate<typename... Ts>\nusing Tup =\
    \ std::tuple<Ts...>;\ntemplate<typename T, int N>\nusing Arr = std::array<T, N>;\n\
    template<typename... Ts>\nusing Deq = std::deque<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing Set = std::set<Ts...>;\ntemplate<typename... Ts>\nusing MSet = std::multiset<Ts...>;\n\
    template<typename... Ts>\nusing USet = std::unordered_set<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing UMSet = std::unordered_multiset<Ts...>;\ntemplate<typename... Ts>\n\
    using Map = std::map<Ts...>;\ntemplate<typename... Ts>\nusing MMap = std::multimap<Ts...>;\n\
    template<typename... Ts>\nusing UMap = std::unordered_map<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing UMMap = std::unordered_multimap<Ts...>;\ntemplate<typename... Ts>\n\
    using Vec = std::vector<Ts...>;\ntemplate<typename... Ts>\nusing Stack = std::stack<Ts...>;\n\
    template<typename... Ts>\nusing Queue = std::queue<Ts...>;\ntemplate<typename\
    \ T>\nusing MaxHeap = std::priority_queue<T>;\ntemplate<typename T>\nusing MinHeap\
    \ = std::priority_queue<T, Vec<T>, Gt<T>>;\n#pragma endregion\n#pragma region\
    \ Constants\ntemplate<typename T>\nconstexpr T INF = std::numeric_limits<T>::max()\
    \ / 4;\ntemplate<typename T>\nconstexpr T PI = T{3.141592653589793238462643383279502884};\n\
    template<typename T = u64>\nconstexpr T TEN(const int n)\n{\n    return n == 0\
    \ ? T{1} : TEN<T>(n - 1) * T{10};\n}\n#pragma endregion\n#pragma region FuncAlias\n\
    template<typename T>\nbool chmin(T& a, const T& b)\n{\n    if (a > b) {\n    \
    \    a = b;\n        return true;\n    } else {\n        return false;\n    }\n\
    }\ntemplate<typename T>\nbool chmax(T& a, const T& b)\n{\n    if (a < b) {\n \
    \       a = b;\n        return true;\n    } else {\n        return false;\n  \
    \  }\n}\ntemplate<typename T>\nconstexpr T fdiv(T x, T y)\n{\n    if (y < T{})\
    \ { x = -x, y = -y; }\n    return x >= T{} ? x / y : (x - y + 1) / y;\n}\ntemplate<typename\
    \ T>\nconstexpr T cdiv(T x, T y)\n{\n    if (y < T{}) { x = -x, y = -y; }\n  \
    \  return x >= T{} ? (x + y - 1) / y : x / y;\n}\ntemplate<typename T, typename\
    \ I>\nconstexpr T modPower(T v, I n, T mod)\n{\n    T ans = 1 % mod;\n    for\
    \ (; n > 0; n >>= 1, (v *= v) %= mod) {\n        if (n % 2 == 1) { (ans *= v)\
    \ %= mod; }\n    }\n    return ans;\n}\ntemplate<typename T, typename I>\nconstexpr\
    \ T power(T v, I n)\n{\n    T ans = 1;\n    for (; n > 0; n >>= 1, v *= v) {\n\
    \        if (n % 2 == 1) { ans *= v; }\n    }\n    return ans;\n}\ntemplate<typename\
    \ T, typename I>\nconstexpr T power(T v, I n, const T& e)\n{\n    T ans = e;\n\
    \    for (; n > 0; n >>= 1, v *= v) {\n        if (n % 2 == 1) { ans *= v; }\n\
    \    }\n    return ans;\n}\ntemplate<typename T>\nvoid fillAll(Vec<T>& vs, const\
    \ T& v)\n{\n    std::fill(vs.begin(), vs.end(), v);\n}\ntemplate<typename T, typename\
    \ C = Lt<T>>\nvoid sortAll(Vec<T>& vs, C comp = C{})\n{\n    std::sort(vs.begin(),\
    \ vs.end(), comp);\n}\ntemplate<typename T>\nvoid reverseAll(Vec<T>& vs)\n{\n\
    \    std::reverse(vs.begin(), vs.end());\n}\ntemplate<typename T>\nvoid uniqueAll(Vec<T>&\
    \ vs)\n{\n    sortAll(vs);\n    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());\n\
    }\ntemplate<typename T>\nvoid iotaAll(Vec<T>& vs, T offset = T{})\n{\n    std::iota(vs.begin(),\
    \ vs.end(), offset);\n}\ntemplate<typename T, typename V = T>\nV sumAll(const\
    \ Vec<T>& vs)\n{\n    return std::accumulate(vs.begin(), vs.end(), V{});\n}\n\
    template<typename T>\nint minInd(const Vec<T>& vs)\n{\n    return std::min_element(vs.begin(),\
    \ vs.end()) - vs.begin();\n}\ntemplate<typename T>\nint maxInd(const Vec<T>& vs)\n\
    {\n    return std::max_element(vs.begin(), vs.end()) - vs.begin();\n}\ntemplate<typename\
    \ T>\nint lbInd(const Vec<T>& vs, const T& v)\n{\n    return std::lower_bound(vs.begin(),\
    \ vs.end(), v) - vs.begin();\n}\ntemplate<typename T>\nint ubInd(const Vec<T>&\
    \ vs, const T& v)\n{\n    return std::lower_bound(vs.begin(), vs.end(), v) - vs.begin();\n\
    }\ntemplate<typename Vs, typename F>\nvoid eraseIf(Vs& vs, F f)\n{\n    vs.erase(std::remove_if(vs.begin(),\
    \ vs.end(), f), vs.end());\n}\ntemplate<typename T, typename F>\nVec<T> genVec(int\
    \ n, F gen)\n{\n    Vec<T> ans;\n    std::generate_n(std::back_insert_iterator(ans),\
    \ n, gen);\n    return ans;\n}\nVec<int> iotaVec(int n, int offset = 0)\n{\n \
    \   Vec<int> ans(n);\n    iotaAll(ans, offset);\n    return ans;\n}\ntemplate<typename\
    \ T, typename F = Lt<T>>\nVec<int> iotaVec(const Vec<T>& vs, F comp = F{})\n{\n\
    \    auto is = iotaVec(vs.size(), 0);\n    sortAll(is, [&](int i, int j) { return\
    \ comp(vs[i], vs[j]); });\n    return is;\n}\ntemplate<typename T>\nVec<T> operator+=(Vec<T>&\
    \ vs1, const Vec<T>& vs2)\n{\n    vs1.insert(vs1.end(), vs2.begin(), vs2.end());\n\
    \    return vs1;\n}\ntemplate<typename T>\nVec<T> operator+(const Vec<T>& vs1,\
    \ const Vec<T>& vs2)\n{\n    return Vec<T>{vs1} += vs2;\n}\n#pragma endregion\n\
    #pragma region Show\nOstream& operator<<(Ostream& os, i128 v)\n{\n    bool minus\
    \ = false;\n    if (v < 0) { minus = true, v = -v; }\n    Str ans;\n    if (v\
    \ == 0) { ans = \"0\"; }\n    while (v) {\n        ans.push_back('0' + v % 10),\
    \ v /= 10;\n    }\n    std::reverse(ans.begin(), ans.end());\n    return os <<\
    \ (minus ? \"-\" : \"\") << ans;\n}\nOstream& operator<<(Ostream& os, u128 v)\n\
    {\n    Str ans;\n    if (v == 0) { ans = \"0\"; }\n    while (v) {\n        ans.push_back('0'\
    \ + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(), ans.end());\n    return\
    \ os << ans;\n}\n#pragma endregion\n#pragma region BitOps\nconstexpr int popcount(const\
    \ u64 v)\n{\n    return v ? __builtin_popcountll(v) : 0;\n}\nconstexpr int log2p1(const\
    \ u64 v)\n{\n    return v ? 64 - __builtin_clzll(v) : 0;\n}\nconstexpr int lsbp1(const\
    \ u64 v)\n{\n    return __builtin_ffsll(v);\n}\nconstexpr int clog(const u64 v)\n\
    {\n    return v ? log2p1(v - 1) : 0;\n}\nconstexpr u64 ceil2(const u64 v)\n{\n\
    \    return 1_u64 << clog(v);\n}\nconstexpr u64 floor2(const u64 v)\n{\n    return\
    \ v ? (1_u64 << (log2p1(v) - 1)) : 0_u64;\n}\nconstexpr bool ispow2(const u64\
    \ v)\n{\n    return (v & (v - 1)) == 0;\n}\nconstexpr bool btest(const u64 mask,\
    \ const int ind)\n{\n    return (mask >> ind) & 1_u64;\n}\n#pragma endregion\n\
    #pragma region FixPoint\ntemplate<typename F>\nstruct Fixpoint : F\n{\n    Fixpoint(F&&\
    \ f) : F{std::forward<F>(f)} {}\n    template<typename... Args>\n    auto operator()(Args&&...\
    \ args) const\n    {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n#pragma endregion\n#pragma region NdVec\ntemplate<typename T, int\
    \ n, int i = 0>\nauto ndVec(int const (&szs)[n], const T x = T{})\n{\n    if constexpr\
    \ (i == n) {\n        return x;\n    } else {\n        return std::vector(szs[i],\
    \ ndVec<T, n, i + 1>(szs, x));\n    }\n}\n#pragma endregion\n#pragma region Range\n\
    class range\n{\nprivate:\n    struct itr\n    {\n        itr(int start = 0, int\
    \ step = 1) : m_cnt{start}, m_step{step} {}\n        bool operator!=(const itr&\
    \ it) const\n        {\n            return m_cnt != it.m_cnt;\n        }\n   \
    \     int operator*()\n        {\n            return m_cnt;\n        }\n     \
    \   itr& operator++()\n        {\n            m_cnt += m_step;\n            return\
    \ *this;\n        }\n        int m_cnt, m_step;\n    };\n    int m_start, m_end,\
    \ m_step;\npublic:\n    range(int start, int end, int step = 1)\n        : m_start{start},\
    \ m_end{end}, m_step{step}\n    {\n        assert(m_step == 1 or m_step == -1);\n\
    \    }\n    itr begin() const\n    {\n        return itr{m_start, m_step};\n \
    \   }\n    itr end() const\n    {\n        return itr{m_end, m_step};\n    }\n\
    };\nrange rep(int end)\n{\n    return range(0, end, 1);\n}\nrange per(int rend)\n\
    {\n    return range(rend - 1, -1, -1);\n}\nclass ndRep\n{\nprivate:\n    struct\
    \ itr\n    {\n        itr(const Vec<int>& ns) : m_ns{ns}, m_cs(ns.size(), 0),\
    \ m_end{false} {}\n        bool operator!=(const itr&) const\n        {\n    \
    \        return not m_end;\n        }\n        const Vec<int>& operator*()\n \
    \       {\n            return m_cs;\n        }\n        itr& operator++()\n  \
    \      {\n            for (const int i : per(m_ns.size())) {\n               \
    \ m_cs[i]++;\n                if (m_cs[i] < m_ns[i]) {\n                    break;\n\
    \                } else {\n                    if (i == 0) { m_end = true; }\n\
    \                    m_cs[i] = 0;\n                }\n            }\n        \
    \    return *this;\n        }\n        Vec<int> m_ns, m_cs;\n        bool m_end;\n\
    \    };\n    Vec<int> m_ns;\npublic:\n    ndRep(const Vec<int>& ns) : m_ns{ns}\
    \ {}\n    itr begin() const\n    {\n        return itr{m_ns};\n    }\n    itr\
    \ end() const\n    {\n        return itr{m_ns};\n    }\n};\n#pragma endregion\n\
    #pragma COMMENT(\"[REFS] Xoshiro: https://prng.di.unimi.it\")\n#pragma region\
    \ Xoshiro\nnamespace xoshiro_impl {\nu64 x;\nu64 next()\n{\n    uint64_t z = (x\
    \ += 0x9e3779b97f4a7c15);\n    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n   \
    \ z = (z ^ (z >> 27)) * 0x94d049bb133111eb;\n    return z ^ (z >> 31);\n}\n}\n\
    class Xoshiro32\n{\npublic:\n    using result_type = u32;\n    using T = result_type;\n\
    \    Xoshiro32(T seed = 0)\n    {\n        xoshiro_impl::x = seed;\n        s[0]\
    \ = xoshiro_impl::next();\n        s[1] = xoshiro_impl::next();\n        s[2]\
    \ = xoshiro_impl::next();\n        s[3] = xoshiro_impl::next();\n    }\n    static\
    \ constexpr T min()\n    {\n        return std::numeric_limits<T>::min();\n  \
    \  }\n    static constexpr T max()\n    {\n        return std::numeric_limits<T>::max();\n\
    \    }\n    T operator()()\n    {\n        return next();\n    }\nprivate:\n \
    \   static constexpr T rotl(const T x, int k)\n    {\n        return (x << k)\
    \ | (x >> (32 - k));\n    }\n    T next()\n    {\n        const T ans = rotl(s[1]\
    \ * 5, 7) * 9;\n        const T t = s[1] << 9;\n        s[2] ^= s[0];\n      \
    \  s[3] ^= s[1];\n        s[1] ^= s[2];\n        s[0] ^= s[3];\n        s[2] ^=\
    \ t;\n        s[3] = rotl(s[3], 11);\n        return ans;\n    }\n    T s[4];\n\
    };\nclass Xoshiro64\n{\npublic:\n    using result_type = u64;\n    using T = result_type;\n\
    \    Xoshiro64(T seed = 0)\n    {\n        xoshiro_impl::x = seed;\n        s[0]\
    \ = xoshiro_impl::next();\n        s[1] = xoshiro_impl::next();\n        s[2]\
    \ = xoshiro_impl::next();\n        s[3] = xoshiro_impl::next();\n    }\n    static\
    \ constexpr T min()\n    {\n        return std::numeric_limits<T>::min();\n  \
    \  }\n    static constexpr T max()\n    {\n        return std::numeric_limits<T>::max();\n\
    \    }\n    T operator()()\n    {\n        return next();\n    }\nprivate:\n \
    \   static constexpr T rotl(const T x, int k)\n    {\n        return (x << k)\
    \ | (x >> (64 - k));\n    }\n    T next()\n    {\n        const T ans = rotl(s[1]\
    \ * 5, 7) * 9;\n        const T t = s[1] << 17;\n        s[2] ^= s[0];\n     \
    \   s[3] ^= s[1];\n        s[1] ^= s[2];\n        s[0] ^= s[3];\n        s[2]\
    \ ^= t;\n        s[3] = rotl(s[3], 45);\n        return ans;\n    }\n    T s[4];\n\
    };\n#pragma endregion\n#pragma region RNG\ntemplate<typename Rng>\nclass RNG\n\
    {\npublic:\n    using result_type = typename Rng::result_type;\n    using T =\
    \ result_type;\n    static constexpr T min()\n    {\n        return Rng::min();\n\
    \    }\n    static constexpr T max()\n    {\n        return Rng::max();\n    }\n\
    \    RNG() : RNG(std::random_device{}()) {}\n    RNG(T seed) : m_rng(seed) {}\n\
    \    T operator()()\n    {\n        return m_rng();\n    }\n    template<typename\
    \ T>\n    T val(T min, T max)\n    {\n        return std::uniform_int_distribution<T>(min,\
    \ max)(m_rng);\n    }\n    template<typename T>\n    Pair<T, T> pair(T min, T\
    \ max)\n    {\n        return std::minmax({val<T>(min, max), val<T>(min, max)});\n\
    \    }\n    template<typename T>\n    Vec<T> vec(int n, T min, T max)\n    {\n\
    \        return genVec<T>(n, [&]() { return val<T>(min, max); });\n    }\n   \
    \ template<typename T>\n    Vec<Vec<T>> vvec(int n, int m, T min, T max)\n   \
    \ {\n        return genVec<Vec<T>>(n, [&]() { return vec(m, min, max); });\n \
    \   }\nprivate:\n    Rng m_rng;\n};\nRNG<std::mt19937> rng;\nRNG<std::mt19937_64>\
    \ rng64;\nRNG<Xoshiro32> rng_xo;\nRNG<Xoshiro64> rng_xo64;\n#pragma endregion\n\
    template<u32 mod_, u32 root_, u32 max2p_>\nclass modint\n{\n    template<typename\
    \ U = u32&>\n    static U modRef()\n    {\n        static u32 s_mod = 0;\n   \
    \     return s_mod;\n    }\n    template<typename U = u32&>\n    static U rootRef()\n\
    \    {\n        static u32 s_root = 0;\n        return s_root;\n    }\n    template<typename\
    \ U = u32&>\n    static U max2pRef()\n    {\n        static u32 s_max2p = 0;\n\
    \        return s_max2p;\n    }\npublic:\n    template<typename U = const u32>\n\
    \    static constexpr std::enable_if_t<mod_ != 0, U> mod()\n    {\n        return\
    \ mod_;\n    }\n    template<typename U = const u32>\n    static std::enable_if_t<mod_\
    \ == 0, U> mod()\n    {\n        return modRef();\n    }\n    template<typename\
    \ U = const u32>\n    static constexpr std::enable_if_t<mod_ != 0, U> root()\n\
    \    {\n        return root_;\n    }\n    template<typename U = const u32>\n \
    \   static std::enable_if_t<mod_ == 0, U> root()\n    {\n        return rootRef();\n\
    \    }\n    template<typename U = const u32>\n    static constexpr std::enable_if_t<mod_\
    \ != 0, U> max2p()\n    {\n        return max2p_;\n    }\n    template<typename\
    \ U = const u32>\n    static std::enable_if_t<mod_ == 0, U> max2p()\n    {\n \
    \       return max2pRef();\n    }\n    template<typename U = u32>\n    static\
    \ void setMod(std::enable_if_t<mod_ == 0, U> m)\n    {\n        modRef() = m;\n\
    \    }\n    template<typename U = u32>\n    static void setRoot(std::enable_if_t<mod_\
    \ == 0, U> r)\n    {\n        rootRef() = r;\n    }\n    template<typename U =\
    \ u32>\n    static void setMax2p(std::enable_if_t<mod_ == 0, U> m)\n    {\n  \
    \      max2pRef() = m;\n    }\n    constexpr modint() : m_val{0} {}\n    constexpr\
    \ modint(i64 v) : m_val{normll(v)} {}\n    constexpr void setRaw(u32 v)\n    {\n\
    \        m_val = v;\n    }\n    constexpr modint operator-() const\n    {\n  \
    \      return modint{0} - (*this);\n    }\n    constexpr modint& operator+=(const\
    \ modint& m)\n    {\n        m_val = norm(m_val + m.val());\n        return *this;\n\
    \    }\n    constexpr modint& operator-=(const modint& m)\n    {\n        m_val\
    \ = norm(m_val + mod() - m.val());\n        return *this;\n    }\n    constexpr\
    \ modint& operator*=(const modint& m)\n    {\n        m_val = normll((i64)m_val\
    \ * (i64)m.val() % (i64)mod());\n        return *this;\n    }\n    constexpr modint&\
    \ operator/=(const modint& m)\n    {\n        return *this *= m.inv();\n    }\n\
    \    constexpr modint operator+(const modint& m) const\n    {\n        return\
    \ modint{*this} += m;\n    }\n    constexpr modint operator-(const modint& m)\
    \ const\n    {\n        return modint{*this} -= m;\n    }\n    constexpr modint\
    \ operator*(const modint& m) const\n    {\n        return modint{*this} *= m;\n\
    \    }\n    constexpr modint operator/(const modint& m) const\n    {\n       \
    \ return modint{*this} /= m;\n    }\n    constexpr bool operator==(const modint&\
    \ m) const\n    {\n        return m_val == m.val();\n    }\n    constexpr bool\
    \ operator!=(const modint& m) const\n    {\n        return not(*this == m);\n\
    \    }\n    friend Istream& operator>>(Istream& is, modint& m)\n    {\n      \
    \  i64 v;\n        return is >> v, m = v, is;\n    }\n    friend Ostream& operator<<(Ostream&\
    \ os, const modint& m)\n    {\n        return os << m.val();\n    }\n    constexpr\
    \ u32 val() const\n    {\n        return m_val;\n    }\n    template<typename\
    \ I>\n    constexpr modint pow(I n) const\n    {\n        return power(*this,\
    \ n);\n    }\n    constexpr modint inv() const\n    {\n        return pow(mod()\
    \ - 2);\n    }\n    static modint sinv(u32 n)\n    {\n        static Vec<modint>\
    \ is{1, 1};\n        for (u32 i = (u32)is.size(); i <= n; i++) {\n           \
    \ is.push_back(-is[mod() % i] * (mod() / i));\n        }\n        return is[n];\n\
    \    }\n    static modint fact(u32 n)\n    {\n        static Vec<modint> fs{1,\
    \ 1};\n        for (u32 i = (u32)fs.size(); i <= n; i++) {\n            fs.push_back(fs.back()\
    \ * i);\n        }\n        return fs[n];\n    }\n    static modint ifact(u32\
    \ n)\n    {\n        static Vec<modint> ifs{1, 1};\n        for (u32 i = (u32)ifs.size();\
    \ i <= n; i++) {\n            ifs.push_back(ifs.back() * sinv(i));\n        }\n\
    \        return ifs[n];\n    }\n    static modint comb(int n, int k)\n    {\n\
    \        return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k) * ifact(k);\n\
    \    }\nprivate:\n    static constexpr u32 norm(u32 x)\n    {\n        return\
    \ x < mod() ? x : x - mod();\n    }\n    static constexpr u32 normll(i64 x)\n\
    \    {\n        return norm(u32(x % (i64)mod() + (i64)mod()));\n    }\n    u32\
    \ m_val;\n};\nusing modint_1000000007 = modint<1000000007, 5, 1>;\nusing modint_998244353\
    \ = modint<998244353, 3, 23>;\ntemplate<int id>\nusing modint_dynamic = modint<0,\
    \ 0, id>;\n"
  code: "#pragma once\n#include <iostream>\n\n#include \"../misc/common.hpp\"\ntemplate<u32\
    \ mod_, u32 root_, u32 max2p_>\nclass modint\n{\n    template<typename U = u32&>\n\
    \    static U modRef()\n    {\n        static u32 s_mod = 0;\n        return s_mod;\n\
    \    }\n    template<typename U = u32&>\n    static U rootRef()\n    {\n     \
    \   static u32 s_root = 0;\n        return s_root;\n    }\n    template<typename\
    \ U = u32&>\n    static U max2pRef()\n    {\n        static u32 s_max2p = 0;\n\
    \        return s_max2p;\n    }\n\npublic:\n    template<typename U = const u32>\n\
    \    static constexpr std::enable_if_t<mod_ != 0, U> mod()\n    {\n        return\
    \ mod_;\n    }\n    template<typename U = const u32>\n    static std::enable_if_t<mod_\
    \ == 0, U> mod()\n    {\n        return modRef();\n    }\n    template<typename\
    \ U = const u32>\n    static constexpr std::enable_if_t<mod_ != 0, U> root()\n\
    \    {\n        return root_;\n    }\n    template<typename U = const u32>\n \
    \   static std::enable_if_t<mod_ == 0, U> root()\n    {\n        return rootRef();\n\
    \    }\n    template<typename U = const u32>\n    static constexpr std::enable_if_t<mod_\
    \ != 0, U> max2p()\n    {\n        return max2p_;\n    }\n    template<typename\
    \ U = const u32>\n    static std::enable_if_t<mod_ == 0, U> max2p()\n    {\n \
    \       return max2pRef();\n    }\n    template<typename U = u32>\n    static\
    \ void setMod(std::enable_if_t<mod_ == 0, U> m)\n    {\n        modRef() = m;\n\
    \    }\n    template<typename U = u32>\n    static void setRoot(std::enable_if_t<mod_\
    \ == 0, U> r)\n    {\n        rootRef() = r;\n    }\n    template<typename U =\
    \ u32>\n    static void setMax2p(std::enable_if_t<mod_ == 0, U> m)\n    {\n  \
    \      max2pRef() = m;\n    }\n\n    constexpr modint() : m_val{0} {}\n    constexpr\
    \ modint(i64 v) : m_val{normll(v)} {}\n    constexpr void setRaw(u32 v)\n    {\n\
    \        m_val = v;\n    }\n    constexpr modint operator-() const\n    {\n  \
    \      return modint{0} - (*this);\n    }\n    constexpr modint& operator+=(const\
    \ modint& m)\n    {\n        m_val = norm(m_val + m.val());\n        return *this;\n\
    \    }\n    constexpr modint& operator-=(const modint& m)\n    {\n        m_val\
    \ = norm(m_val + mod() - m.val());\n        return *this;\n    }\n    constexpr\
    \ modint& operator*=(const modint& m)\n    {\n        m_val = normll((i64)m_val\
    \ * (i64)m.val() % (i64)mod());\n        return *this;\n    }\n    constexpr modint&\
    \ operator/=(const modint& m)\n    {\n        return *this *= m.inv();\n    }\n\
    \    constexpr modint operator+(const modint& m) const\n    {\n        return\
    \ modint{*this} += m;\n    }\n    constexpr modint operator-(const modint& m)\
    \ const\n    {\n        return modint{*this} -= m;\n    }\n    constexpr modint\
    \ operator*(const modint& m) const\n    {\n        return modint{*this} *= m;\n\
    \    }\n    constexpr modint operator/(const modint& m) const\n    {\n       \
    \ return modint{*this} /= m;\n    }\n    constexpr bool operator==(const modint&\
    \ m) const\n    {\n        return m_val == m.val();\n    }\n    constexpr bool\
    \ operator!=(const modint& m) const\n    {\n        return not(*this == m);\n\
    \    }\n    friend Istream& operator>>(Istream& is, modint& m)\n    {\n      \
    \  i64 v;\n        return is >> v, m = v, is;\n    }\n    friend Ostream& operator<<(Ostream&\
    \ os, const modint& m)\n    {\n        return os << m.val();\n    }\n    constexpr\
    \ u32 val() const\n    {\n        return m_val;\n    }\n    template<typename\
    \ I>\n    constexpr modint pow(I n) const\n    {\n        return power(*this,\
    \ n);\n    }\n    constexpr modint inv() const\n    {\n        return pow(mod()\
    \ - 2);\n    }\n    static modint sinv(u32 n)\n    {\n        static Vec<modint>\
    \ is{1, 1};\n        for (u32 i = (u32)is.size(); i <= n; i++) {\n           \
    \ is.push_back(-is[mod() % i] * (mod() / i));\n        }\n        return is[n];\n\
    \    }\n    static modint fact(u32 n)\n    {\n        static Vec<modint> fs{1,\
    \ 1};\n        for (u32 i = (u32)fs.size(); i <= n; i++) {\n            fs.push_back(fs.back()\
    \ * i);\n        }\n        return fs[n];\n    }\n    static modint ifact(u32\
    \ n)\n    {\n        static Vec<modint> ifs{1, 1};\n        for (u32 i = (u32)ifs.size();\
    \ i <= n; i++) {\n            ifs.push_back(ifs.back() * sinv(i));\n        }\n\
    \        return ifs[n];\n    }\n    static modint comb(int n, int k)\n    {\n\
    \        return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k) * ifact(k);\n\
    \    }\n\nprivate:\n    static constexpr u32 norm(u32 x)\n    {\n        return\
    \ x < mod() ? x : x - mod();\n    }\n    static constexpr u32 normll(i64 x)\n\
    \    {\n        return norm(u32(x % (i64)mod() + (i64)mod()));\n    }\n    u32\
    \ m_val;\n};\nusing modint_1000000007 = modint<1000000007, 5, 1>;\nusing modint_998244353\
    \ = modint<998244353, 3, 23>;\ntemplate<int id>\nusing modint_dynamic = modint<0,\
    \ 0, id>;\n"
  dependsOn:
  - src/misc/common.hpp
  - src/misc/common/macros.hpp
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
  path: src/math/modint.hpp
  requiredBy:
  - src/math/nth_term.hpp
  - src/math/lagrange_interpolation.hpp
  - src/math/primitive_root.hpp
  - src/math/is_prime.hpp
  - src/math/prime_factors.hpp
  - src/math/fps.hpp
  - src/math/fps_div_nth.hpp
  - src/math/fft.hpp
  - src/math/mod_nthroot.hpp
  - verifications/math/mod_nthroot.yuki981.cpp
  timestamp: '2021-05-23 19:52:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifications/math/fps.exp.test.cpp
  - verifications/math/fps.inv.test.cpp
  - verifications/math/fps.convolution1000000007.test.cpp
  - verifications/math/prime_factors.test.cpp
  - verifications/math/fps.div_nth.test.cpp
  - verifications/math/multiplicative_sum.test.cpp
  - verifications/math/and_convolution.test.cpp
  - verifications/math/gcd_convolution.test.cpp
  - verifications/math/mod_sqrt.test.cpp
  - verifications/math/mod_nthroot.test.cpp
  - verifications/math/fps.tshift.test.cpp
  - verifications/math/fps.log.test.cpp
  - verifications/math/berlekamp_massey.test.cpp
  - verifications/math/xor_convolution.test.cpp
  - verifications/math/fps.convolution.test.cpp
  - verifications/math/fps.pow.test.cpp
  - verifications/math/fps.nth.test.cpp
  - verifications/data_structure/swag.test.cpp
  - verifications/data_structure/lazyseg.test.cpp
  - verifications/data_structure/segtree.test.cpp
  - verifications/graph/hld.test.cpp
documentation_of: src/math/modint.hpp
layout: document
redirect_from:
- /library/src/math/modint.hpp
- /library/src/math/modint.hpp.html
title: src/math/modint.hpp
---
