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
  - icon: ':question:'
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
  - icon: ':question:'
    path: src/misc/common/print/int128_t.hpp
    title: src/misc/common/print/int128_t.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/rng.hpp
    title: src/misc/common/rng.hpp
  - icon: ':question:'
    path: src/misc/common/show.hpp
    title: src/misc/common/show.hpp
  - icon: ':question:'
    path: src/misc/common/type_alias.hpp
    title: src/misc/common/type_alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/vec_utils.hpp
    title: src/misc/common/vec_utils.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/common/xoshiro.hpp
    title: src/misc/common/xoshiro.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifications/ds/li_chao_tree.line.test.cpp
    title: verifications/ds/li_chao_tree.line.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifications/ds/li_chao_tree.segment.test.cpp
    title: verifications/ds/li_chao_tree.segment.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ false;\n    }\n}\ntemplate<typename T>\nconstexpr T floorDiv(T x, T y)\n{\n\
    \    if (y < T{}) { x = -x, y = -y; }\n    return x >= T{} ? x / y : (x - y +\
    \ 1) / y;\n}\ntemplate<typename T>\nconstexpr T ceilDiv(T x, T y)\n{\n    if (y\
    \ < T{}) { x = -x, y = -y; }\n    return x >= T{} ? (x + y - 1) / y : x / y;\n\
    }\ntemplate<typename T, typename I>\nconstexpr T modPower(T v, I n, T mod)\n{\n\
    \    T ans = 1 % mod;\n    for (; n > 0; n >>= 1, (v *= v) %= mod) {\n       \
    \ if (n % 2 == 1) { (ans *= v) %= mod; }\n    }\n    return ans;\n}\ntemplate<typename\
    \ T, typename I>\nconstexpr T power(T v, I n)\n{\n    T ans = 1;\n    for (; n\
    \ > 0; n >>= 1, v *= v) {\n        if (n % 2 == 1) { ans *= v; }\n    }\n    return\
    \ ans;\n}\ntemplate<typename T, typename I>\nconstexpr T power(T v, I n, const\
    \ T& e)\n{\n    T ans = e;\n    for (; n > 0; n >>= 1, v *= v) {\n        if (n\
    \ % 2 == 1) { ans *= v; }\n    }\n    return ans;\n}\ntemplate<typename T>\nVec<T>\
    \ operator+=(Vec<T>& vs1, const Vec<T>& vs2)\n{\n    vs1.insert(vs1.end(), vs2.begin(),\
    \ vs2.end());\n    return vs1;\n}\ntemplate<typename T>\nVec<T> operator+(const\
    \ Vec<T>& vs1, const Vec<T>& vs2)\n{\n    auto vs = vs1;\n    vs += vs2;\n   \
    \ return vs;\n}\ntemplate<typename T>\nvoid fillAll(Vec<T>& vs, const T& v)\n\
    {\n    std::fill(vs.begin(), vs.end(), v);\n}\ntemplate<typename T, typename C\
    \ = Lt<T>>\nvoid sortAll(Vec<T>& vs, C comp = C{})\n{\n    std::sort(vs.begin(),\
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
    \ T>\nclass LiChaoTree\n{\n    using L = Pair<T, T>;\n    static constexpr L NIL\
    \ = {0, INF<T>};\n    struct Node\n    {\n        L line = NIL;\n        Arr<int,\
    \ 2> sons{-1, -1};\n    };\n    static bool comp(const L& l1, const L& l2, T x)\n\
    \    {\n        if (l1 == NIL or l2 == NIL) { return l2 == NIL; }\n        const\
    \ auto& [a1, b1] = l1;\n        const auto& [a2, b2] = l2;\n        if (a1 ==\
    \ a2) {\n            return b1 <= b2;\n        } else if (a1 > a2) {\n       \
    \     return x <= floorDiv(b2 - b1, a1 - a2);\n        } else {\n            return\
    \ floorDiv(b1 - b2, a2 - a1) < x;\n        }\n    }\npublic:\n    LiChaoTree(T\
    \ xmin, T xsup) : m_xmin{xmin}, m_xsup{xsup}, m_nodes{Node{}}\n    {\n       \
    \ assert(m_xmin < m_xsup);\n    }\n    void addLine(const L& line)\n    {\n  \
    \      add(line, 0, m_xmin, m_xsup);\n    }\n    void addSeg(const L& line, T\
    \ x_left, T x_right)\n    {\n        if (x_left >= x_right) { return; }\n    \
    \    assert(m_xmin <= x_left and x_right <= m_xsup);\n        Fix([&](auto dfs,\
    \ int i, T lx, T rx) -> void {\n            if (x_left <= lx and rx <= x_right)\
    \ {\n                add(line, i, lx, rx);\n            } else {\n           \
    \     if (rx - lx == 1) { return; }\n                auto [li, ri] = m_nodes[i].sons;\n\
    \                const T mx = (lx + rx) / 2;\n                if (lx < x_right\
    \ and x_left < mx) {\n                    if (li == -1) { li = m_nodes[i].sons[0]\
    \ = alloc(); }\n                    dfs(li, lx, mx);\n                }\n    \
    \            if (mx < x_right and x_left < rx) {\n                    if (ri ==\
    \ -1) { ri = m_nodes[i].sons[1] = alloc(); }\n                    dfs(ri, mx,\
    \ rx);\n                }\n            }\n        })(0, m_xmin, m_xsup);\n   \
    \ }\n    Pair<bool, L> minLine(const T x) const\n    {\n        T lx = m_xmin,\
    \ rx = m_xsup;\n        L ans = NIL;\n        for (int i = 0; i != -1;) {\n  \
    \          const auto& pl = m_nodes[i].line;\n            if (pl != NIL) {\n \
    \               if (comp(pl, ans, x)) { ans = pl; }\n            }\n         \
    \   const auto& [li, ri] = m_nodes[i].sons;\n            const T mx = (lx + rx)\
    \ / 2;\n            if (x < mx) {\n                i = li;\n                rx\
    \ = mx;\n            } else {\n                i = ri;\n                lx = mx;\n\
    \            }\n        }\n        return {ans != NIL, ans};\n    }\nprivate:\n\
    \    void add(L l, int i, T lx, T rx)\n    {\n        for (;;) {\n           \
    \ const auto& pl = m_nodes[i].line;\n            const T mx = (lx + rx) / 2;\n\
    \            const bool lunder = comp(l, pl, lx);\n            const bool runder\
    \ = comp(l, pl, rx - 1);\n            const bool munder = comp(l, pl, mx);\n \
    \           if (munder) { std::swap(l, m_nodes[i].line); }\n            if (lunder\
    \ == runder) { break; }\n            int dir = (lunder == munder ? 1 : 0);\n \
    \           int nind = m_nodes[i].sons[dir];\n            if (nind == -1) { nind\
    \ = m_nodes[i].sons[dir] = alloc(); }\n            i = nind;\n            if (rx\
    \ - lx == 1) { break; }\n            if (lunder == munder) {\n               \
    \ lx = mx;\n            } else {\n                rx = mx;\n            }\n  \
    \      }\n    }\n    int alloc()\n    {\n        m_nodes.push_back(Node{});\n\
    \        return (int)m_nodes.size() - 1;\n    }\n    T m_xmin, m_xsup;\n    Vec<Node>\
    \ m_nodes;\n};\n"
  code: "#pragma once\n#include \"../misc/common.hpp\"\ntemplate<typename T>\nclass\
    \ LiChaoTree\n{\n    using L = Pair<T, T>;\n    static constexpr L NIL = {0, INF<T>};\n\
    \    struct Node\n    {\n        L line = NIL;\n        Arr<int, 2> sons{-1, -1};\n\
    \    };\n    static bool comp(const L& l1, const L& l2, T x)\n    {\n        if\
    \ (l1 == NIL or l2 == NIL) { return l2 == NIL; }\n        const auto& [a1, b1]\
    \ = l1;\n        const auto& [a2, b2] = l2;\n        if (a1 == a2) {\n       \
    \     return b1 <= b2;\n        } else if (a1 > a2) {\n            return x <=\
    \ floorDiv(b2 - b1, a1 - a2);\n        } else {\n            return floorDiv(b1\
    \ - b2, a2 - a1) < x;\n        }\n    }\n\npublic:\n    LiChaoTree(T xmin, T xsup)\
    \ : m_xmin{xmin}, m_xsup{xsup}, m_nodes{Node{}}\n    {\n        assert(m_xmin\
    \ < m_xsup);\n    }\n    void addLine(const L& line)\n    {\n        add(line,\
    \ 0, m_xmin, m_xsup);\n    }\n    void addSeg(const L& line, T x_left, T x_right)\n\
    \    {\n        if (x_left >= x_right) { return; }\n        assert(m_xmin <= x_left\
    \ and x_right <= m_xsup);\n        Fix([&](auto dfs, int i, T lx, T rx) -> void\
    \ {\n            if (x_left <= lx and rx <= x_right) {\n                add(line,\
    \ i, lx, rx);\n            } else {\n                if (rx - lx == 1) { return;\
    \ }\n                auto [li, ri] = m_nodes[i].sons;\n                const T\
    \ mx = (lx + rx) / 2;\n                if (lx < x_right and x_left < mx) {\n \
    \                   if (li == -1) { li = m_nodes[i].sons[0] = alloc(); }\n   \
    \                 dfs(li, lx, mx);\n                }\n                if (mx\
    \ < x_right and x_left < rx) {\n                    if (ri == -1) { ri = m_nodes[i].sons[1]\
    \ = alloc(); }\n                    dfs(ri, mx, rx);\n                }\n    \
    \        }\n        })(0, m_xmin, m_xsup);\n    }\n    Pair<bool, L> minLine(const\
    \ T x) const\n    {\n        T lx = m_xmin, rx = m_xsup;\n        L ans = NIL;\n\
    \        for (int i = 0; i != -1;) {\n            const auto& pl = m_nodes[i].line;\n\
    \            if (pl != NIL) {\n                if (comp(pl, ans, x)) { ans = pl;\
    \ }\n            }\n            const auto& [li, ri] = m_nodes[i].sons;\n    \
    \        const T mx = (lx + rx) / 2;\n            if (x < mx) {\n            \
    \    i = li;\n                rx = mx;\n            } else {\n               \
    \ i = ri;\n                lx = mx;\n            }\n        }\n        return\
    \ {ans != NIL, ans};\n    }\n\nprivate:\n    void add(L l, int i, T lx, T rx)\n\
    \    {\n        for (;;) {\n            const auto& pl = m_nodes[i].line;\n  \
    \          const T mx = (lx + rx) / 2;\n            const bool lunder = comp(l,\
    \ pl, lx);\n            const bool runder = comp(l, pl, rx - 1);\n           \
    \ const bool munder = comp(l, pl, mx);\n            if (munder) { std::swap(l,\
    \ m_nodes[i].line); }\n            if (lunder == runder) { break; }\n        \
    \    int dir = (lunder == munder ? 1 : 0);\n            int nind = m_nodes[i].sons[dir];\n\
    \            if (nind == -1) { nind = m_nodes[i].sons[dir] = alloc(); }\n    \
    \        i = nind;\n            if (rx - lx == 1) { break; }\n            if (lunder\
    \ == munder) {\n                lx = mx;\n            } else {\n             \
    \   rx = mx;\n            }\n        }\n    }\n    int alloc()\n    {\n      \
    \  m_nodes.push_back(Node{});\n        return (int)m_nodes.size() - 1;\n    }\n\
    \    T m_xmin, m_xsup;\n    Vec<Node> m_nodes;\n};\n"
  dependsOn:
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
  isVerificationFile: false
  path: src/ds/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2021-09-03 16:07:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifications/ds/li_chao_tree.segment.test.cpp
  - verifications/ds/li_chao_tree.line.test.cpp
documentation_of: src/ds/li_chao_tree.hpp
layout: document
title: Li Chao Tree
---

## 概要

線分 $s _ i(x): y = a _ i x + b _ i (l _ i \le x \lt r _ i)$ の集合 $\mathcal{S}$ について以下の操作を $\mathrm{O}(\log N)$ で行う。

- 線分追加: $\mathcal{S} \leftarrow \mathcal{S} \cup \lbrace s:y=ax+b (l \le x \le r) \rbrace$
- 最小値取得: $\mathrm{argmin}_{l \in \mathcal{S}}\ l(x)$

## I/F

### コンストラクタ

```cpp
LiChaoTree<T, V> cht(T xmin, T xsup)
```

- `T`: $x$ 座標, 傾き, $y$ 切片の型
- `xmin`,`xsup`: クエリ $x$ 座標の上限下限($x _ {min} \le x \lt x _ {sup}$ を満たす)

以下 $X = x _ {sup} - x _ {min}$

#### 計算量

$\mathrm{O}(1)$

### addLine

```cpp
void cht.addLine(T a, T b)
```

$\mathcal{S}$ に直線 $l: y=ax+b$ を追加

#### 計算量

$\mathrm{O}(\log X)$

### addSeg

```cpp
void cht.addSeg(T a, T b, T xl, T xr)
```

$\mathcal{S}$ に線分 $s: y=ax+b (x _ l \le x \lt x _ r)$ を追加

#### 計算量

$\mathrm{O}(\log^2 X)$

### minLine

```cpp
Pair<bool,L> cht.minLine(T x)
```

$\mathrm{argmin}_{s \in \mathcal{S}}\ s(x)$ を取得  

- 返り値の`first`は $x$ 上に線分があるかどうか
- 返り値の`second`は (線分の傾き, 線分の$y$切片) のペア

#### 計算量

$\mathrm{O}(\log X)$
