---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segtree.hpp
    title: src/data_structure/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: src/graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/hld.hpp
    title: src/graph/hld.hpp
  - icon: ':question:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
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
    path: src/misc/common/macros.hpp
    title: src/misc/common/macros.hpp
  - icon: ':question:'
    path: src/misc/common/nd_vec.hpp
    title: src/misc/common/nd_vec.hpp
  - icon: ':question:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
  - icon: ':question:'
    path: src/misc/common/range.hpp
    title: src/misc/common/range.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
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
    template<typename MergeMonoid>\nclass SegTree\n{\n    using T = typename MergeMonoid::T;\n\
    \    static constexpr T e()\n    {\n        return MergeMonoid::e();\n    }\n\
    public:\n    SegTree(const Vec<T>& vs)\n        : m_size(vs.size()),\n       \
    \   m_half(ceil2(m_size)),\n          m_vals(m_half << 1, MergeMonoid::e())\n\
    \    {\n        std::copy(vs.begin(), vs.end(), m_vals.begin() + m_half);\n  \
    \      for (int i = m_half - 1; i >= 1; i--) {\n            up(i);\n        }\n\
    \    }\n    T get(int i) const\n    {\n        assert(0 <= i and i < m_size);\n\
    \        return m_vals[i + m_half];\n    }\n    void set(int i, const T& v)\n\
    \    {\n        assert(0 <= i and i < m_size);\n        m_vals[i += m_half] =\
    \ v;\n        while (i >>= 1) {\n            up(i);\n        }\n    }\n    T fold(int\
    \ l, int r) const\n    {\n        assert(0 <= l and l <= r and r <= m_size);\n\
    \        T lv = e(), rv = e();\n        int li = l + m_half, ri = r + m_half;\n\
    \        for (; li < ri; li >>= 1, ri >>= 1) {\n            if (li & 1) { lv =\
    \ merge(lv, m_vals[li++]); }\n            if (ri & 1) { rv = merge(m_vals[--ri],\
    \ rv); }\n        }\n        return merge(lv, rv);\n    }\n    friend Ostream&\
    \ operator<<(Ostream& os, const SegTree& seg)\n    {\n        os << \"[\";\n \
    \       for (int i : rep(seg.m_size)) {\n            os << (i == 0 ? \"\" : \"\
    ,\") << seg.m_vals[i + seg.m_half];\n        }\n        return (os << \"]\");\n\
    \    }\nprivate:\n    void up(int i)\n    {\n        m_vals[i] = merge(m_vals[i\
    \ << 1], m_vals[i << 1 | 1]);\n    }\n    int m_size, m_half;\n    Vec<T> m_vals;\n\
    \    static inline MergeMonoid merge;\n};\ntemplate<typename T = int>\nclass Graph\n\
    {\n    struct Edge\n    {\n        Edge() = default;\n        Edge(int i, int\
    \ t, T c) : id{i}, to{t}, cost{c} {}\n        int id;\n        int to;\n     \
    \   T cost;\n        operator int() const\n        {\n            return to;\n\
    \        }\n    };\npublic:\n    Graph(int n) : m_v{n}, m_edges(n) {}\n    void\
    \ addEdge(int u, int v, bool bi = false)\n    {\n        assert(0 <= u and u <\
    \ m_v);\n        assert(0 <= v and v < m_v);\n        m_edges[u].emplace_back(m_e,\
    \ v, 1);\n        if (bi) { m_edges[v].emplace_back(m_e, u, 1); }\n        m_e++;\n\
    \    }\n    void addEdge(int u, int v, const T& c, bool bi = false)\n    {\n \
    \       assert(0 <= u and u < m_v);\n        assert(0 <= v and v < m_v);\n   \
    \     m_edges[u].emplace_back(m_e, v, c);\n        if (bi) { m_edges[v].emplace_back(m_e,\
    \ u, c); }\n        m_e++;\n    }\n    const Vec<Edge>& operator[](const int u)\
    \ const\n    {\n        assert(0 <= u and u < m_v);\n        return m_edges[u];\n\
    \    }\n    Vec<Edge>& operator[](const int u)\n    {\n        assert(0 <= u and\
    \ u < m_v);\n        return m_edges[u];\n    }\n    int v() const\n    {\n   \
    \     return m_v;\n    }\n    int e() const\n    {\n        return m_e;\n    }\n\
    \    friend Ostream& operator<<(Ostream& os, const Graph& g)\n    {\n        for\
    \ (int u : rep(g.v())) {\n            for (const auto& [id, v, c] : g[u]) {\n\
    \                os << \"[\" << id << \"]: \";\n                os << u << \"\
    ->\" << v << \"(\" << c << \")\\n\";\n            }\n        }\n        return\
    \ os;\n    }\n    Vec<T> sizes(int root = 0) const\n    {\n        const int N\
    \ = v();\n        assert(0 <= root and root < N);\n        Vec<T> ss(N, 1);\n\
    \        Fixpoint([&](auto dfs, int u, int p) -> void {\n            for (const\
    \ auto& [id, v, c] : m_edges[u]) {\n                static_cast<void>(id);\n \
    \               if (v == p) { continue; }\n                dfs(v, u);\n      \
    \          ss[v] += ss[u];\n            }\n        })(root, -1);\n        return\
    \ ss;\n    }\n    Vec<T> depths(int root = 0) const\n    {\n        const int\
    \ N = v();\n        assert(0 <= root and root < N);\n        Vec<T> ds(N, 0);\n\
    \        Fixpoint([&](auto dfs, int u, int p) -> void {\n            for (const\
    \ auto& [id, v, c] : m_edges[u]) {\n                static_cast<void>(id);\n \
    \               if (v == p) { continue; }\n                ds[v] = ds[u] + c;\n\
    \                dfs(v, u);\n            }\n        })(root, -1);\n        return\
    \ ds;\n    }\n    Vec<int> parents(int root = 0) const\n    {\n        const int\
    \ N = v();\n        assert(0 <= root and root < N);\n        Vec<int> ps(N, -1);\n\
    \        Fixpoint([&](auto dfs, int u, int p) -> void {\n            for (const\
    \ auto& [id, v, c] : m_edges[u]) {\n                static_cast<void>(id);\n \
    \               if (v == p) { continue; }\n                ps[v] = u;\n      \
    \          dfs(v, u);\n            }\n        })(root, -1);\n        return ps;\n\
    \    }\nprivate:\n    int m_v;\n    int m_e = 0;\n    Vec<Vec<Edge>> m_edges;\n\
    };\ntemplate<typename T>\nclass HLD\n{\n    using P = Pair<int, int>;\npublic:\n\
    \    HLD(Graph<T>& g, int r = 0)\n        : m_v(g.v()),\n          m_ps(m_v, -1),\n\
    \          m_tops(m_v, -1),\n          m_ords(m_v, -1),\n          m_ins(m_v,\
    \ -1),\n          m_outs(m_v, -1)\n    {\n        const int N = g.v();\n     \
    \   Vec<int> szs(N, 1);\n        Fixpoint([&](auto dfs, int u, int p) -> int {\n\
    \            m_ps[u] = p;\n            for (int i : rep(g[u].size())) {\n    \
    \            const int v = g[u][i];\n                if (p == v) { continue; }\n\
    \                szs[u] += dfs(v, u);\n                if (szs[(int)g[u][0]] <\
    \ szs[v]) { std::swap(g[u][0], g[u][i]); }\n            }\n            return\
    \ szs[u];\n        })(r, -1);\n        m_tops[r] = r;\n        int index = 0;\n\
    \        Fixpoint([&](auto dfs, int u, int p) -> void {\n            m_ins[u]\
    \ = index++;\n            m_ords[m_ins[u]] = u;\n            for (int i : rep(g[u].size()))\
    \ {\n                const int v = g[u][i];\n                if (v == p) { continue;\
    \ }\n                if (i == 0) {\n                    m_tops[v] = m_tops[u];\n\
    \                } else {\n                    m_tops[v] = v;\n              \
    \  }\n                dfs(v, u);\n            }\n        })(r, -1);\n    }\n \
    \   int pos(int v) const\n    {\n        assert(0 <= v and v < m_v);\n       \
    \ return m_ins[v];\n    }\n    int at(int n) const\n    {\n        assert(0 <=\
    \ n and n < m_v);\n        return m_ords[n];\n    }\n    P sub(int v) const\n\
    \    {\n        assert(0 <= v and v < m_v);\n        return {m_ins[v], m_outs[v]};\n\
    \    }\n    Vec<P> path(int u, int v) const\n    {\n        assert(0 <= u and\
    \ u < m_v);\n        assert(0 <= v and v < m_v);\n        Vec<P> head, tail;\n\
    \        for (int pu = m_tops[u], pv = m_tops[v]; pu != pv;) {\n            if\
    \ (m_ins[pu] < m_ins[pv]) {\n                tail.push_back({m_ins[pv], m_ins[v]});\n\
    \                v = m_ps[pv];\n                pv = m_tops[v];\n            }\
    \ else {\n                head.push_back({m_ins[u], m_ins[pu]});\n           \
    \     u = m_ps[pu];\n                pu = m_tops[u];\n            }\n        }\n\
    \        head.push_back({m_ins[u], m_ins[v]});\n        reverseAll(tail);\n  \
    \      for (const auto& p : tail) {\n            head.push_back(p);\n        }\n\
    \        return head;\n    }\nprivate:\n    int m_v;\n    Vec<int> m_ps;\n   \
    \ Vec<int> m_tops;\n    Vec<int> m_ords;\n    Vec<int> m_ins, m_outs;\n};\ntemplate<u32\
    \ mod_, u32 root_, u32 max2p_>\nclass modint\n{\n    template<typename U = u32&>\n\
    \    static U modRef()\n    {\n        static u32 s_mod = 0;\n        return s_mod;\n\
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
    int main()\n{\n    using mint = modint_998244353;\n    const auto [N, Q] = in.tup<int,\
    \ int>();\n    Graph g(N);\n    using Func = Pair<mint, mint>;\n    struct Monoid\n\
    \    {\n        using T = Func;\n        static const T e()\n        {\n     \
    \       return T{1, 0};\n        }\n        T operator()(const T& f2, const T&\
    \ f1) const\n        {\n            return T{f1.first * f2.first, f1.first * f2.second\
    \ + f1.second};\n        }\n    };\n    struct RMonoid\n    {\n        using T\
    \ = Func;\n        static const T e()\n        {\n            return T{1, 0};\n\
    \        }\n        T operator()(const T& f1, const T& f2) const\n        {\n\
    \            return T{f1.first * f2.first, f1.first * f2.second + f1.second};\n\
    \        }\n    };\n    std::vector<mint> as(N), bs(N);\n    for (int i : rep(N))\
    \ {\n        std::tie(as[i], bs[i]) = in.tup<mint, mint>();\n    }\n    for (int\
    \ i : rep(N - 1)) {\n        const auto [u, v] = in.tup<int, int>();\n       \
    \ g.addEdge(u, v, true);\n    }\n    const HLD hld{g};\n    std::vector<Func>\
    \ vs(N);\n    for (int i : rep(N)) {\n        vs[hld.pos(i)] = Func{as[i], bs[i]};\n\
    \    }\n    auto seg = SegTree<Monoid>(vs);\n    auto rseg = SegTree<RMonoid>(vs);\n\
    \    for (int q : rep(Q)) {\n        const auto t = in.val<int>();\n        if\
    \ (t == 0) {\n            const auto [p, c, d] = in.tup<int, mint, mint>();\n\
    \            seg.set(hld.pos(p), {c, d}), rseg.set(hld.pos(p), {c, d});\n    \
    \    } else {\n            const auto [u, v, x] = in.tup<int, int, mint>();\n\
    \            const auto ps = hld.path(u, v);\n            Func f{1, 0};\n    \
    \        for (const auto& [a, b] : ps) {\n                f = Monoid{}(f,\n  \
    \                           a <= b ? seg.fold(a, b + 1) : rseg.fold(b, a + 1));\n\
    \            }\n            out.ln((f.first * x + f.second).val());\n        }\n\
    \    }\n    return 0;\n}\n"
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
  dependsOn:
  - src/data_structure/segtree.hpp
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
  - src/graph/hld.hpp
  - src/graph/graph.hpp
  - src/math/modint.hpp
  - src/misc/fastio/printer.hpp
  - src/misc/fastio/scanner.hpp
  isVerificationFile: true
  path: verifications/graph/hld.test.cpp
  requiredBy: []
  timestamp: '2021-05-24 03:04:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/graph/hld.test.cpp
layout: document
redirect_from:
- /verify/verifications/graph/hld.test.cpp
- /verify/verifications/graph/hld.test.cpp.html
title: verifications/graph/hld.test.cpp
---
