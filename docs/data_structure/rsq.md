---
title: 数列の累積和管理
documentation_of: //src/data_structure/rsq.hpp
---

## 概要

アーベル群 $(T, +)$ が決まっている。  
要素数 $N$ の 数列 $A = \lbrack A _ 0, A _ 1, \dots , A _ {N-1}\rbrack$ について、以下の操作が $\mathrm{O}(1)$ でできる。

- 範囲和取得: $A _ l \dots A _ {r-1}$ の和

一点更新 $A _ i \leftarrow v$ についても `unsafeSet(i,v)` でサポートしているが、  
$i=0,1,\dots,N-1$ または $i=N-1,N-2,\dots,0$ の順に呼ばれることを前提としている。  
範囲和を取得する際はそれぞれ、 `prefixSum(l,r)`, `suffixSum(l,r)` を使うこと。  
DPの高速化などの用途を想定している。

### unsafeSetについて

クラス内部では以下を保持していて、

- 数列 $\lbrace A _ i \rbrace$
- 先頭からの累積和 $P_i = \sum _ {j \lt i} A_j\ (i=0,1,\dots,N)$
- 末尾からの累積和 $S_i = \sum _ {j \ge i} A_j\ (i=0,1,\dots,N)$ 

`unsafeSet(i,v)` は $P _ {i+1} \leftarrow P _ i + v$ と $S _ i \leftarrow S _ {i+1} + v$ を行う。  
そのため上記の制約を守って使わないと $\lbrace P _ i \rbrace$ と $\lbrace S _ i \rbrace$ が両方とも壊れてしまう。  

`recalc()` を呼ぶと $\mathrm{O}(N)$ 時間かけて、両方の累積和を計算しなおす。

## I/F

### コンストラクタ

```cpp
RSQ<T> rsq(const Vec<T>& vs)
```

数列 $A$ を `vs` の内容で初期化する

テンプレート引数`T`は以下を満たす型

- `T operator+(const T& x, const T& y)`: $x+y$ を返すオペレータが定義済み
- `x + T{} == x` である(`T{}`が単位元である)

#### 計算量

$\mathrm{O}(N)$

### prefixSum

```cpp
T rsq.prefixSum(int l, int r)
```

$A _ l \ast \dots \ast A _ {r-1}$ の取得  
計算には、先頭からの累積和 $\lbrace P _ i \rbrace$ を使う。


#### 計算量

$\mathrm{O}(1)$

### suffixSum

```cpp
T rsq.suffixSum(int l, int r)
```

$A _ l \ast \dots \ast A _ {r-1}$ の取得  
計算には、末尾からの累積和 $\lbrace S _ i \rbrace$ を使う。


#### 計算量

$\mathrm{O}(1)$

### unsafeSet

```cpp
void rsq.unsafeSet(int i, const T& v)
```

$A _ i$ に $v$ を代入する。

#### 計算量

$\mathrm{O}(1)$

### operator[]

```cpp
T a = rsq[i];
```

$A _ i$ の値を取得

#### 計算量

$\mathrm{O}(1)$

### recalc

```cpp
void rsq.recalc()
```

内部で保持する累積和 $\lbrace P _ i \rbrace, \lbrace S _ i \rbrace$ を再計算する。  
この直後は `prefixSum`, `suffixSum` の呼び出しは正当となる。

#### 計算量

$\mathrm{O}(N)$
