---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/fps.hpp
    title: src/math/fps.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
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
    path: src/misc/common/irange.hpp
    title: src/misc/common/irange.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/macros.hpp
    title: src/misc/common/macros.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/operator_alias.hpp
    title: src/misc/common/operator_alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
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
    path: src/misc/common/vec_utils.hpp
    title: src/misc/common/vec_utils.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/xoshiro.hpp
    title: src/misc/common/xoshiro.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/fastio/printer.hpp
    title: src/misc/fastio/printer.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/fastio/scanner.hpp
    title: src/misc/fastio/scanner.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
  bundledCode: "#include <iostream>\n#include <bits/stdc++.h>\n#pragma region Macros\n\
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
    \ = std::priority_queue<T, Vec<T>, Gt<T>>;\nusing NSec = std::chrono::nanoseconds;\n\
    using USec = std::chrono::microseconds;\nusing MSec = std::chrono::milliseconds;\n\
    using Sec = std::chrono::seconds;\n#pragma endregion\n#pragma region Constants\n\
    template<typename T>\nconstexpr T INF = std::numeric_limits<T>::max() / 4;\ntemplate<typename\
    \ T>\nconstexpr T PI = T{3.141592653589793238462643383279502884};\ntemplate<typename\
    \ T = u64>\nconstexpr T TEN(const int n)\n{\n    return n == 0 ? T{1} : TEN<T>(n\
    \ - 1) * T{10};\n}\n#pragma endregion\n#pragma region FuncAlias\ntemplate<typename\
    \ T>\nbool chmin(T& a, const T& b)\n{\n    if (a > b) {\n        a = b;\n    \
    \    return true;\n    } else {\n        return false;\n    }\n}\ntemplate<typename\
    \ T>\nbool chmax(T& a, const T& b)\n{\n    if (a < b) {\n        a = b;\n    \
    \    return true;\n    } else {\n        return false;\n    }\n}\ntemplate<typename\
    \ T>\nconstexpr T fdiv(T x, T y)\n{\n    if (y < T{}) { x = -x, y = -y; }\n  \
    \  return x >= T{} ? x / y : (x - y + 1) / y;\n}\ntemplate<typename T>\nconstexpr\
    \ T cdiv(T x, T y)\n{\n    if (y < T{}) { x = -x, y = -y; }\n    return x >= T{}\
    \ ? (x + y - 1) / y : x / y;\n}\ntemplate<typename T, typename I>\nconstexpr T\
    \ modPower(T v, I n, T mod)\n{\n    T ans = 1 % mod;\n    for (; n > 0; n >>=\
    \ 1, (v *= v) %= mod) {\n        if (n % 2 == 1) { (ans *= v) %= mod; }\n    }\n\
    \    return ans;\n}\ntemplate<typename T, typename I>\nconstexpr T power(T v,\
    \ I n)\n{\n    T ans = 1;\n    for (; n > 0; n >>= 1, v *= v) {\n        if (n\
    \ % 2 == 1) { ans *= v; }\n    }\n    return ans;\n}\ntemplate<typename T, typename\
    \ I>\nconstexpr T power(T v, I n, const T& e)\n{\n    T ans = e;\n    for (; n\
    \ > 0; n >>= 1, v *= v) {\n        if (n % 2 == 1) { ans *= v; }\n    }\n    return\
    \ ans;\n}\n#pragma endregion\n#pragma region OperatorAlias\ntemplate<typename\
    \ T>\nVec<T> operator+=(Vec<T>& vs1, const Vec<T>& vs2)\n{\n    vs1.insert(vs1.end(),\
    \ vs2.begin(), vs2.end());\n    return vs1;\n}\ntemplate<typename T>\nVec<T> operator+(const\
    \ Vec<T>& vs1, const Vec<T>& vs2)\n{\n    auto vs = vs1;\n    vs += vs2;\n   \
    \ return vs;\n}\n#pragma endregion\n#pragma region VecUtils\ntemplate<typename\
    \ T>\nvoid fillAll(Vec<T>& vs, const T& v)\n{\n    std::fill(vs.begin(), vs.end(),\
    \ v);\n}\ntemplate<typename T, typename C = Lt<T>>\nvoid sortAll(Vec<T>& vs, C\
    \ comp = C{})\n{\n    std::sort(vs.begin(), vs.end(), comp);\n}\ntemplate<typename\
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
    \ ans = vs;\n    reverseAll(ans);\n    return ans;\n}\n#pragma endregion\n#pragma\
    \ region Show\nOstream& operator<<(Ostream& os, i128 v)\n{\n    bool minus = false;\n\
    \    if (v < 0) { minus = true, v = -v; }\n    Str ans;\n    if (v == 0) { ans\
    \ = \"0\"; }\n    while (v) {\n        ans.push_back('0' + v % 10), v /= 10;\n\
    \    }\n    std::reverse(ans.begin(), ans.end());\n    return os << (minus ? \"\
    -\" : \"\") << ans;\n}\nOstream& operator<<(Ostream& os, u128 v)\n{\n    Str ans;\n\
    \    if (v == 0) { ans = \"0\"; }\n    while (v) {\n        ans.push_back('0'\
    \ + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(), ans.end());\n    return\
    \ os << ans;\n}\n#pragma endregion\n#pragma region BitOps\nconstexpr int popcount(const\
    \ u64 v)\n{\n    return v ? __builtin_popcountll(v) : 0;\n}\nconstexpr int log2p1(const\
    \ u64 v)\n{\n    return v ? 64 - __builtin_clzll(v) : 0;\n}\nconstexpr int lsbp1(const\
    \ u64 v)\n{\n    return __builtin_ffsll(v);\n}\nconstexpr int clog(const u64 v)\n\
    {\n    return v ? log2p1(v - 1) : 0;\n}\nconstexpr u64 ceil2(const u64 v)\n{\n\
    \    const int l = clog(v);\n    return (l == 64) ? 0_u64 : (1_u64 << l);\n}\n\
    constexpr u64 floor2(const u64 v)\n{\n    return v ? (1_u64 << (log2p1(v) - 1))\
    \ : 0_u64;\n}\nconstexpr bool ispow2(const u64 v)\n{\n    return (v > 0) and ((v\
    \ & (v - 1)) == 0);\n}\nconstexpr bool btest(const u64 mask, const int ind)\n\
    {\n    return (mask >> ind) & 1_u64;\n}\n#pragma endregion\n#pragma region FixPoint\n\
    template<typename F>\nstruct Fix : F\n{\n    Fix(F&& f) : F{std::forward<F>(f)}\
    \ {}\n    template<typename... Args>\n    auto operator()(Args&&... args) const\n\
    \    {\n        return F::operator()(*this, std::forward<Args>(args)...);\n  \
    \  }\n};\n#pragma endregion\n#pragma region Range\nclass irange\n{\nprivate:\n\
    \    struct itr\n    {\n        itr(int start = 0, int step = 1) : m_cnt{start},\
    \ m_step{step} {}\n        bool operator!=(const itr& it) const\n        {\n \
    \           return m_cnt != it.m_cnt;\n        }\n        int operator*()\n  \
    \      {\n            return m_cnt;\n        }\n        itr& operator++()\n  \
    \      {\n            m_cnt += m_step;\n            return *this;\n        }\n\
    \        int m_cnt, m_step;\n    };\n    int m_start, m_end, m_step;\npublic:\n\
    \    irange(int start, int end, int step = 1)\n    {\n        assert(step != 0);\n\
    \        const int d = std::abs(step);\n        const int l = (step > 0 ? start\
    \ : end);\n        const int r = (step > 0 ? end : start);\n        int n = (r\
    \ - l) / d + ((r - l) % d ? 1 : 0);\n        if (l >= r) { n = 0; }\n        m_start\
    \ = start;\n        m_end = start + step * n;\n        m_step = step;\n    }\n\
    \    itr begin() const\n    {\n        return itr{m_start, m_step};\n    }\n \
    \   itr end() const\n    {\n        return itr{m_end, m_step};\n    }\n};\nirange\
    \ rep(int end)\n{\n    return irange(0, end, 1);\n}\nirange per(int rend)\n{\n\
    \    return irange(rend - 1, -1, -1);\n}\n#pragma endregion\n#pragma COMMENT(\"\
    [REFS] Xoshiro: https://prng.di.unimi.it\")\n#pragma region Xoshiro\nnamespace\
    \ xoshiro_impl {\nu64 x;\nu64 next()\n{\n    uint64_t z = (x += 0x9e3779b97f4a7c15);\n\
    \    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;\n\
    \    return z ^ (z >> 31);\n}\n}\nclass Xoshiro32\n{\npublic:\n    using result_type\
    \ = u32;\n    using T = result_type;\n    Xoshiro32(T seed = 0)\n    {\n     \
    \   xoshiro_impl::x = seed;\n        s[0] = xoshiro_impl::next();\n        s[1]\
    \ = xoshiro_impl::next();\n        s[2] = xoshiro_impl::next();\n        s[3]\
    \ = xoshiro_impl::next();\n    }\n    static constexpr T min()\n    {\n      \
    \  return std::numeric_limits<T>::min();\n    }\n    static constexpr T max()\n\
    \    {\n        return std::numeric_limits<T>::max();\n    }\n    T operator()()\n\
    \    {\n        return next();\n    }\nprivate:\n    static constexpr T rotl(const\
    \ T x, int k)\n    {\n        return (x << k) | (x >> (32 - k));\n    }\n    T\
    \ next()\n    {\n        const T ans = rotl(s[1] * 5, 7) * 9;\n        const T\
    \ t = s[1] << 9;\n        s[2] ^= s[0];\n        s[3] ^= s[1];\n        s[1] ^=\
    \ s[2];\n        s[0] ^= s[3];\n        s[2] ^= t;\n        s[3] = rotl(s[3],\
    \ 11);\n        return ans;\n    }\n    T s[4];\n};\nclass Xoshiro64\n{\npublic:\n\
    \    using result_type = u64;\n    using T = result_type;\n    Xoshiro64(T seed\
    \ = 0)\n    {\n        xoshiro_impl::x = seed;\n        s[0] = xoshiro_impl::next();\n\
    \        s[1] = xoshiro_impl::next();\n        s[2] = xoshiro_impl::next();\n\
    \        s[3] = xoshiro_impl::next();\n    }\n    static constexpr T min()\n \
    \   {\n        return std::numeric_limits<T>::min();\n    }\n    static constexpr\
    \ T max()\n    {\n        return std::numeric_limits<T>::max();\n    }\n    T\
    \ operator()()\n    {\n        return next();\n    }\nprivate:\n    static constexpr\
    \ T rotl(const T x, int k)\n    {\n        return (x << k) | (x >> (64 - k));\n\
    \    }\n    T next()\n    {\n        const T ans = rotl(s[1] * 5, 7) * 9;\n  \
    \      const T t = s[1] << 17;\n        s[2] ^= s[0];\n        s[3] ^= s[1];\n\
    \        s[1] ^= s[2];\n        s[0] ^= s[3];\n        s[2] ^= t;\n        s[3]\
    \ = rotl(s[3], 45);\n        return ans;\n    }\n    T s[4];\n};\n#pragma endregion\n\
    #pragma region RNG\ntemplate<typename Rng>\nclass RNG\n{\npublic:\n    using result_type\
    \ = typename Rng::result_type;\n    using T = result_type;\n    static constexpr\
    \ T min()\n    {\n        return Rng::min();\n    }\n    static constexpr T max()\n\
    \    {\n        return Rng::max();\n    }\n    RNG() : RNG(std::random_device{}())\
    \ {}\n    RNG(T seed) : m_rng(seed) {}\n    T operator()()\n    {\n        return\
    \ m_rng();\n    }\n    template<typename T>\n    T val(T min, T max)\n    {\n\
    \        return std::uniform_int_distribution<T>(min, max)(m_rng);\n    }\n  \
    \  template<typename T>\n    Pair<T, T> pair(T min, T max)\n    {\n        return\
    \ std::minmax({val<T>(min, max), val<T>(min, max)});\n    }\n    template<typename\
    \ T>\n    Vec<T> vec(int n, T min, T max)\n    {\n        return genVec<T>(n,\
    \ [&]() { return val<T>(min, max); });\n    }\n    template<typename T>\n    Vec<Vec<T>>\
    \ vvec(int n, int m, T min, T max)\n    {\n        return genVec<Vec<T>>(n, [&]()\
    \ { return vec(m, min, max); });\n    }\nprivate:\n    Rng m_rng;\n};\nRNG<std::mt19937>\
    \ rng;\nRNG<std::mt19937_64> rng64;\nRNG<Xoshiro32> rng_xo;\nRNG<Xoshiro64> rng_xo64;\n\
    #pragma endregion\ntemplate<u32 mod_, u32 root_, u32 max2p_>\nclass modint\n{\n\
    \    template<typename U = u32&>\n    static U modRef()\n    {\n        static\
    \ u32 s_mod = 0;\n        return s_mod;\n    }\n    template<typename U = u32&>\n\
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
    \    {\n        return modint{*this} += m;\n    }\n    constexpr modint operator-(const\
    \ modint& m) const\n    {\n        return modint{*this} -= m;\n    }\n    constexpr\
    \ modint operator*(const modint& m) const\n    {\n        return modint{*this}\
    \ *= m;\n    }\n    constexpr modint operator/(const modint& m) const\n    {\n\
    \        return modint{*this} /= m;\n    }\n    constexpr bool operator==(const\
    \ modint& m) const\n    {\n        return m_val == m.val();\n    }\n    constexpr\
    \ bool operator!=(const modint& m) const\n    {\n        return not(*this == m);\n\
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
    \ 0, id>;\ntemplate<typename mint>\nclass FPS : public Vec<mint>\n{\npublic:\n\
    \    using std::vector<mint>::vector;\n    using std::vector<mint>::resize;\n\
    \    FPS(const Vec<mint>& vs) : Vec<mint>{vs} {}\n    int size() const\n    {\n\
    \        return Vec<mint>::size();\n    }\n    int deg() const\n    {\n      \
    \  return size() - 1;\n    }\n    FPS low(int n) const\n    {\n        return\
    \ FPS{this->begin(), this->begin() + std::min(n, size())};\n    }\n    FPS rev()\
    \ const\n    {\n        FPS ans = *this;\n        reverseAll(ans);\n        return\
    \ ans;\n    }\n    mint eval(const mint& x) const\n    {\n        mint ans = 0;\n\
    \        mint power = 1;\n        for (int i : rep(size())) {\n            ans\
    \ += power * (*this)[i];\n            power *= x;\n        }\n        return ans;\n\
    \    }\n    mint& operator[](const int n)\n    {\n        if (deg() < n) { resize(n\
    \ + 1); }\n        return Vec<mint>::operator[](n);\n    }\n    const mint& operator[](const\
    \ int n) const\n    {\n        return Vec<mint>::operator[](n);\n    }\n    mint\
    \ at(const int n) const\n    {\n        return (n < size() ? (*this)[n] : mint{0});\n\
    \    }\n    FPS operator-() const\n    {\n        FPS ans = *this;\n        for\
    \ (auto& v : ans) {\n            v = -v;\n        }\n        return ans;\n   \
    \ }\n    FPS& operator+=(const FPS& f)\n    {\n        for (int i : rep(f.size()))\
    \ {\n            (*this)[i] += f[i];\n        }\n        return *this;\n    }\n\
    \    FPS& operator-=(const FPS& f)\n    {\n        for (int i : rep(f.size()))\
    \ {\n            (*this)[i] -= f[i];\n        }\n        return *this;\n    }\n\
    \    FPS& operator*=(const FPS& f)\n    {\n        return (*this) = (*this) *\
    \ f;\n    }\n    FPS& operator<<=(const int s)\n    {\n        return *this =\
    \ (*this << s);\n    }\n    FPS& operator>>=(const int s)\n    {\n        return\
    \ *this = (*this >> s);\n    }\n    FPS operator+(const FPS& f) const\n    {\n\
    \        return FPS(*this) += f;\n    }\n    FPS operator-(const FPS& f) const\n\
    \    {\n        return FPS(*this) -= f;\n    }\n    FPS operator*(const FPS& f)\
    \ const\n    {\n        return mult(f, size() + f.size() - 1);\n    }\n    FPS\
    \ operator<<(const int s) const\n    {\n        FPS ans(size() + s);\n       \
    \ for (int i : rep(size())) {\n            ans[i + s] = (*this)[i];\n        }\n\
    \        return ans;\n    }\n    FPS operator>>(const int s) const\n    {\n  \
    \      FPS ans;\n        for (int i : irange(s, size())) {\n            ans[i\
    \ - s] = (*this)[i];\n        }\n        return ans;\n    }\n    friend Ostream&\
    \ operator<<(Ostream& os, const FPS& f)\n    {\n        return os << static_cast<Vec<mint>>(f);\n\
    \    }\n    FPS derivative() const\n    {\n        FPS ans;\n        for (int\
    \ i : irange(1, size())) {\n            ans[i - 1] = (*this)[i] * i;\n       \
    \ }\n        return ans;\n    }\n    FPS integral() const\n    {\n        FPS\
    \ ans;\n        for (int i : irange(1, size() + 1)) {\n            ans[i] = (*this)[i\
    \ - 1] * mint::sinv(i);\n        }\n        return ans;\n    }\n    FPS mult(const\
    \ FPS& f, int sz) const\n    {\n        if (sz == 0) { return FPS{}; }\n     \
    \   const int N = std::min(size(), sz) + std::min(f.size(), sz) - 1;\n       \
    \ if (N <= (1 << mint::max2p())) {\n            auto ans = conv<mint>(*this, f,\
    \ sz);\n            return ans;\n        } else {\n            const auto cs1\
    \ = conv<submint1>(*this, f, sz);\n            const auto cs2 = conv<submint2>(*this,\
    \ f, sz);\n            const auto cs3 = conv<submint3>(*this, f, sz);\n      \
    \      FPS ans((int)cs1.size());\n            for (int i : rep(cs1.size())) {\n\
    \                ans[i] = restore(cs1[i].val(), cs2[i].val(), cs3[i].val());\n\
    \            }\n            return ans;\n        }\n    }\n    FPS smult(int p,\
    \ const mint a, int sz)\n    {\n        FPS ans = low(sz);\n        for (int i\
    \ = 0; i + p < sz; i++) {\n            ans[i + p] += (*this)[i] * a;\n       \
    \ }\n        return ans;\n    }\n    FPS sdiv(int p, const mint& a, int sz)\n\
    \    {\n        FPS ans = low(sz);\n        for (int i = 0; i + p < sz; i++) {\n\
    \            ans[i + p] -= ans[i] * a;\n        }\n        return ans;\n    }\n\
    \    FPS inv(int sz) const\n    {\n        const int n = size();\n        assert((*this)[0].val()\
    \ != 0);\n        const int N = n * 2 - 1;\n        if (N <= (1 << mint::max2p()))\
    \ {\n            FPS r{(*this)[0].inv()};\n            for (int lg = 0, m = 1;\
    \ m < sz; m <<= 1, lg++) {\n                FPS f{this->begin(), this->begin()\
    \ + std::min(n, 2 * m)};\n                FPS g = r;\n                f.resize(2\
    \ * m), g.resize(2 * m);\n                trans(f, lg + 1, false), trans(g, lg\
    \ + 1, false);\n                for (int i : rep(2 * m)) {\n                 \
    \   f[i] *= g[i];\n                }\n                trans(f, lg + 1, true);\n\
    \                std::fill(f.begin(), f.begin() + m, 0);\n                trans(f,\
    \ lg + 1, false);\n                for (int i : rep(2 * m)) {\n              \
    \      f[i] *= g[i];\n                }\n                trans(f, lg + 1, true);\n\
    \                for (int i = m; i < std::min(2 * m, sz); i++) {\n           \
    \         r[i] = -f[i];\n                }\n            }\n            return\
    \ r;\n        } else {\n            FPS g{(*this)[0].inv()};\n            for\
    \ (int lg = 0, m = 1; m < sz; m <<= 1, lg++) {\n                g = FPS{2} * g\
    \ - this->mult(g.mult(g, 2 * m), 2 * m);\n            }\n            return g.low(sz);\n\
    \        }\n    }\n    FPS log(const int sz) const\n    {\n        assert((*this)[0].val()\
    \ == 1);\n        auto ans = derivative().mult(inv(sz), sz).integral();\n    \
    \    ans.resize(sz);\n        return ans;\n    }\n    FPS exp(const int sz) const\n\
    \    {\n        const int l = lsb(sz);\n        if (l == -1) { return FPS{1}.low(sz);\
    \ }\n        assert((*this)[0].val() == 0);\n        const int n = size();\n \
    \       const int N = n * 2 - 1;\n        if (N <= (1 << mint::max2p())) {\n \
    \           FPS f = {1, (*this)[1]}, g{1}, G{1, 1};\n            for (int m =\
    \ 2, lg = 1; m < sz; m <<= 1, lg++) {\n                auto F = f;\n         \
    \       F.resize(2 * m), trans(F, lg + 1, false);\n                FPS z(m);\n\
    \                for (int i : rep(m)) {\n                    z[i] = F[i] * G[i];\n\
    \                }\n                trans(z, lg, true);\n                std::fill(z.begin(),\
    \ z.begin() + m / 2, 0);\n                trans(z, lg, false);\n             \
    \   for (int i : rep(m)) {\n                    z[i] *= G[i];\n              \
    \  }\n                trans(z, lg, true);\n                for (int i : irange(m\
    \ / 2, m)) {\n                    g[i] = -z[i];\n                }\n         \
    \       G = g, G.resize(m * 2), trans(G, lg + 1, false);\n                auto\
    \ q = low(m).derivative();\n                q.resize(m), trans(q, lg, false);\n\
    \                for (int i : rep(m)) {\n                    q[i] *= F[i];\n \
    \               }\n                trans(q, lg, true);\n                const\
    \ auto df = f.derivative();\n                for (int i : rep(m - 1)) {\n    \
    \                q[i] -= df[i];\n                }\n                q.resize(m\
    \ * 2);\n                for (int i : rep(m - 1)) {\n                    q[m +\
    \ i] = q[i], q[i] = 0;\n                }\n                trans(q, lg + 1, false);\n\
    \                for (int i : rep(m * 2)) {\n                    q[i] *= G[i];\n\
    \                }\n                trans(q, lg + 1, true);\n                q.pop_back();\n\
    \                q = q.integral();\n                for (int i = m; i < std::min(size(),\
    \ m * 2); i++) {\n                    q[i] += (*this)[i];\n                }\n\
    \                std::fill(q.begin(), q.begin() + m, 0);\n                trans(q,\
    \ lg + 1, false);\n                for (int i = 0; i < m * 2; i++) {\n       \
    \             q[i] *= F[i];\n                }\n                trans(q, lg +\
    \ 1, true);\n                for (int i = m; i < 2 * m; i++) {\n             \
    \       f[i] = q[i];\n                }\n            }\n            return f.low(sz);\n\
    \        } else {\n            FPS f{1};\n            for (int m = 1; m < sz;\
    \ m <<= 1) {\n                auto g = low(2 * m);\n                g[0] += 1;\n\
    \                f.resize(2 * m);\n                g -= f.log(2 * m);\n      \
    \          g = f.mult(g, 2 * m);\n                for (int i = m; i < std::min(2\
    \ * m, g.size()); i++) {\n                    f[i] = g[i];\n                }\n\
    \            }\n            return f.low(sz);\n        }\n    }\n    template<typename\
    \ I>\n    FPS pow(I n) const\n    {\n        return pow(n, deg() * n + 1);\n \
    \   }\n    template<typename I>\n    FPS pow(I n, int sz) const\n    {\n     \
    \   if (n == 0) { return FPS{1}.low(sz); }\n        if (size() == 0) { return\
    \ FPS{}; }\n        const int p = lsb(deg() / n);\n        if (p == -1) { return\
    \ FPS{}; }\n        const mint a = (*this)[p];\n        FPS f = (*this) >> p;\n\
    \        for (auto& c : f) {\n            c /= a;\n        }\n        f = f.log(sz\
    \ - p * n);\n        for (auto& c : f) {\n            c *= n;\n        }\n   \
    \     f = f.exp(sz - p * n);\n        FPS g;\n        for (int i : rep(f.size()))\
    \ {\n            g[i + p * n] = f[i] * a.pow(n);\n        }\n        return g;\n\
    \    }\n    FPS tshift(const mint& c) const\n    {\n        const int N = size();\n\
    \        FPS f(N), d(N);\n        for (int i = 0; i < N; i++) {\n            d[i]\
    \ = c.pow(N - 1 - i) * mint::ifact(N - 1 - i);\n        }\n        for (int i\
    \ = 0; i < N; i++) {\n            f[i] = (*this)[i] * mint::fact(i);\n       \
    \ }\n        f = f * d;\n        FPS g(N);\n        for (int i = 0; i < N; i++)\
    \ {\n            g[i] = f[i + N - 1] * mint::ifact(i);\n        }\n        return\
    \ g;\n    }\n    FPS quot(const FPS& g) const\n    {\n        const int N = size(),\
    \ M = g.size();\n        if (N < M) { return FPS{}; }\n        const auto fR =\
    \ rev(), gR = g.rev();\n        return fR.mult(gR.inv(N - M + 1), N - M + 1).rev();\n\
    \    }\n    FPS rem(const FPS& g) const\n    {\n        return (*this) - g * quot(g);\n\
    \    }\nprivate:\n    int lsb() const\n    {\n        return lsb(deg());\n   \
    \ }\n    int lsb(int sz) const\n    {\n        for (int p : rep(sz + 1)) {\n \
    \           if ((*this)[p].val() != 0) { return p; }\n        }\n        return\
    \ -1;\n    }\n    using submint1 = modint<469762049, 3, 26>;\n    using submint2\
    \ = modint<167772161, 3, 25>;\n    using submint3 = modint<754974721, 11, 24>;\n\
    \    template<typename submint>\n    static void trans(Vec<submint>& as, int lg,\
    \ bool rev)\n    {\n        const int N = 1 << lg;\n        assert((int)as.size()\
    \ == N);\n        Vec<submint> rs, irs;\n        if (rs.empty()) {\n         \
    \   const submint r = submint(submint::root()), ir = r.inv();\n            rs.resize(submint::max2p()\
    \ + 1), irs.resize(submint::max2p() + 1);\n            rs.back() = -r.pow((submint::mod()\
    \ - 1) >> submint::max2p()),\n            irs.back() = -ir.pow((submint::mod()\
    \ - 1) >> submint::max2p());\n            for (u32 i : irange(submint::max2p(),\
    \ 0, -1)) {\n                rs[i - 1] = -(rs[i] * rs[i]);\n                irs[i\
    \ - 1] = -(irs[i] * irs[i]);\n            }\n        }\n        const auto drange\
    \ = (rev ? irange(0, lg, 1) : irange(lg - 1, -1, -1));\n        for (const int\
    \ d : drange) {\n            const int width = 1 << d;\n            submint e\
    \ = 1;\n            for (int i = 0, j = 1; i < N; i += width * 2, j++) {\n   \
    \             for (int l = i, r = i + width; l < i + width; l++, r++) {\n    \
    \                if (rev) {\n                        const submint x = as[l],\
    \ y = as[r];\n                        as[l] = x + y, as[r] = (x - y) * e;\n  \
    \                  } else {\n                        const submint x = as[l],\
    \ y = as[r] * e;\n                        as[l] = x + y, as[r] = x - y;\n    \
    \                }\n                }\n                e *= (rev ? irs : rs)[lsbp1(j)\
    \ + 1];\n            }\n        }\n        if (rev) {\n            const submint\
    \ iN = submint{N}.inv();\n            for (auto& a : as) {\n                a\
    \ *= iN;\n            }\n        }\n    }\n    template<typename submint>\n  \
    \  static Vec<submint> conv(const Vec<mint>& as, const Vec<mint>& bs, int sz)\n\
    \    {\n        const int an = std::min((int)as.size(), sz);\n        const int\
    \ bn = std::min((int)bs.size(), sz);\n        const int M = an + bn - 1;\n   \
    \     const int lg = clog(M);\n        const int L = 1 << lg;\n        Vec<submint>\
    \ As(L), Bs(L);\n        for (int i : rep(an)) {\n            As[i] = as[i].val();\n\
    \        }\n        for (int i : rep(bn)) {\n            Bs[i] = bs[i].val();\n\
    \        }\n        trans(As, lg, false), trans(Bs, lg, false);\n        for (int\
    \ i : rep(L)) {\n            As[i] *= Bs[i];\n        }\n        trans(As, lg,\
    \ true);\n        const int N = std::min(sz, (int)as.size() + (int)bs.size() -\
    \ 1);\n        As.resize(N);\n        return As;\n    }\n    static constexpr\
    \ submint2 ip1 = submint2{submint1::mod()}.inv();\n    static constexpr submint3\
    \ ip2 = submint3{submint2::mod()}.inv();\n    static constexpr submint3 ip1p2\
    \ = submint3{submint1::mod()}.inv() * ip2;\n    static constexpr mint p1()\n \
    \   {\n        return mint{submint1::mod()};\n    }\n    static constexpr mint\
    \ p1p2()\n    {\n        return p1() * mint{submint2::mod()};\n    }\n    static\
    \ constexpr mint restore(int x1, int x2, int x3)\n    {\n        const int k0\
    \ = x1;\n        const int k1 = (ip1 * (x2 - k0)).val();\n        const int k2\
    \ = (ip1p2 * (x3 - k0) - ip2 * k1).val();\n        return p1p2() * k2 + p1() *\
    \ k1 + k0;\n    }\n};\n#pragma region FastIO Printer\nclass Printer\n{\npublic:\n\
    \    Printer() {}\n    template<typename... Args>\n    int operator()(const Args&...\
    \ args)\n    {\n        dump(args...);\n        return 0;\n    }\n    template<typename...\
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
    int main()\n{\n    using mint = modint_998244353;\n    const auto N = in.val<int>();\n\
    \    FPS<mint> as(N);\n    for (auto& a : as) {\n        a.setRaw(in.val<int>());\n\
    \    }\n    const auto bs = as.log(N);\n    Vec<int> ans(N);\n    for (int i :\
    \ rep(N)) {\n        ans[i] = bs.at(i).val();\n    }\n    out.ln(ans);\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n#include \"../../src/math/fps.hpp\"\n#include \"../../src/misc/fastio/printer.hpp\"\
    \n#include \"../../src/misc/fastio/scanner.hpp\"\nint main()\n{\n    using mint\
    \ = modint_998244353;\n    const auto N = in.val<int>();\n    FPS<mint> as(N);\n\
    \    for (auto& a : as) {\n        a.setRaw(in.val<int>());\n    }\n    const\
    \ auto bs = as.log(N);\n    Vec<int> ans(N);\n    for (int i : rep(N)) {\n   \
    \     ans[i] = bs.at(i).val();\n    }\n    out.ln(ans);\n    return 0;\n}\n"
  dependsOn:
  - src/math/fps.hpp
  - src/misc/common.hpp
  - src/misc/common/macros.hpp
  - src/misc/common/type_alias.hpp
  - src/misc/common/constants.hpp
  - src/misc/common/func_alias.hpp
  - src/misc/common/operator_alias.hpp
  - src/misc/common/vec_utils.hpp
  - src/misc/common/show.hpp
  - src/misc/common/print/int128_t.hpp
  - src/misc/common/bit_ops.hpp
  - src/misc/common/fixpoint.hpp
  - src/misc/common/irange.hpp
  - src/misc/common/rng.hpp
  - src/misc/common/xoshiro.hpp
  - src/math/modint.hpp
  - src/misc/fastio/printer.hpp
  - src/misc/fastio/scanner.hpp
  isVerificationFile: true
  path: verifications/math/fps.log.test.cpp
  requiredBy: []
  timestamp: '2021-05-27 03:45:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/math/fps.log.test.cpp
layout: document
redirect_from:
- /verify/verifications/math/fps.log.test.cpp
- /verify/verifications/math/fps.log.test.cpp.html
title: verifications/math/fps.log.test.cpp
---
