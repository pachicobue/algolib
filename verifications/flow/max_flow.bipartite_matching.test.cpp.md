---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/flow/max_flow.hpp
    title: src/flow/max_flow.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
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
    \ T>\nclass MaxFlow\n{\n    struct Edge\n    {\n        int to;\n        T cap;\n\
    \        T flow;\n        int rid;\n        Edge() = default;\n        Edge(int\
    \ t, T c, T f, int r) : to{t}, cap{c}, flow{f}, rid{r} {}\n        T resCap()\
    \ const\n        {\n            return cap - flow;\n        }\n    };\npublic:\n\
    \    MaxFlow(int n) : m_v(n), m_ds(n, -1)\n    {\n        m_is[0].resize(n);\n\
    \        m_is[1].resize(n);\n        m_gs[0].resize(n);\n        m_gs[1].resize(n);\n\
    \    }\n    void addEdge(int from, int to, T cap)\n    {\n        assert(0 <=\
    \ from and from < m_v);\n        assert(0 <= to and to < m_v);\n        assert(0\
    \ <= cap);\n        int id = m_gs[0][from].size();\n        int rid = m_gs[1][to].size();\n\
    \        m_gs[0][from].emplace_back(to, cap, 0, rid);\n        m_gs[1][to].emplace_back(from,\
    \ cap, cap, id);\n        m_es.emplace_back(from, id);\n    }\n    const Edge&\
    \ edge(int i) const\n    {\n        const auto& [u, id] = m_es[i];\n        return\
    \ m_gs[0][u][id];\n    }\n    T maxFlow(int s, int t, T max_flow = INF<T>)\n \
    \   {\n        auto bfs = [&]() {\n            fillAll(m_ds, -1);\n          \
    \  Queue<int> q;\n            m_ds[s] = 0, q.push(s);\n            while (not\
    \ q.empty()) {\n                const int u = q.front();\n                q.pop();\n\
    \                for (int l : rep(2)) {\n                    for (const auto&\
    \ e : m_gs[l][u]) {\n                        if (e.resCap() > 0 and m_ds[e.to]\
    \ == -1) {\n                            m_ds[e.to] = m_ds[u] + 1;\n          \
    \                  q.push(e.to);\n                        }\n                \
    \    }\n                }\n            }\n        };\n        auto dfs = Fix([&](auto\
    \ dfs, int u, T fmax) -> T {\n            if (u == t) { return fmax; }\n     \
    \       for (int l : rep(2)) {\n                for (int& i = m_is[l][u]; i <\
    \ (int)m_gs[l][u].size(); i++) {\n                    auto& e = m_gs[l][u][i];\n\
    \                    if (e.resCap() > 0 and m_ds[u] < m_ds[e.to]) {\n        \
    \                const T d = dfs(e.to, std::min(fmax, e.resCap()));\n        \
    \                if (d > 0) {\n                            e.flow += d;\n    \
    \                        m_gs[1 - l][e.to][e.rid].flow -= d;\n               \
    \             return d;\n                        }\n                    }\n  \
    \              }\n            }\n            return 0;\n        });\n        T\
    \ flow = 0;\n        while (flow < max_flow) {\n            bfs();\n         \
    \   if (m_ds[t] == -1) { return flow; }\n            for (int l : rep(2)) {\n\
    \                fillAll(m_is[l], 0);\n            }\n            while (true)\
    \ {\n                T f = dfs(s, max_flow - flow);\n                if (f ==\
    \ 0) { break; }\n                flow += f;\n            }\n        }\n      \
    \  return flow;\n    }\n    Vec<Edge>& operator[](int i)\n    {\n        assert(0\
    \ <= i and i < m_v);\n        return m_gs[0][i];\n    }\n    const Vec<Edge>&\
    \ operator[](int i) const\n    {\n        assert(0 <= i and i < m_v);\n      \
    \  return m_gs[0][i];\n    }\n    int v() const\n    {\n        return m_v;\n\
    \    }\n    friend Ostream& operator<<(Ostream& os, const MaxFlow& mf)\n    {\n\
    \        const int N = mf.v();\n        os << \"[\\n\";\n        for (int u :\
    \ rep(N)) {\n            for (const auto& e : mf[u]) {\n                const\
    \ int v = e.to;\n                const T cap = e.cap, flow = e.flow;\n       \
    \         os << u << \"->\" << v << \" [\" << flow << \"/\" << cap << \"]\\n\"\
    ;\n            }\n        }\n        return (os << \"]\\n\");\n    }\nprivate:\n\
    \    int m_v;\n    Vec<int> m_ds;\n    Arr<Vec<int>, 2> m_is;\n    Vec<Pair<int,\
    \ int>> m_es;\n    Arr<Vec<Vec<Edge>>, 2> m_gs;\n};\nclass Printer\n{\npublic:\n\
    \    Printer(Ostream& os = std::cout) : m_os{os}\n    {\n        m_os << std::fixed\
    \ << std::setprecision(15);\n    }\n    template<typename... Args>\n    int operator()(const\
    \ Args&... args)\n    {\n        dump(args...);\n        return 0;\n    }\n  \
    \  template<typename... Args>\n    int ln(const Args&... args)\n    {\n      \
    \  dump(args...), m_os << '\\n';\n        return 0;\n    }\n    template<typename...\
    \ Args>\n    int el(const Args&... args)\n    {\n        dump(args...), m_os <<\
    \ std::endl;\n        return 0;\n    }\nprivate:\n    template<typename T>\n \
    \   void dump(const T& v)\n    {\n        m_os << v;\n    }\n    template<typename\
    \ T>\n    void dump(const Vec<T>& vs)\n    {\n        for (const int i : rep(vs.size()))\
    \ {\n            m_os << (i ? \" \" : \"\"), dump(vs[i]);\n        }\n    }\n\
    \    template<typename T>\n    void dump(const Vec<Vec<T>>& vss)\n    {\n    \
    \    for (const int i : rep(vss.size())) {\n            m_os << (i ? \"\\n\" :\
    \ \"\"), dump(vss[i]);\n        }\n    }\n    template<typename T, typename...\
    \ Ts>\n    int dump(const T& v, const Ts&... args)\n    {\n        dump(v), m_os\
    \ << ' ', dump(args...);\n        return 0;\n    }\n    Ostream& m_os;\n};\nPrinter\
    \ out;\nclass Scanner\n{\npublic:\n    Scanner(Istream& is = std::cin) : m_is{is}\n\
    \    {\n        m_is.tie(nullptr)->sync_with_stdio(false);\n    }\n    template<typename\
    \ T>\n    T val()\n    {\n        T v;\n        return m_is >> v, v;\n    }\n\
    \    template<typename T>\n    T val(T offset)\n    {\n        return val<T>()\
    \ - offset;\n    }\n    template<typename T>\n    Vec<T> vec(int n)\n    {\n \
    \       return genVec<T>(n, [&]() { return val<T>(); });\n    }\n    template<typename\
    \ T>\n    Vec<T> vec(int n, T offset)\n    {\n        return genVec<T>(n, [&]()\
    \ { return val<T>(offset); });\n    }\n    template<typename T>\n    Vec<Vec<T>>\
    \ vvec(int n, int m)\n    {\n        return genVec<Vec<T>>(n, [&]() { return vec<T>(m);\
    \ });\n    }\n    template<typename T>\n    Vec<Vec<T>> vvec(int n, int m, const\
    \ T offset)\n    {\n        return genVec<Vec<T>>(n, [&]() { return vec<T>(m,\
    \ offset); });\n    }\n    template<typename... Args>\n    auto tup()\n    {\n\
    \        return Tup<Args...>{val<Args>()...};\n    }\n    template<typename...\
    \ Args>\n    auto tup(const Args&... offsets)\n    {\n        return Tup<Args...>{val<Args>(offsets)...};\n\
    \    }\nprivate:\n    Istream& m_is;\n};\nScanner in;\nint main()\n{\n    const\
    \ auto [L, R, M] = in.tup<int, int, int>();\n    MaxFlow<int> flow(L + R + 2);\n\
    \    const int S = L + R, T = L + R + 1;\n    for (int i : rep(M)) {\n       \
    \ static_cast<void>(i);\n        const auto [u, v] = in.tup<int, int>();\n   \
    \     flow.addEdge(u, v + L, 1);\n    }\n    for (int i : rep(L)) {\n        flow.addEdge(S,\
    \ i, 1);\n    }\n    for (int i : rep(R)) {\n        flow.addEdge(i + L, T, 1);\n\
    \    }\n    const int K = flow.maxFlow(S, T);\n    out.ln(K);\n    for (int i\
    \ : rep(L)) {\n        for (const auto& e : flow[i]) {\n            if (e.flow\
    \ == 1) { out.ln(i, e.to - L); }\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ \"../../src/flow/max_flow.hpp\"\n#include \"../../src/misc/printer.hpp\"\n#include\
    \ \"../../src/misc/scanner.hpp\"\nint main()\n{\n    const auto [L, R, M] = in.tup<int,\
    \ int, int>();\n    MaxFlow<int> flow(L + R + 2);\n    const int S = L + R, T\
    \ = L + R + 1;\n    for (int i : rep(M)) {\n        USE(i);\n        const auto\
    \ [u, v] = in.tup<int, int>();\n        flow.addEdge(u, v + L, 1);\n    }\n  \
    \  for (int i : rep(L)) {\n        flow.addEdge(S, i, 1);\n    }\n    for (int\
    \ i : rep(R)) {\n        flow.addEdge(i + L, T, 1);\n    }\n    const int K =\
    \ flow.maxFlow(S, T);\n    out.ln(K);\n    for (int i : rep(L)) {\n        for\
    \ (const auto& e : flow[i]) {\n            if (e.flow == 1) { out.ln(i, e.to -\
    \ L); }\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - src/flow/max_flow.hpp
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
  - src/misc/printer.hpp
  - src/misc/scanner.hpp
  isVerificationFile: true
  path: verifications/flow/max_flow.bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2021-09-02 11:14:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifications/flow/max_flow.bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/verifications/flow/max_flow.bipartite_matching.test.cpp
- /verify/verifications/flow/max_flow.bipartite_matching.test.cpp.html
title: verifications/flow/max_flow.bipartite_matching.test.cpp
---
