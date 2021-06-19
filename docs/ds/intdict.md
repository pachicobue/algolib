---
title: 整数キーのハッシュマップ
documentation_of: //src/ds/intdict.hpp
---

## 概要

整数をキーに持つハッシュマップ

開番地法＋[Fibonnachi Hash](https://en.wikipedia.org/wiki/Hash_function#Fibonacci_hashing) で実装している。  
Fibonacchi HashはシンプルだしHackされそう。要調査

## I/F

### コンストラクタ

```cpp
IntDict<Key, Value, int w> dict()
```

空の辞書を作成する

- `Key`: キー型(`u64` に型変換可能な型)
- `Value`: 値型(Default Constructiveを要求)
- `w`: 辞書サイズの最大値は $2^w$ になる

#### 計算量

- $\mathrm{O}(2^w)$

### operator[]

```cpp
dict[key] = "hoge"
```

キーに対応する値を返す  
キーが存在しないときは `Value{}` を返す

#### 計算量

平均 $\mathrm{O}(1)$

### erase

```cpp
void dict.erase(Key key)
```

辞書から `key` を削除

#### 計算量

平均 $\mathrm{O}(1)$

### contains

```cpp
bool dict.contains(Key key)
```

辞書に `key` が含まれるかどうか

##### 計算量

平均 $\mathrm{O}(1)$
