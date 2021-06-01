---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/is_prime.hpp
    title: src/math/is_prime.hpp
  - icon: ':question:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
  - icon: ':x:'
    path: src/math/modint64.hpp
    title: src/math/modint64.hpp
  - icon: ':x:'
    path: src/math/prime_factors.hpp
    title: src/math/prime_factors.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\n#include <iostream>\nusing i32 = int;\n\
    using u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\nusing f64 = double;\nusing\
    \ f80 = long double;\nusing f128 = __float128;\nconstexpr i32 operator\"\" _i32(u64\
    \ v)\n{\n    return v;\n}\nconstexpr i32 operator\"\" _u32(u64 v)\n{\n    return\
    \ v;\n}\nconstexpr i64 operator\"\" _i64(u64 v)\n{\n    return v;\n}\nconstexpr\
    \ u64 operator\"\" _u64(u64 v)\n{\n    return v;\n}\nconstexpr f64 operator\"\"\
    \ _f64(f80 v)\n{\n    return v;\n}\nconstexpr f80 operator\"\" _f80(f80 v)\n{\n\
    \    return v;\n}\nusing Istream = std::istream;\nusing Ostream = std::ostream;\n\
    using Str = std::string;\ntemplate<typename T>\nusing Lt = std::less<T>;\ntemplate<typename\
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
    using Sec = std::chrono::seconds;\ntemplate<typename T>\nconstexpr T INF = std::numeric_limits<T>::max()\
    \ / 4;\ntemplate<typename T>\nconstexpr T PI = T{3.141592653589793238462643383279502884};\n\
    template<typename T = u64>\nconstexpr T TEN(const int n)\n{\n    return n == 0\
    \ ? T{1} : TEN<T>(n - 1) * T{10};\n}\ntemplate<typename T>\nbool chmin(T& a, const\
    \ T& b)\n{\n    if (a > b) {\n        a = b;\n        return true;\n    } else\
    \ {\n        return false;\n    }\n}\ntemplate<typename T>\nbool chmax(T& a, const\
    \ T& b)\n{\n    if (a < b) {\n        a = b;\n        return true;\n    } else\
    \ {\n        return false;\n    }\n}\ntemplate<typename T>\nconstexpr T fdiv(T\
    \ x, T y)\n{\n    if (y < T{}) { x = -x, y = -y; }\n    return x >= T{} ? x /\
    \ y : (x - y + 1) / y;\n}\ntemplate<typename T>\nconstexpr T cdiv(T x, T y)\n\
    {\n    if (y < T{}) { x = -x, y = -y; }\n    return x >= T{} ? (x + y - 1) / y\
    \ : x / y;\n}\ntemplate<typename T, typename I>\nconstexpr T modPower(T v, I n,\
    \ T mod)\n{\n    T ans = 1 % mod;\n    for (; n > 0; n >>= 1, (v *= v) %= mod)\
    \ {\n        if (n % 2 == 1) { (ans *= v) %= mod; }\n    }\n    return ans;\n\
    }\ntemplate<typename T, typename I>\nconstexpr T power(T v, I n)\n{\n    T ans\
    \ = 1;\n    for (; n > 0; n >>= 1, v *= v) {\n        if (n % 2 == 1) { ans *=\
    \ v; }\n    }\n    return ans;\n}\ntemplate<typename T, typename I>\nconstexpr\
    \ T power(T v, I n, const T& e)\n{\n    T ans = e;\n    for (; n > 0; n >>= 1,\
    \ v *= v) {\n        if (n % 2 == 1) { ans *= v; }\n    }\n    return ans;\n}\n\
    template<typename T>\nVec<T> operator+=(Vec<T>& vs1, const Vec<T>& vs2)\n{\n \
    \   vs1.insert(vs1.end(), vs2.begin(), vs2.end());\n    return vs1;\n}\ntemplate<typename\
    \ T>\nVec<T> operator+(const Vec<T>& vs1, const Vec<T>& vs2)\n{\n    auto vs =\
    \ vs1;\n    vs += vs2;\n    return vs;\n}\ntemplate<typename T>\nvoid fillAll(Vec<T>&\
    \ vs, const T& v)\n{\n    std::fill(vs.begin(), vs.end(), v);\n}\ntemplate<typename\
    \ T, typename C = Lt<T>>\nvoid sortAll(Vec<T>& vs, C comp = C{})\n{\n    std::sort(vs.begin(),\
    \ vs.end(), comp);\n}\ntemplate<typename T>\nvoid reverseAll(Vec<T>& vs)\n{\n\
    \    std::reverse(vs.begin(), vs.end());\n}\ntemplate<typename T>\nvoid uniqueAll(Vec<T>&\
    \ vs)\n{\n    sortAll(vs);\n    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());\n\
    }\ntemplate<typename T, typename V = T>\nV sumAll(const Vec<T>& vs)\n{\n    return\
    \ std::accumulate(vs.begin(), vs.end(), V{});\n}\ntemplate<typename T>\nint minInd(const\
    \ Vec<T>& vs)\n{\n    return std::min_element(vs.begin(), vs.end()) - vs.begin();\n\
    }\ntemplate<typename T>\nint maxInd(const Vec<T>& vs)\n{\n    return std::max_element(vs.begin(),\
    \ vs.end()) - vs.begin();\n}\ntemplate<typename T>\nint lbInd(const Vec<T>& vs,\
    \ const T& v)\n{\n    return std::lower_bound(vs.begin(), vs.end(), v) - vs.begin();\n\
    }\ntemplate<typename T>\nint ubInd(const Vec<T>& vs, const T& v)\n{\n    return\
    \ std::upper_bound(vs.begin(), vs.end(), v) - vs.begin();\n}\ntemplate<typename\
    \ T, typename F>\nVec<T> genVec(int n, F gen)\n{\n    Vec<T> ans;\n    std::generate_n(std::back_insert_iterator(ans),\
    \ n, gen);\n    return ans;\n}\nVec<int> iotaVec(int n, int offset = 0)\n{\n \
    \   Vec<int> ans(n);\n    std::iota(ans.begin(), ans.end(), offset);\n    return\
    \ ans;\n}\ntemplate<typename T>\nVec<T> revVec(const Vec<T>& vs)\n{\n    auto\
    \ ans = vs;\n    reverseAll(ans);\n    return ans;\n}\nOstream& operator<<(Ostream&\
    \ os, i128 v)\n{\n    bool minus = false;\n    if (v < 0) { minus = true, v =\
    \ -v; }\n    Str ans;\n    if (v == 0) { ans = \"0\"; }\n    while (v) {\n   \
    \     ans.push_back('0' + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(),\
    \ ans.end());\n    return os << (minus ? \"-\" : \"\") << ans;\n}\nOstream& operator<<(Ostream&\
    \ os, u128 v)\n{\n    Str ans;\n    if (v == 0) { ans = \"0\"; }\n    while (v)\
    \ {\n        ans.push_back('0' + v % 10), v /= 10;\n    }\n    std::reverse(ans.begin(),\
    \ ans.end());\n    return os << ans;\n}\nconstexpr int popcount(const u64 v)\n\
    {\n    return v ? __builtin_popcountll(v) : 0;\n}\nconstexpr int log2p1(const\
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
    \ itr\n    {\n        itr(int start = 0, int step = 1) : m_cnt{start}, m_step{step}\
    \ {}\n        bool operator!=(const itr& it) const\n        {\n            return\
    \ m_cnt != it.m_cnt;\n        }\n        int operator*()\n        {\n        \
    \    return m_cnt;\n        }\n        itr& operator++()\n        {\n        \
    \    m_cnt += m_step;\n            return *this;\n        }\n        int m_cnt,\
    \ m_step;\n    };\n    int m_start, m_end, m_step;\npublic:\n    irange(int start,\
    \ int end, int step = 1)\n    {\n        assert(step != 0);\n        const int\
    \ d = std::abs(step);\n        const int l = (step > 0 ? start : end);\n     \
    \   const int r = (step > 0 ? end : start);\n        int n = (r - l) / d + ((r\
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
    \ rng64;\nRNG<Xoshiro32> rng_xo;\nRNG<Xoshiro64> rng_xo64;\ntemplate<u32 mod_,\
    \ u32 root_, u32 max2p_>\nclass modint\n{\n    template<typename U = u32&>\n \
    \   static U modRef()\n    {\n        static u32 s_mod = 0;\n        return s_mod;\n\
    \    }\n    template<typename U = u32&>\n    static U rootRef()\n    {\n     \
    \   static u32 s_root = 0;\n        return s_root;\n    }\n    template<typename\
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
    \ 0, id>;\ntemplate<u64 mod_, u64 root_, u64 max2p_>\nclass modint64\n{\n    template<typename\
    \ U = u64&>\n    static U modRef()\n    {\n        static u64 s_mod = 0;\n   \
    \     return s_mod;\n    }\n    template<typename U = u64&>\n    static U rootRef()\n\
    \    {\n        static u64 s_root = 0;\n        return s_root;\n    }\n    template<typename\
    \ U = u64&>\n    static U max2pRef()\n    {\n        static u64 s_max2p = 0;\n\
    \        return s_max2p;\n    }\npublic:\n    template<typename U = const u64>\n\
    \    static constexpr std::enable_if_t<mod_ != 0, U> mod()\n    {\n        return\
    \ mod_;\n    }\n    template<typename U = const u64>\n    static std::enable_if_t<mod_\
    \ == 0, U> mod()\n    {\n        return modRef();\n    }\n    template<typename\
    \ U = const u64>\n    static constexpr std::enable_if_t<mod_ != 0, U> root()\n\
    \    {\n        return root_;\n    }\n    template<typename U = const u64>\n \
    \   static std::enable_if_t<mod_ == 0, U> root()\n    {\n        return rootRef();\n\
    \    }\n    template<typename U = const u64>\n    static constexpr std::enable_if_t<mod_\
    \ != 0, U> max2p()\n    {\n        return max2p_;\n    }\n    template<typename\
    \ U = const u64>\n    static std::enable_if_t<mod_ == 0, U> max2p()\n    {\n \
    \       return max2pRef();\n    }\n    template<typename U = u64>\n    static\
    \ void setMod(std::enable_if_t<mod_ == 0, U> m)\n    {\n        modRef() = m;\n\
    \    }\n    template<typename U = u64>\n    static void setRoot(std::enable_if_t<mod_\
    \ == 0, U> r)\n    {\n        rootRef() = r;\n    }\n    template<typename U =\
    \ u64>\n    static void setMax2p(std::enable_if_t<mod_ == 0, U> m)\n    {\n  \
    \      max2pRef() = m;\n    }\n    constexpr modint64() : m_val{0} {}\n    constexpr\
    \ modint64(const i64 v) : m_val{normLL(v)} {}\n    constexpr void setRaw(const\
    \ u64 v)\n    {\n        m_val = v;\n    }\n    constexpr modint64 operator+()\
    \ const\n    {\n        return *this;\n    }\n    constexpr modint64 operator-()\
    \ const\n    {\n        return modint64{0} - (*this);\n    }\n    constexpr modint64&\
    \ operator+=(const modint64& m)\n    {\n        m_val = norm(m_val + m.val());\n\
    \        return *this;\n    }\n    constexpr modint64& operator-=(const modint64&\
    \ m)\n    {\n        m_val = norm(m_val + mod() - m.val());\n        return *this;\n\
    \    }\n    constexpr modint64& operator*=(const modint64& m)\n    {\n       \
    \ m_val = normLL((i128)m_val * (i128)m.val() % (i128)mod());\n        return *this;\n\
    \    }\n    constexpr modint64& operator/=(const modint64& m)\n    {\n       \
    \ return *this *= m.inv();\n    }\n    constexpr modint64 operator+(const modint64&\
    \ m) const\n    {\n        return modint64{*this} += m;\n    }\n    constexpr\
    \ modint64 operator-(const modint64& m) const\n    {\n        return modint64{*this}\
    \ -= m;\n    }\n    constexpr modint64 operator*(const modint64& m) const\n  \
    \  {\n        return modint64{*this} *= m;\n    }\n    constexpr modint64 operator/(const\
    \ modint64& m) const\n    {\n        return modint64{*this} /= m;\n    }\n   \
    \ constexpr bool operator==(const modint64& m) const\n    {\n        return m_val\
    \ == m();\n    }\n    constexpr bool operator!=(const modint64& m) const\n   \
    \ {\n        return not(*this == m);\n    }\n    friend Istream& operator>>(Istream&\
    \ is, modint64& m)\n    {\n        i64 v;\n        return is >> v, m = v, is;\n\
    \    }\n    friend Ostream& operator<<(Ostream& os, const modint64& m)\n    {\n\
    \        return os << m.val();\n    }\n    constexpr u64 val() const\n    {\n\
    \        return m_val;\n    }\n    template<typename I>\n    constexpr modint64\
    \ pow(I n) const\n    {\n        return power(*this, n);\n    }\n    constexpr\
    \ modint64 inv() const\n    {\n        return pow(mod() - 2);\n    }\n    modint64\
    \ sinv() const\n    {\n        return sinv(m_val);\n    }\n    static modint64\
    \ fact(u32 n)\n    {\n        static Vec<modint64> fs{1, 1};\n        for (u32\
    \ i = (u32)fs.size(); i <= n; i++) {\n            fs.push_back(fs.back() * i);\n\
    \        }\n        return fs[n];\n    }\n    static modint64 ifact(u32 n)\n \
    \   {\n        static Vec<modint64> ifs{1, 1};\n        for (u32 i = (u32)ifs.size();\
    \ i <= n; i++) {\n            ifs.push_back(ifs.back() * sinv(i));\n        }\n\
    \        return ifs[n];\n    }\n    static modint64 perm(int n, int k)\n    {\n\
    \        return k > n or k < 0 ? modint64{0} : fact(n) * ifact(n - k);\n    }\n\
    \    static modint64 comb(int n, int k)\n    {\n        return k > n or k < 0\
    \ ? modint64{0} : fact(n) * ifact(n - k) * ifact(k);\n    }\nprivate:\n    static\
    \ constexpr u64 norm(const u64 x)\n    {\n        return x < mod() ? x : x - mod();\n\
    \    }\n    static constexpr u64 normLL(const i64 x)\n    {\n        return norm(u64((i128)x\
    \ % (i128)mod() + (i128)mod()));\n    }\n    static modint64 sinv(u32 n)\n   \
    \ {\n        static Vec<modint64> is{1, 1};\n        for (u32 i = (u32)is.size();\
    \ i <= n; i++) {\n            is.push_back(-is[mod() % i] * (mod() / i));\n  \
    \      }\n        return is[n];\n    }\n    u64 m_val;\n};\ntemplate<int id>\n\
    using modint64_dynamic = modint64<0, 0, id>;\ntemplate<typename mint>\nbool millerRabin(u64\
    \ n, const Vec<u64>& as)\n{\n    auto d = n - 1;\n    for (; (d & 1) == 0; d >>=\
    \ 1) {}\n    for (const u64 a : as) {\n        if (n <= a) { break; }\n      \
    \  auto s = d;\n        mint x = mint(a).pow(s);\n        while (x.val() != 1\
    \ and x.val() != n - 1 and s != n - 1) {\n            x *= x, s <<= 1;\n     \
    \   }\n        if (x.val() != n - 1 and s % 2 == 0) { return false; }\n    }\n\
    \    return true;\n}\nbool isPrime(u64 n)\n{\n    using mint = modint_dynamic<873293817>;\n\
    \    using mint64 = modint64_dynamic<828271328>;\n    if (n == 1) { return false;\
    \ }\n    if ((n & 1) == 0) { return n == 2; }\n    if (n < (1ULL << 30)) {\n \
    \       mint::setMod(n);\n        return millerRabin<mint>(n, {2, 7, 61});\n \
    \   } else {\n        mint64::setMod(n);\n        return millerRabin<mint64>(n,\
    \ {2, 325, 9375, 28178, 450775, 9780504});\n    }\n}\ntemplate<typename mint>\n\
    u64 pollardRho(u64 n)\n{\n    if (n % 2 == 0) { return 2; }\n    if (isPrime(n))\
    \ { return n; }\n    mint c;\n    auto f = [&](const mint& x) { return x * x +\
    \ c; };\n    while (true) {\n        mint x, y, ys, q = 1;\n        y = rng64.val<u64>(0,\
    \ n - 2) + 2;\n        c = rng64.val<u64>(0, n - 2) + 2;\n        u64 d = 1;\n\
    \        constexpr u32 dk = 128;\n        for (u32 r = 1; d == 1; r <<= 1) {\n\
    \            x = y;\n            for (u32 i = 0; i < r; i++) {\n             \
    \   y = f(y);\n            }\n            for (u32 k = 0; k < r and d == 1; k\
    \ += dk) {\n                ys = y;\n                for (u32 i = 0; i < dk and\
    \ i < r - k; i++) {\n                    q *= x - (y = f(y));\n              \
    \  }\n                d = std::gcd((u64)q.val(), n);\n            }\n        }\n\
    \        if (d == n) {\n            do {\n                d = std::gcd(u64((x\
    \ - (ys = f(ys))).val()), n);\n            } while (d == 1);\n        }\n    \
    \    if (d != n) { return d; }\n    }\n    return n;\n}\nMap<u64, int> primeFactors(u64\
    \ n)\n{\n    using mint = modint_dynamic<287687412>;\n    using mint64 = modint64_dynamic<4832432>;\n\
    \    Map<u64, int> ans;\n    Fix([&](auto dfs, u64 x) -> void {\n        while\
    \ ((x & 1) == 0) {\n            x >>= 1, ans[2]++;\n        }\n        if (x ==\
    \ 1) { return; }\n        u64 p;\n        if (x < (1ULL << 30)) {\n          \
    \  mint::setMod(x);\n            p = pollardRho<mint>(x);\n        } else {\n\
    \            mint64::setMod(x);\n            p = pollardRho<mint64>(x);\n    \
    \    }\n        if (p == x) {\n            ans[p]++;\n            return;\n  \
    \      }\n        dfs(p), dfs(x / p);\n    })(n);\n    return ans;\n}\nVec<u64>\
    \ divisors(const u64 n)\n{\n    const auto fs = primeFactors(n);\n    Vec<u64>\
    \ ds{1};\n    for (const auto& [p, e] : fs) {\n        u64 pe = p;\n        const\
    \ u32 dn = ds.size();\n        for (i32 i = 0; i < e; i++, pe *= p) {\n      \
    \      for (u32 j = 0; j < dn; j++) {\n                ds.push_back(ds[j] * pe);\n\
    \            }\n        }\n    }\n    return ds;\n}\ntemplate<typename mint>\n\
    mint primitiveRoot()\n{\n    const auto p = mint::mod();\n    if (p == 2) { return\
    \ 1; }\n    const auto fs = primeFactors(p - 1);\n    for (mint g = 2;; g += 1)\
    \ {\n        bool ok = true;\n        for (const auto& [p, n] : fs) {\n      \
    \      const auto per = (p - 1) / p;\n            if (g.pow(per)() == 1) {\n \
    \               ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) { return g; }\n    }\n    return 0;\n}\n"
  code: "#pragma once\n#include \"../misc/common.hpp\"\n#include \"prime_factors.hpp\"\
    \ntemplate<typename mint>\nmint primitiveRoot()\n{\n    const auto p = mint::mod();\n\
    \    if (p == 2) { return 1; }\n    const auto fs = primeFactors(p - 1);\n   \
    \ for (mint g = 2;; g += 1) {\n        bool ok = true;\n        for (const auto&\
    \ [p, n] : fs) {\n            const auto per = (p - 1) / p;\n            if (g.pow(per)()\
    \ == 1) {\n                ok = false;\n                break;\n            }\n\
    \        }\n        if (ok) { return g; }\n    }\n    return 0;\n}\n"
  dependsOn:
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
  - src/math/prime_factors.hpp
  - src/math/is_prime.hpp
  - src/math/modint.hpp
  - src/math/modint64.hpp
  isVerificationFile: false
  path: src/math/primitive_root.hpp
  requiredBy: []
  timestamp: '2021-06-02 01:47:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/primitive_root.hpp
layout: document
redirect_from:
- /library/src/math/primitive_root.hpp
- /library/src/math/primitive_root.hpp.html
title: src/math/primitive_root.hpp
---
