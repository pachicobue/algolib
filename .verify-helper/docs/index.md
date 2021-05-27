# AlgoLib

競プロライブラリ  
C++17を前提にしています。

## 型エイリアス

ドキュメントでも以下のエイリアスを使う

### 値型

```cpp
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

using f64 = double;
using f80 = long double;
using f128 = __float128;

using Str = std::string;
using Pair = std::pair;
using Tup = std::tuple;
```

### コンテナ型

```cpp
using Set = std::set;
using Map = std::map;
using Vec = std::vector;
```

### その他

```cpp
using NSec = std::chrono::nanoseconds;
using USec = std::chrono::microseconds;
using MSec = std::chrono::milliseconds;
using Sec = std::chrono::seconds;
```
