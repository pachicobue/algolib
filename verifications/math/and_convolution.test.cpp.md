---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/and_convolution.hpp
    title: src/math/and_convolution.hpp
  - icon: ':question:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/set_moebius.hpp
    title: src/math/set_moebius.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/set_zeta.hpp
    title: src/math/set_zeta.hpp
  - icon: ':question:'
    path: src/misc/common.hpp
    title: src/misc/common.hpp
  - icon: ':question:'
    path: src/misc/common/bit_ops.hpp
    title: src/misc/common/bit_ops.hpp
  - icon: ':question:'
    path: src/misc/common/constants.hpp
    title: src/misc/common/constants.hpp
  - icon: ':question:'
    path: src/misc/common/fixpoint.hpp
    title: src/misc/common/fixpoint.hpp
  - icon: ':question:'
    path: src/misc/common/func_alias.hpp
    title: src/misc/common/func_alias.hpp
  - icon: ':question:'
    path: src/misc/common/irange.hpp
    title: src/misc/common/irange.hpp
  - icon: ':question:'
    path: src/misc/common/macros.hpp
    title: src/misc/common/macros.hpp
  - icon: ':question:'
    path: src/misc/common/operator_alias.hpp
    title: src/misc/common/operator_alias.hpp
  - icon: ':question:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
  - icon: ':question:'
    path: src/misc/common/rng.hpp
    title: src/misc/common/rng.hpp
  - icon: ':question:'
    path: src/misc/common/show.hpp
    title: src/misc/common/show.hpp
  - icon: ':question:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  - icon: ':question:'
    path: src/misc/common/vec_utils.hpp
    title: src/misc/common/vec_utils.hpp
  - icon: ':question:'
    path: src/misc/common/xoshiro.hpp
    title: src/misc/common/xoshiro.hpp
  - icon: ':question:'
    path: src/misc/fastio/printer.hpp
    title: src/misc/fastio/printer.hpp
  - icon: ':question:'
    path: src/misc/fastio/scanner.hpp
    title: src/misc/fastio/scanner.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#include <bits/stdc++.h>\nusing i32 = int;\nusing u32 = unsigned int;\n\
    using i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing f64 = double;\nusing f80 = long double;\nusing\
    \ f128 = __float128;\nconstexpr i32 operator\"\" _i32(u64 v)\n{\n    return v;\n\
    }\nconstexpr i32 operator\"\" _u32(u64 v)\n{\n    return v;\n}\nconstexpr i64\
    \ operator\"\" _i64(u64 v)\n{\n    return v;\n}\nconstexpr u64 operator\"\" _u64(u64\
    \ v)\n{\n    return v;\n}\nconstexpr f64 operator\"\" _f64(f80 v)\n{\n    return\
    \ v;\n}\nconstexpr f80 operator\"\" _f80(f80 v)\n{\n    return v;\n}\nusing Istream\
    \ = std::istream;\nusing Ostream = std::ostream;\nusing Str = std::string;\ntemplate<typename\
    \ T>\nusing Lt = std::less<T>;\ntemplate<typename T>\nusing Gt = std::greater<T>;\n\
    template<typename T>\nusing IList = std::initializer_list<T>;\ntemplate<int n>\n\
    using BSet = std::bitset<n>;\ntemplate<typename T1, typename T2>\nusing Pair =\
    \ std::pair<T1, T2>;\ntemplate<typename... Ts>\nusing Tup = std::tuple<Ts...>;\n\
    template<typename T, int N>\nusing Arr = std::array<T, N>;\ntemplate<typename...\
    \ Ts>\nusing Deq = std::deque<Ts...>;\ntemplate<typename... Ts>\nusing Set = std::set<Ts...>;\n\
    template<typename... Ts>\nusing MSet = std::multiset<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing USet = std::unordered_set<Ts...>;\ntemplate<typename... Ts>\nusing\
    \ UMSet = std::unordered_multiset<Ts...>;\ntemplate<typename... Ts>\nusing Map\
    \ = std::map<Ts...>;\ntemplate<typename... Ts>\nusing MMap = std::multimap<Ts...>;\n\
    template<typename... Ts>\nusing UMap = std::unordered_map<Ts...>;\ntemplate<typename...\
    \ Ts>\nusing UMMap = std::unordered_multimap<Ts...>;\ntemplate<typename... Ts>\n\
    using Vec = std::vector<Ts...>;\ntemplate<typename... Ts>\nusing Stack = std::stack<Ts...>;\n\
    template<typename... Ts>\nusing Queue = std::queue<Ts...>;\ntemplate<typename\
    \ T>\nusing MaxHeap = std::priority_queue<T>;\ntemplate<typename T>\nusing MinHeap\
    \ = std::priority_queue<T, Vec<T>, Gt<T>>;\nusing NSec = std::chrono::nanoseconds;\n\
    using USec = std::chrono::microseconds;\nusing MSec = std::chrono::milliseconds;\n\
    using Sec = std::chrono::seconds;\ntemplate<typename T>\nconstexpr T LIMMIN =\
    \ std::numeric_limits<T>::min();\ntemplate<typename T>\nconstexpr T LIMMAX = std::numeric_limits<T>::max();\n\
    template<typename T>\nconstexpr T INF = (LIMMAX<T> - 1) / 2;\ntemplate<typename\
    \ T>\nconstexpr T PI = T{3.141592653589793238462643383279502884};\ntemplate<typename\
    \ T = u64>\nconstexpr T TEN(const int n)\n{\n    return n == 0 ? T{1} : TEN<T>(n\
    \ - 1) * T{10};\n}\nOstream& operator<<(Ostream& os, i128 v)\n{\n    bool minus\
    \ = false;\n    if (v < 0) { minus = true, v = -v; }\n    Str ans;\n    if (v\
    \ == 0) { ans = \"0\"; }\n    while (v) {\n        ans.push_back('0' + v % 10),\
    \ v /= 10;\n    }\n    std::reverse(ans.begin(), ans.end());\n    return os <<\
    \ (minus ? \"-\" : \"\") << ans;\n}\nOstream& operator<<(Ostream& os, u128 v)\n\
    {\n    Str ans;\n    if (v == 0) { ans = \"0\"; }\n    while (v) {\n        ans.push_back('0'\
    \ + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(), ans.end());\n    return\
    \ os << ans;\n}\ntemplate<typename T>\nbool chmin(T& a, const T& b)\n{\n    if\
    \ (a > b) {\n        a = b;\n        return true;\n    } else {\n        return\
    \ false;\n    }\n}\ntemplate<typename T>\nbool chmax(T& a, const T& b)\n{\n  \
    \  if (a < b) {\n        a = b;\n        return true;\n    } else {\n        return\
    \ false;\n    }\n}\ntemplate<typename T>\nconstexpr T fdiv(T x, T y)\n{\n    if\
    \ (y < T{}) { x = -x, y = -y; }\n    return x >= T{} ? x / y : (x - y + 1) / y;\n\
    }\ntemplate<typename T>\nconstexpr T cdiv(T x, T y)\n{\n    if (y < T{}) { x =\
    \ -x, y = -y; }\n    return x >= T{} ? (x + y - 1) / y : x / y;\n}\ntemplate<typename\
    \ T, typename I>\nconstexpr T modPower(T v, I n, T mod)\n{\n    T ans = 1 % mod;\n\
    \    for (; n > 0; n >>= 1, (v *= v) %= mod) {\n        if (n % 2 == 1) { (ans\
    \ *= v) %= mod; }\n    }\n    return ans;\n}\ntemplate<typename T, typename I>\n\
    constexpr T power(T v, I n)\n{\n    T ans = 1;\n    for (; n > 0; n >>= 1, v *=\
    \ v) {\n        if (n % 2 == 1) { ans *= v; }\n    }\n    return ans;\n}\ntemplate<typename\
    \ T, typename I>\nconstexpr T power(T v, I n, const T& e)\n{\n    T ans = e;\n\
    \    for (; n > 0; n >>= 1, v *= v) {\n        if (n % 2 == 1) { ans *= v; }\n\
    \    }\n    return ans;\n}\ntemplate<typename T>\nVec<T> operator+=(Vec<T>& vs1,\
    \ const Vec<T>& vs2)\n{\n    vs1.insert(vs1.end(), vs2.begin(), vs2.end());\n\
    \    return vs1;\n}\ntemplate<typename T>\nVec<T> operator+(const Vec<T>& vs1,\
    \ const Vec<T>& vs2)\n{\n    auto vs = vs1;\n    vs += vs2;\n    return vs;\n\
    }\ntemplate<typename T>\nvoid fillAll(Vec<T>& vs, const T& v)\n{\n    std::fill(vs.begin(),\
    \ vs.end(), v);\n}\ntemplate<typename T, typename C = Lt<T>>\nvoid sortAll(Vec<T>&\
    \ vs, C comp = C{})\n{\n    std::sort(vs.begin(), vs.end(), comp);\n}\ntemplate<typename\
    \ T>\nvoid reverseAll(Vec<T>& vs)\n{\n    std::reverse(vs.begin(), vs.end());\n\
    }\ntemplate<typename T>\nvoid uniqueAll(Vec<T>& vs)\n{\n    sortAll(vs);\n   \
    \ vs.erase(std::unique(vs.begin(), vs.end()), vs.end());\n}\ntemplate<typename\
    \ T, typename V = T>\nV sumAll(const Vec<T>& vs)\n{\n    return std::accumulate(vs.begin(),\
    \ vs.end(), V{});\n}\ntemplate<typename T>\nint minInd(const Vec<T>& vs)\n{\n\
    \    return std::min_element(vs.begin(), vs.end()) - vs.begin();\n}\ntemplate<typename\
    \ T>\nint maxInd(const Vec<T>& vs)\n{\n    return std::max_element(vs.begin(),\
    \ vs.end()) - vs.begin();\n}\ntemplate<typename T>\nint lbInd(const Vec<T>& vs,\
    \ const T& v)\n{\n    return std::lower_bound(vs.begin(), vs.end(), v) - vs.begin();\n\
    }\ntemplate<typename T>\nint ubInd(const Vec<T>& vs, const T& v)\n{\n    return\
    \ std::upper_bound(vs.begin(), vs.end(), v) - vs.begin();\n}\ntemplate<typename\
    \ T, typename F>\nVec<T> genVec(int n, F gen)\n{\n    Vec<T> ans;\n    std::generate_n(std::back_insert_iterator(ans),\
    \ n, gen);\n    return ans;\n}\nVec<int> iotaVec(int n, int offset = 0)\n{\n \
    \   Vec<int> ans(n);\n    std::iota(ans.begin(), ans.end(), offset);\n    return\
    \ ans;\n}\ntemplate<typename T>\nVec<T> revVec(const Vec<T>& vs)\n{\n    auto\
    \ ans = vs;\n    reverseAll(ans);\n    return ans;\n}\nconstexpr int popcount(const\
    \ u64 v)\n{\n    return v ? __builtin_popcountll(v) : 0;\n}\nconstexpr int log2p1(const\
    \ u64 v)\n{\n    return v ? 64 - __builtin_clzll(v) : 0;\n}\nconstexpr int lsbp1(const\
    \ u64 v)\n{\n    return __builtin_ffsll(v);\n}\nconstexpr int clog(const u64 v)\n\
    {\n    return v ? log2p1(v - 1) : 0;\n}\nconstexpr u64 ceil2(const u64 v)\n{\n\
    \    const int l = clog(v);\n    return (l == 64) ? 0_u64 : (1_u64 << l);\n}\n\
    constexpr u64 floor2(const u64 v)\n{\n    return v ? (1_u64 << (log2p1(v) - 1))\
    \ : 0_u64;\n}\nconstexpr bool ispow2(const u64 v)\n{\n    return (v > 0) and ((v\
    \ & (v - 1)) == 0);\n}\nconstexpr bool btest(const u64 mask, const int ind)\n\
    {\n    return (mask >> ind) & 1_u64;\n}\ntemplate<typename F>\nstruct Fix : F\n\
    {\n    Fix(F&& f) : F{std::forward<F>(f)} {}\n    template<typename... Args>\n\
    \    auto operator()(Args&&... args) const\n    {\n        return F::operator()(*this,\
    \ std::forward<Args>(args)...);\n    }\n};\nclass irange\n{\nprivate:\n    struct\
    \ itr\n    {\n        itr(i64 start = 0, i64 step = 1) : m_cnt{start}, m_step{step}\
    \ {}\n        bool operator!=(const itr& it) const\n        {\n            return\
    \ m_cnt != it.m_cnt;\n        }\n        int operator*()\n        {\n        \
    \    return m_cnt;\n        }\n        itr& operator++()\n        {\n        \
    \    m_cnt += m_step;\n            return *this;\n        }\n        i64 m_cnt,\
    \ m_step;\n    };\n    i64 m_start, m_end, m_step;\npublic:\n    irange(i64 start,\
    \ i64 end, i64 step = 1)\n    {\n        assert(step != 0);\n        const i64\
    \ d = std::abs(step);\n        const i64 l = (step > 0 ? start : end);\n     \
    \   const i64 r = (step > 0 ? end : start);\n        int n = (r - l) / d + ((r\
    \ - l) % d ? 1 : 0);\n        if (l >= r) { n = 0; }\n        m_start = start;\n\
    \        m_end = start + step * n;\n        m_step = step;\n    }\n    itr begin()\
    \ const\n    {\n        return itr{m_start, m_step};\n    }\n    itr end() const\n\
    \    {\n        return itr{m_end, m_step};\n    }\n};\nirange rep(int end)\n{\n\
    \    return irange(0, end, 1);\n}\nirange per(int rend)\n{\n    return irange(rend\
    \ - 1, -1, -1);\n}\n#pragma COMMENT(\"[REFS] Xoshiro: https://prng.di.unimi.it\"\
    )\nnamespace xoshiro_impl {\nu64 x;\nu64 next()\n{\n    uint64_t z = (x += 0x9e3779b97f4a7c15);\n\
    \    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;\n\
    \    return z ^ (z >> 31);\n}\n}\nclass Xoshiro32\n{\npublic:\n    using result_type\
    \ = u32;\n    using T = result_type;\n    Xoshiro32(T seed = 0)\n    {\n     \
    \   xoshiro_impl::x = seed;\n        s[0] = xoshiro_impl::next();\n        s[1]\
    \ = xoshiro_impl::next();\n        s[2] = xoshiro_impl::next();\n        s[3]\
    \ = xoshiro_impl::next();\n    }\n    static constexpr T min()\n    {\n      \
    \  return LIMMIN<T>;\n    }\n    static constexpr T max()\n    {\n        return\
    \ LIMMAX<T>;\n    }\n    T operator()()\n    {\n        return next();\n    }\n\
    private:\n    static constexpr T rotl(const T x, int k)\n    {\n        return\
    \ (x << k) | (x >> (32 - k));\n    }\n    T next()\n    {\n        const T ans\
    \ = rotl(s[1] * 5, 7) * 9;\n        const T t = s[1] << 9;\n        s[2] ^= s[0];\n\
    \        s[3] ^= s[1];\n        s[1] ^= s[2];\n        s[0] ^= s[3];\n       \
    \ s[2] ^= t;\n        s[3] = rotl(s[3], 11);\n        return ans;\n    }\n   \
    \ T s[4];\n};\nclass Xoshiro64\n{\npublic:\n    using result_type = u64;\n   \
    \ using T = result_type;\n    Xoshiro64(T seed = 0)\n    {\n        xoshiro_impl::x\
    \ = seed;\n        s[0] = xoshiro_impl::next();\n        s[1] = xoshiro_impl::next();\n\
    \        s[2] = xoshiro_impl::next();\n        s[3] = xoshiro_impl::next();\n\
    \    }\n    static constexpr T min()\n    {\n        return LIMMIN<T>;\n    }\n\
    \    static constexpr T max()\n    {\n        return LIMMAX<T>;\n    }\n    T\
    \ operator()()\n    {\n        return next();\n    }\nprivate:\n    static constexpr\
    \ T rotl(const T x, int k)\n    {\n        return (x << k) | (x >> (64 - k));\n\
    \    }\n    T next()\n    {\n        const T ans = rotl(s[1] * 5, 7) * 9;\n  \
    \      const T t = s[1] << 17;\n        s[2] ^= s[0];\n        s[3] ^= s[1];\n\
    \        s[1] ^= s[2];\n        s[0] ^= s[3];\n        s[2] ^= t;\n        s[3]\
    \ = rotl(s[3], 45);\n        return ans;\n    }\n    T s[4];\n};\ntemplate<typename\
    \ Rng>\nclass RNG\n{\npublic:\n    using result_type = typename Rng::result_type;\n\
    \    using T = result_type;\n    static constexpr T min()\n    {\n        return\
    \ Rng::min();\n    }\n    static constexpr T max()\n    {\n        return Rng::max();\n\
    \    }\n    RNG() : RNG(std::random_device{}()) {}\n    RNG(T seed) : m_rng(seed)\
    \ {}\n    T operator()()\n    {\n        return m_rng();\n    }\n    template<typename\
    \ T>\n    T val(T min, T max)\n    {\n        return std::uniform_int_distribution<T>(min,\
    \ max)(m_rng);\n    }\n    template<typename T>\n    Pair<T, T> pair(T min, T\
    \ max)\n    {\n        return std::minmax({val<T>(min, max), val<T>(min, max)});\n\
    \    }\n    template<typename T>\n    Vec<T> vec(int n, T min, T max)\n    {\n\
    \        return genVec<T>(n, [&]() { return val<T>(min, max); });\n    }\n   \
    \ template<typename T>\n    Vec<Vec<T>> vvec(int n, int m, T min, T max)\n   \
    \ {\n        return genVec<Vec<T>>(n, [&]() { return vec(m, min, max); });\n \
    \   }\nprivate:\n    Rng m_rng;\n};\nRNG<std::mt19937> rng;\nRNG<std::mt19937_64>\
    \ rng64;\nRNG<Xoshiro32> rng_xo;\nRNG<Xoshiro64> rng_xo64;\ntemplate<typename\
    \ T>\nVec<T> setMoebius(const Vec<T>& xs, bool subset)\n{\n    const int N = ceil2(xs.size());\n\
    \    Vec<T> ys(N);\n    for (int i : rep(xs.size())) {\n        ys[i] = xs[i];\n\
    \    }\n    for (int i = 1; i < N; i <<= 1) {\n        for (int j : rep(N)) {\n\
    \            if ((j & i) == 0) {\n                if (subset) {\n            \
    \        ys[j | i] -= ys[j];\n                } else {\n                    ys[j]\
    \ -= ys[j | i];\n                }\n            }\n        }\n    }\n    return\
    \ ys;\n}\ntemplate<typename T>\nVec<T> setZeta(const Vec<T>& xs, const bool subset)\n\
    {\n    const int N = ceil2(xs.size());\n    Vec<T> ys(N);\n    for (int i : rep(xs.size()))\
    \ {\n        ys[i] = xs[i];\n    }\n    for (int i = 1; i < N; i <<= 1) {\n  \
    \      for (int j : rep(N)) {\n            if ((j & i) == 0) {\n             \
    \   if (subset) {\n                    ys[j | i] += ys[j];\n                }\
    \ else {\n                    ys[j] += ys[j | i];\n                }\n       \
    \     }\n        }\n    }\n    return ys;\n}\ntemplate<typename T>\nVec<T> andConvolute(Vec<T>\
    \ f, Vec<T> g)\n{\n    const int N = ceil2(std::max(f.size(), g.size()));\n  \
    \  f.resize(N), g.resize(N);\n    auto F = setZeta(f, false), G = setZeta(g, false);\n\
    \    for (int i : rep(N)) {\n        F[i] *= G[i];\n    }\n    return setMoebius(F,\
    \ false);\n}\ntemplate<u32 mod_, u32 root_, u32 max2p_>\nclass modint\n{\n   \
    \ template<typename U = u32&>\n    static U modRef()\n    {\n        static u32\
    \ s_mod = 0;\n        return s_mod;\n    }\n    template<typename U = u32&>\n\
    \    static U rootRef()\n    {\n        static u32 s_root = 0;\n        return\
    \ s_root;\n    }\n    template<typename U = u32&>\n    static U max2pRef()\n \
    \   {\n        static u32 s_max2p = 0;\n        return s_max2p;\n    }\npublic:\n\
    \    template<typename U = const u32>\n    static constexpr std::enable_if_t<mod_\
    \ != 0, U> mod()\n    {\n        return mod_;\n    }\n    template<typename U\
    \ = const u32>\n    static std::enable_if_t<mod_ == 0, U> mod()\n    {\n     \
    \   return modRef();\n    }\n    template<typename U = const u32>\n    static\
    \ constexpr std::enable_if_t<mod_ != 0, U> root()\n    {\n        return root_;\n\
    \    }\n    template<typename U = const u32>\n    static std::enable_if_t<mod_\
    \ == 0, U> root()\n    {\n        return rootRef();\n    }\n    template<typename\
    \ U = const u32>\n    static constexpr std::enable_if_t<mod_ != 0, U> max2p()\n\
    \    {\n        return max2p_;\n    }\n    template<typename U = const u32>\n\
    \    static std::enable_if_t<mod_ == 0, U> max2p()\n    {\n        return max2pRef();\n\
    \    }\n    template<typename U = u32>\n    static void setMod(std::enable_if_t<mod_\
    \ == 0, U> m)\n    {\n        modRef() = m;\n    }\n    template<typename U =\
    \ u32>\n    static void setRoot(std::enable_if_t<mod_ == 0, U> r)\n    {\n   \
    \     rootRef() = r;\n    }\n    template<typename U = u32>\n    static void setMax2p(std::enable_if_t<mod_\
    \ == 0, U> m)\n    {\n        max2pRef() = m;\n    }\n    constexpr modint() :\
    \ m_val{0} {}\n    constexpr modint(i64 v) : m_val{normll(v)} {}\n    constexpr\
    \ void setRaw(u32 v)\n    {\n        m_val = v;\n    }\n    constexpr modint operator-()\
    \ const\n    {\n        return modint{0} - (*this);\n    }\n    constexpr modint&\
    \ operator+=(const modint& m)\n    {\n        m_val = norm(m_val + m.val());\n\
    \        return *this;\n    }\n    constexpr modint& operator-=(const modint&\
    \ m)\n    {\n        m_val = norm(m_val + mod() - m.val());\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint& m)\n    {\n        m_val\
    \ = normll((i64)m_val * (i64)m.val() % (i64)mod());\n        return *this;\n \
    \   }\n    constexpr modint& operator/=(const modint& m)\n    {\n        return\
    \ *this *= m.inv();\n    }\n    constexpr modint operator+(const modint& m) const\n\
    \    {\n        auto v = *this;\n        return v += m;\n    }\n    constexpr\
    \ modint operator-(const modint& m) const\n    {\n        auto v = *this;\n  \
    \      return v -= m;\n    }\n    constexpr modint operator*(const modint& m)\
    \ const\n    {\n        auto v = *this;\n        return v *= m;\n    }\n    constexpr\
    \ modint operator/(const modint& m) const\n    {\n        auto v = *this;\n  \
    \      return v /= m;\n    }\n    constexpr bool operator==(const modint& m) const\n\
    \    {\n        return m_val == m.val();\n    }\n    constexpr bool operator!=(const\
    \ modint& m) const\n    {\n        return not(*this == m);\n    }\n    friend\
    \ Istream& operator>>(Istream& is, modint& m)\n    {\n        i64 v;\n       \
    \ return is >> v, m = v, is;\n    }\n    friend Ostream& operator<<(Ostream& os,\
    \ const modint& m)\n    {\n        return os << m.val();\n    }\n    constexpr\
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
    \ 0, id>;\n#pragma region FastIO Printer\nclass Printer\n{\npublic:\n    Printer()\
    \ {}\n    template<typename... Args>\n    int operator()(const Args&... args)\n\
    \    {\n        dump(args...);\n        return 0;\n    }\n    template<typename...\
    \ Args>\n    int ln(const Args&... args)\n    {\n        dump(args...), putchar('\\\
    n');\n        return 0;\n    }\nprivate:\n    template<typename T>\n    void dump(T\
    \ v)\n    {\n        static char tmp[30];\n        if (v < 0) {\n            putchar('-');\n\
    \            v = -v;\n        }\n        int i = 0;\n        do {\n          \
    \  tmp[i++] = v % T{10} + '0';\n            v /= T{10};\n        } while (v);\n\
    \        while (i) {\n            putchar(tmp[--i]);\n        }\n    }\n    void\
    \ dump(bool b)\n    {\n        dump<int>(b);\n    }\n    void dump(char c)\n \
    \   {\n        putchar(c);\n    }\n    void dump(const Str& cs)\n    {\n     \
    \   for (char c : cs) {\n            dump(c);\n        }\n    }\n    template<typename\
    \ T>\n    void dump(const Vec<T>& vs)\n    {\n        for (const int i : rep(vs.size()))\
    \ {\n            if (i) { putchar(' '); }\n            dump(vs[i]);\n        }\n\
    \    }\n    template<typename T>\n    void dump(const Vec<Vec<T>>& vss)\n    {\n\
    \        for (const int i : rep(vss.size())) {\n            if (i) { putchar('\\\
    n'); }\n            dump(vss[i]);\n        }\n    }\n    template<typename T,\
    \ typename... Ts>\n    int dump(const T& v, const Ts&... args)\n    {\n      \
    \  dump(v), putchar(' '), dump(args...);\n        return 0;\n    }\n    static\
    \ inline void putchar(char c)\n    {\n        putchar_unlocked(c);\n    }\n} out;\n\
    #pragma endregion\n#pragma region FastIO Scanner\nclass Scanner\n{\npublic:\n\
    \    Scanner() {}\n    template<typename T>\n    T val()\n    {\n        T ans\
    \ = 0;\n        bool neg = false;\n        char c = getchar();\n        if (c\
    \ < '0') {\n            neg = true;\n        } else {\n            ans = c - '0';\n\
    \        }\n        while (true) {\n            c = getchar();\n            if\
    \ (c < '0') { break; }\n            ans = ans * T{10} + (c - '0');\n        }\n\
    \        if (neg) { ans = -ans; }\n        return ans;\n    }\n    template<typename\
    \ T>\n    T val(T offset)\n    {\n        return val<T>() - offset;\n    }\n \
    \   template<typename T>\n    Vec<T> vec(int n)\n    {\n        return genVec<T>(n,\
    \ [&]() { return val<T>(); });\n    }\n    template<typename T>\n    Vec<T> vec(int\
    \ n, T offset)\n    {\n        return genVec<T>(n, [&]() { return val<T>(offset);\
    \ });\n    }\n    template<typename T>\n    Vec<Vec<T>> vvec(int n, int m)\n \
    \   {\n        return genVec<Vec<T>>(n, [&]() { return vec<T>(m); });\n    }\n\
    \    template<typename T>\n    Vec<Vec<T>> vvec(int n, int m, T offset)\n    {\n\
    \        return genVec<Vec<T>>(n, [&]() { return vec<T>(m, offset); });\n    }\n\
    \    template<typename... Args>\n    auto tup()\n    {\n        return std::tuple<Args...>{val<Args>()...};\n\
    \    }\n    template<typename... Args>\n    auto tup(const Args&... offsets)\n\
    \    {\n        return std::tuple<Args...>{val<Args>(offsets)...};\n    }\nprivate:\n\
    \    static inline char getchar()\n    {\n        return getchar_unlocked();\n\
    \    }\n} in;\ntemplate<>\nchar Scanner::val()\n{\n    return Scanner::getchar();\n\
    }\ntemplate<>\nStr Scanner::val()\n{\n    Str ans;\n    while (true) {\n     \
    \   const char c = Scanner::getchar();\n        if (c == ' ' or c == '\\n' or\
    \ c == EOF) { break; }\n        ans.push_back(c);\n    }\n    return ans;\n}\n\
    int main()\n{\n    using mint = modint_998244353;\n    const auto n = in.val<int>();\n\
    \    const int N = 1 << n;\n    const auto as = in.vec<mint>(N);\n    const auto\
    \ bs = in.vec<mint>(N);\n    const auto cs = andConvolute(as, bs);\n    Vec<int>\
    \ ans(cs.size());\n    for (int i : rep(N)) {\n        ans[i] = cs[i].val();\n\
    \    }\n    out.ln(ans);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include \"../../src/math/and_convolution.hpp\"\n#include \"../../src/math/modint.hpp\"\
    \n#include \"../../src/misc/fastio/printer.hpp\"\n#include \"../../src/misc/fastio/scanner.hpp\"\
    \nint main()\n{\n    using mint = modint_998244353;\n    const auto n = in.val<int>();\n\
    \    const int N = 1 << n;\n    const auto as = in.vec<mint>(N);\n    const auto\
    \ bs = in.vec<mint>(N);\n    const auto cs = andConvolute(as, bs);\n    Vec<int>\
    \ ans(cs.size());\n    for (int i : rep(N)) {\n        ans[i] = cs[i].val();\n\
    \    }\n    out.ln(ans);\n    return 0;\n}\n"
  dependsOn:
  - src/math/and_convolution.hpp
  - src/misc/common.hpp
  - src/misc/common/macros.hpp
  - src/misc/common/type_alias.hpp
  - src/misc/common/constants.hpp
  - src/misc/common/func_alias.hpp
  - src/misc/common/show.hpp
  - src/misc/common/print/int128_t.hpp
  - src/misc/common/operator_alias.hpp
  - src/misc/common/vec_utils.hpp
  - src/misc/common/bit_ops.hpp
  - src/misc/common/fixpoint.hpp
  - src/misc/common/irange.hpp
  - src/misc/common/rng.hpp
  - src/misc/common/xoshiro.hpp
  - src/math/set_moebius.hpp
  - src/math/set_zeta.hpp
  - src/math/modint.hpp
  - src/misc/fastio/printer.hpp
  - src/misc/fastio/scanner.hpp
  isVerificationFile: true
  path: verifications/math/and_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-06-15 01:30:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/math/and_convolution.test.cpp
layout: document
redirect_from:
- /verify/verifications/math/and_convolution.test.cpp
- /verify/verifications/math/and_convolution.test.cpp.html
title: verifications/math/and_convolution.test.cpp
---
