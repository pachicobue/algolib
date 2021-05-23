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
  - icon: ':heavy_check_mark:'
    path: src/misc/printer.hpp
    title: "Printer (\u51FA\u529B\u88DC\u52A9\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: src/misc/scanner.hpp
    title: "Scanner (\u5165\u529B\u88DC\u52A9\u30AF\u30E9\u30B9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#include <bits/stdc++.h>\n#pragma region Macros\n#pragma endregion\n\
    #pragma region TypeAlias\nusing i32 = int;\nusing u32 = unsigned int;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\nusing f64 = double;\nusing f80 = long double;\nusing f128\
    \ = __float128;\nconstexpr i32 operator\"\" _i32(u64 v)\n{\n    return v;\n}\n\
    constexpr i32 operator\"\" _u32(u64 v)\n{\n    return v;\n}\nconstexpr i64 operator\"\
    \" _i64(u64 v)\n{\n    return v;\n}\nconstexpr u64 operator\"\" _u64(u64 v)\n\
    {\n    return v;\n}\nconstexpr f64 operator\"\" _f64(f80 v)\n{\n    return v;\n\
    }\nconstexpr f80 operator\"\" _f80(f80 v)\n{\n    return v;\n}\nusing Istream\
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
    #pragma region Printer\nclass Printer\n{\npublic:\n    Printer(Ostream& os = std::cout)\
    \ : m_os{os}\n    {\n        m_os << std::fixed << std::setprecision(15);\n  \
    \  }\n    template<typename... Args>\n    int operator()(const Args&... args)\n\
    \    {\n        dump(args...);\n        return 0;\n    }\n    template<typename...\
    \ Args>\n    int ln(const Args&... args)\n    {\n        dump(args...), m_os <<\
    \ '\\n';\n        return 0;\n    }\n    template<typename... Args>\n    int el(const\
    \ Args&... args)\n    {\n        dump(args...), m_os << std::endl;\n        return\
    \ 0;\n    }\nprivate:\n    template<typename T>\n    void dump(const T& v)\n \
    \   {\n        m_os << v;\n    }\n    template<typename T>\n    void dump(const\
    \ Vec<T>& vs)\n    {\n        for (const int i : rep(vs.size())) {\n         \
    \   m_os << (i ? \" \" : \"\"), dump(vs[i]);\n        }\n    }\n    template<typename\
    \ T>\n    void dump(const Vec<Vec<T>>& vss)\n    {\n        for (const int i :\
    \ rep(vss.size())) {\n            m_os << (i ? \"\" : \"\\n\"), dump(vss[i]);\n\
    \        }\n    }\n    template<typename T, typename... Ts>\n    int dump(const\
    \ T& v, const Ts&... args)\n    {\n        dump(v), m_os << ' ', dump(args...);\n\
    \        return 0;\n    }\n    Ostream& m_os;\n};\nPrinter out;\n#pragma endregion\n\
    #pragma region Scanner\nclass Scanner\n{\npublic:\n    Scanner(Istream& is = std::cin)\
    \ : m_is{is}\n    {\n        m_is.tie(nullptr)->sync_with_stdio(false);\n    }\n\
    \    template<typename T>\n    T val()\n    {\n        T v;\n        return m_is\
    \ >> v, v;\n    }\n    template<typename T>\n    T val(T offset)\n    {\n    \
    \    return val<T>() - offset;\n    }\n    template<typename T>\n    Vec<T> vec(int\
    \ n)\n    {\n        return genVec<T>(n, [&]() { return val<T>(); });\n    }\n\
    \    template<typename T>\n    Vec<T> vec(int n, T offset)\n    {\n        return\
    \ genVec<T>(n, [&]() { return val<T>(offset); });\n    }\n    template<typename\
    \ T>\n    Vec<Vec<T>> vvec(int n, int m)\n    {\n        return genVec<Vec<T>>(n,\
    \ [&]() { return vec<T>(m); });\n    }\n    template<typename T>\n    Vec<Vec<T>>\
    \ vvec(int n, int m, const T offset)\n    {\n        return genVec<Vec<T>>(n,\
    \ [&]() { return vec<T>(m, offset); });\n    }\n    template<typename... Args>\n\
    \    auto tup()\n    {\n        return Tup<Args...>{val<Args>()...};\n    }\n\
    \    template<typename... Args>\n    auto tup(const Args&... offsets)\n    {\n\
    \        return Tup<Args...>{val<Args>(offsets)...};\n    }\nprivate:\n    Istream&\
    \ m_is;\n};\nScanner in;\n#pragma endregion\nconstexpr i64 mod = 1000000007;\n\
    int main()\n{\n    const auto [m, n] = in.tup<i64, i64>();\n    const i64 ans\
    \ = modPower(m, n, mod);\n    out.ln(ans);\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n#include \"../../../src/misc/common.hpp\"\n#include \"../../../src/misc/printer.hpp\"\
    \n#include \"../../../src/misc/scanner.hpp\"\n\nconstexpr i64 mod = 1000000007;\n\
    \nint main()\n{\n    const auto [m, n] = in.tup<i64, i64>();\n    const i64 ans\
    \ = modPower(m, n, mod);\n    out.ln(ans);\n    return 0;\n}\n"
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
  - src/misc/printer.hpp
  - src/misc/scanner.hpp
  isVerificationFile: true
  path: verifications/misc/common/func_alias.mod_power.test.cpp
  requiredBy: []
  timestamp: '2021-05-24 03:23:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/misc/common/func_alias.mod_power.test.cpp
layout: document
redirect_from:
- /verify/verifications/misc/common/func_alias.mod_power.test.cpp
- /verify/verifications/misc/common/func_alias.mod_power.test.cpp.html
title: verifications/misc/common/func_alias.mod_power.test.cpp
---
