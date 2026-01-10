# 学んだこと

# ex00

## **sream class** (標準ストリーム /入出力)

```cpp
#include <iostream>

std::string str = "oitsuki"
int Value = 42;

std::cout << str << " " << Value <<std::endl;

// console:
// oitsuki 42
```

- `<</>>` 挿入演算子
- `std::cin` 表示入力
- `std::cout` 標準出力
- `std::cerr` エラー出力
- `std::endl`
	- 改行文字'\n'を出力
	- 同時に出力ストリームのバッファを強制的にフラッシュ（内容を書き出す）


## **class** (データと処理をまとめるための型)

```cpp
class Class
{
private:
	Class(); // インスタンス化禁止

public:
	static void func();
};
```
### (1)class
#### メンバ変数 (状態) :この型のデータ構造のこと
#### メンバ関数 (処理/振る舞い) : それを操作する関数のこと

### (2) アクセス制御
#### public : 外部から使ってようインターフェース部分
#### private : クラス内部で使うメンバ（外部に見せない 実装詳細）

### (3) インスタンス
### classから生成される実態
```cpp
Megaphon	a;	// a がインスタンス
Megaphon	b;	// b も別インスタンス
```
### インスタンスを作ると、通常は
- メンバ変数の領域が確保される
- コンストラクタが呼ばれ、初期化される
- インスタンスごとに独立した状態を持つ

### (4) ユーティリティークラス（外部からのインスタンス化を防止）
#### Megaphon(); が private の意味について
1)  コンストラクタは「インスタンス生成時に呼ばれる初期化関数」です。
2) それを private にして、クラス外からコンストラクタにアクセスできないため、外部でインスタンスを作れなくすした堅牢な作り
```cpp
Class m;      // ❌ コンストラクタが private なので不可
```

### (5)まとめ（この断片の読み方）

class Megaphon：型を定義
- `private Megaphon();`：外部からインスタンス化禁止（誤用防止）
- `public static void print();`：インスタンス不要の公開API
- `private/public`：外部に見せるAPIと内部実装を分離

## **namespace** (関数・クラス・変数の名前の衝突を防ぐための仕組み)

```cpp
	namespace name
	{
		void func();

	}

	name::func();
```
- `::` スコープ解決演算子
- インスタンス化できない
- 複数ファイルに分割/拡張可能

⚠️ using namespace はスコープ汚染の原因になるため基本使わない

## **cast** (データ型の変換)

### (1) `static_cast`（最も基本・最も安全）

```cpp
	static_cast<DataType>(Value);
```
- コンパイル時にチェックされる
- 意味のある変換だけを許可

### (2) `const_cast`

```cpp
	const_cast<DataType>(Value);
```
- `const / volatile` の除去・付与
- 本来 const なオブジェクトを書き換えると未定義動作

### (3) `reinterpret_cast`
```cpp
	reinterpret_cast<DataType>(value);
```
- ビット列を全く別の型として再解釈
- 型安全性を完全に無視

### (4) `dynamic_cast`
```cpp
	Base* base = getObject();
	Derived* d = dynamic_cast<Derived*>(base);
```
- ポリモーフィズム（継承）が関係する型変換
- 基底クラスに virtual 関数が必要

## **try/catch/throw** (例外処理)

#### 例外処理とは
通常の処理の流れでは扱えない異常状態」を扱う仕組み。
`try`内で起こりうる例外を`throw`すると例外を`catch`する
- 入力不正
- 前提条件の破綻
- 実行時にしか分からない問題


```cpp

if (!is_err())
{
	throw ErrorMessage;
}

try
{
	// 通常処理
}

catch (const )
{
	// 例外処理
}

```

#### `try`
- 異常が起きるかもしれない領域
#### `catch`
- 異常を集約して処理する
	- 型で例外を振り分ける
	- 最初に一致した catch が実行される
#### `throw`
- 異常を通知する
	- 異常が起きた瞬間に処理を中断
	- 呼び出し元へ一気に伝播