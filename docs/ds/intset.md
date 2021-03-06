---
title: 整数キーのハッシュセット
documentation_of: //src/ds/intset.hpp
---

## 概要

整数をキーに持つハッシュセット

開番地法＋[Fibonnachi Hash](https://en.wikipedia.org/wiki/Hash_function#Fibonacci_hashing) で実装している。  
Fibonacchi HashはシンプルだしHackされそう。要調査

## I/F

### コンストラクタ

```cpp
IntSet<Key, int w> set()
```

空の辞書を作成する

- `Key`: キー型(`u64` に型変換可能な型)
- `w`: 辞書サイズの最大値は $2^w$ になる

#### 計算量

- $\mathrm{O}(2^w)$

### insert

```cpp
void set.insert(Key key)
```

集合に `key` を挿入

#### 計算量

平均 $\mathrm{O}(1)$

### erase

```cpp
void set.erase(Key key)
```

集合から `key` を削除

#### 計算量

平均 $\mathrm{O}(1)$

### contains

```cpp
bool set.contains(Key key)
```

集合に `key` が含まれるかどうか

##### 計算量

平均 $\mathrm{O}(1)$
