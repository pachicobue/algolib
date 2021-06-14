---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/bit_vector.hpp
    title: Bit Vector
  - icon: ':heavy_check_mark:'
    path: src/data_structure/wavelet.hpp
    title: "Wavelet\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: src/misc/bin_search.hpp
    title: src/misc/bin_search.hpp
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
    PROBLEM: https://yukicoder.me/problems/1937
    links:
    - https://yukicoder.me/problems/1937
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
    \ rng64;\nRNG<Xoshiro32> rng_xo;\nRNG<Xoshiro64> rng_xo64;\nclass BitVector\n\
    {\n    static constexpr int B = 64;\n    static int rank(u64 v, int i)\n    {\n\
    \        if (i == 0) { return 0; }\n        return popcount((v << (B - i)) >>\
    \ (B - i));\n    }\n    struct Block\n    {\n        u64 bits = 0;\n        int\
    \ rank = 0;\n    };\npublic:\n    BitVector(int n) : m_size{n}, m_bn{n / B + 1},\
    \ m_blocks(m_bn) {}\n    void set(int i)\n    {\n        assert(0 <= i and i <\
    \ m_size);\n        m_blocks[i / B].bits |= (1_u64 << (i % B));\n        m_calced\
    \ = false;\n    }\n    void reset(int i)\n    {\n        assert(0 <= i and i <\
    \ m_size);\n        m_blocks[i / B].bits &= ~(1_u64 << (i % B));\n        m_calced\
    \ = false;\n    }\n    int rank0(int i)\n    {\n        return i - rank1(i);\n\
    \    }\n    int rank1(int i)\n    {\n        assert(0 <= i and i <= m_size);\n\
    \        calc();\n        return m_blocks[i / B].rank + rank(m_blocks[i / B].bits,\
    \ i % B);\n    }\n    int select0(int k)\n    {\n        assert(0 <= k and k <\
    \ m_size);\n        int inf = -1, sup = m_size;\n        while (sup - inf > 1)\
    \ {\n            const int mid = (inf + sup) / 2;\n            const int z = rank0(mid);\n\
    \            (z < k ? inf : sup) = mid;\n        }\n        return sup;\n    }\n\
    \    int select1(int k)\n    {\n        assert(0 <= k and k < m_size);\n     \
    \   int inf = -1, sup = m_size;\n        while (sup - inf > 1) {\n           \
    \ const int mid = (inf + sup) / 2;\n            const int o = rank1(mid);\n  \
    \          (o < k ? inf : sup) = mid;\n        }\n        return sup;\n    }\n\
    \    int zero()\n    {\n        calc();\n        return m_zero;\n    }\n    int\
    \ one()\n    {\n        return m_size - zero();\n    }\nprivate:\n    void calc()\n\
    \    {\n        if (not m_calced) {\n            m_zero = m_size;\n          \
    \  for (int i : irange(1, m_bn)) {\n                const int p = popcount(m_blocks[i\
    \ - 1].bits);\n                m_blocks[i].rank += m_blocks[i - 1].rank + p;\n\
    \                m_zero -= p;\n            }\n            m_zero -= popcount(m_blocks[m_bn\
    \ - 1].bits);\n            m_calced = true;\n        }\n    }\n    int m_size;\n\
    \    int m_bn;\n    Vec<Block> m_blocks;\n    bool m_calced = false;\n    int\
    \ m_zero = 0;\n};\ntemplate<typename T>\nclass WaveletMatrix\n{\npublic:\n   \
    \ WaveletMatrix(Vec<T> vs, int lg = sizeof(T) * 8)\n        : m_n(vs.size()),\
    \ m_lg{lg}, m_bvs(lg, BitVector(m_n))\n    {\n        Vec<T> nvs(m_n);\n     \
    \   for (int bi : per(lg)) {\n            for (int i : rep(m_n)) {\n         \
    \       if (btest(vs[i], bi)) { m_bvs[bi].set(i); }\n            }\n         \
    \   int is[2] = {0, m_bvs[bi].zero()};\n            for (int i : rep(m_n)) {\n\
    \                nvs[is[btest(vs[i], bi)]++] = vs[i];\n            }\n       \
    \     std::swap(vs, nvs);\n        }\n    }\n    int rangeFreq(int l, int r, T\
    \ vmin, T vsup)\n    {\n        assert(0 <= l and l <= r and r <= m_n);\n    \
    \    return less(r, vsup) - less(r, vmin) - less(l, vsup) + less(l, vmin);\n \
    \   }\n    T quantile(int l, int r, int k)\n    {\n        assert(0 <= l and l\
    \ <= r and r <= m_n);\n        assert(0 <= k and k < r - l);\n        T ans =\
    \ 0;\n        for (int bi : per(m_lg)) {\n            const int z = m_bvs[bi].zero();\n\
    \            const int zl = m_bvs[bi].rank0(l);\n            const int zr = m_bvs[bi].rank0(r);\n\
    \            if (zr - zl <= k) {\n                ans |= (T{1} << bi);\n     \
    \           k -= (zr - zl);\n                l = z + m_bvs[bi].rank1(l), r = z\
    \ + m_bvs[bi].rank1(r);\n            } else {\n                l = zl, r = zr;\n\
    \            }\n        }\n        return ans;\n    }\nprivate:\n    int less(int\
    \ i, T v)\n    {\n        assert(0 <= i and i <= m_n);\n        int ans = 0;\n\
    \        for (int bi : per(m_lg)) {\n            if (btest(v, bi)) {\n       \
    \         const int z = m_bvs[bi].rank0(i);\n                const int o = i -\
    \ z;\n                ans += z;\n                i = m_bvs[bi].zero() + o;\n \
    \           } else {\n                i = m_bvs[bi].rank0(i);\n            }\n\
    \        }\n        return ans;\n    }\n    int m_n;\n    int m_lg;\n    Vec<BitVector>\
    \ m_bvs;\n};\n#pragma region FastIO Printer\nclass Printer\n{\npublic:\n    Printer()\
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
    template<typename T, typename F>\nT binSearch(T ng, T ok, F check)\n{\n    while\
    \ (std::abs(ok - ng) > 1) {\n        const T mid = (ok + ng) / 2;\n        (check(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\nint main()\n{\n    const auto N\
    \ = in.val<int>();\n    auto as = in.vec<i64>(N);\n    Vec<i64> ls(N), rs(N);\n\
    \    for (int i : rep(N)) {\n        std::tie(ls[i], rs[i]) = in.tup<i64, i64>();\n\
    \    }\n    auto is = iotaVec(N);\n    sortAll(is, [&](int i, int j) { return\
    \ as[i] < as[j]; });\n    constexpr i64 L = TEN<i64>(9);\n    Vec<i64> bs = as;\n\
    \    for (int i : rep(N)) {\n        bs[i] = as[is[i]] - ls[is[i]] + L;\n    }\n\
    \    auto wm = WaveletMatrix(bs, 31);\n    i64 ans = 0;\n    for (int i : rep(N\
    \ - 1)) {\n        const int jsup = binSearch(\n            i, N, [&](int j) {\
    \ return as[is[i]] + rs[is[i]] < as[is[j]]; });\n        ans += wm.rangeFreq(i\
    \ + 1, jsup, 0, as[is[i]] + L + 1);\n    }\n    out.ln(ans);\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/1937\"\n#include \"../../src/data_structure/wavelet.hpp\"\
    \n#include \"../../src/misc/fastio/printer.hpp\"\n#include \"../../src/misc/fastio/scanner.hpp\"\
    \n#include \"../../src/misc/bin_search.hpp\"\nint main()\n{\n    const auto N\
    \ = in.val<int>();\n    auto as = in.vec<i64>(N);\n    Vec<i64> ls(N), rs(N);\n\
    \    for (int i : rep(N)) {\n        std::tie(ls[i], rs[i]) = in.tup<i64, i64>();\n\
    \    }\n\n    auto is = iotaVec(N);\n    sortAll(is, [&](int i, int j) { return\
    \ as[i] < as[j]; });\n    constexpr i64 L = TEN<i64>(9);\n    Vec<i64> bs = as;\n\
    \    for (int i : rep(N)) {\n        bs[i] = as[is[i]] - ls[is[i]] + L;\n    }\n\
    \    auto wm = WaveletMatrix(bs, 31);\n\n    i64 ans = 0;\n    for (int i : rep(N\
    \ - 1)) {\n        const int jsup = binSearch(\n            i, N, [&](int j) {\
    \ return as[is[i]] + rs[is[i]] < as[is[j]]; });\n        ans += wm.rangeFreq(i\
    \ + 1, jsup, 0, as[is[i]] + L + 1);\n    }\n    out.ln(ans);\n    return 0;\n\
    }\n"
  dependsOn:
  - src/data_structure/wavelet.hpp
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
  - src/data_structure/bit_vector.hpp
  - src/misc/fastio/printer.hpp
  - src/misc/fastio/scanner.hpp
  - src/misc/bin_search.hpp
  isVerificationFile: true
  path: verifications/data_structure/wavelet.rangefreq.test.cpp
  requiredBy: []
  timestamp: '2021-06-13 23:28:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/data_structure/wavelet.rangefreq.test.cpp
layout: document
redirect_from:
- /verify/verifications/data_structure/wavelet.rangefreq.test.cpp
- /verify/verifications/data_structure/wavelet.rangefreq.test.cpp.html
title: verifications/data_structure/wavelet.rangefreq.test.cpp
---
