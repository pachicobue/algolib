---
title: Disjoint Sparse Table
documentation_of: //src/data_structure/ds_table.hpp
---

## Disjoint Sparse Table

半群 $(T, \ast)$ 上の要素数 $N$ の 数列 $A = \lbrack A_0, A_1, \dots , A_{N-1}\rbrack$ について、  
以下の操作が $\mathrm{O}(1)$ でできる。

- 範囲総積取得: $A_l \ast \dots \ast A_{r-1}$

### コンストラクタ

```cpp
ds_table<SemiGroup> ds(const Vec<T>& A)
```

数列 $A$ で初期化する

テンプレート引数`SemiGroup`は以下のようなフィールドを持つクラス

- `T`:型
- `operator()(T x1, T x2)`: $x_1 \ast xx_2$

```cpp
struct SemiGroup
{
    using T = int;
    T operator()(const T& x1, const T& x2) const { 
        return std::min(x1, x2); 
    }
};
```

#### 計算量

- $\mathrm{O}(N\log N)$

### add

$A _ i$ に $x$ を加算

```cpp
void bit.add(int i, const T& x)
```

#### 計算量

- $\mathrm{O}(\log N)$

### fold

$A_l \ast \dots \ast A_{r-1}$ を取得

```cpp
T ds.fold(int l, int r)
```

#### 計算量

- $\mathrm{O}(1)$
