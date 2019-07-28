# stocker

## 概要
簡単な商品在庫管理システム。以下のような在庫の追加、販売、チェックなどの機能がある。ずれの引数についても、予期しない値（例：整数のところに 1.1 の入力）が入力された場合はエラーとして扱い、"ERROR"と出力。

## データベース
psql (PostgreSQL) 9.2.24

## API
在庫の追加
引数；
- unction（必須）：addstock
- name（必須）：対象の商品の名前を指定する。
- amount（任意）：対象の商品を在庫に追加する数（正の整数）を指定する。省略時は 1 とする。
出力：なし

在庫チェック
引数：
- function（必須）：checkstock
- name（任意）：対象の商品の名前を指定する。
出力：
- nameが指定された場合は、そのnameの商品の在庫の数を "[name]: [amount]" の形式で出力する。在庫が無い場合は amountを 0 として表示する。
- nameが指定されない場合は、全ての商品の在庫の数をnameをキーに昇順ソートして出力する。在庫が 0 のものは表示しない。 

販売
引数：
- function（必須）：sell 
- name（必須）：対象の商品の名前を指定する。
- amount（任意）：対象の商品を販売する数（正の整数）を指定する。省略時は 1 とする。
- price（任意）：対象の商品の価格（0より大きい数値）を指定する。入力された時のみ、price x amount を売り上げに加算する。
出力：なし

売り上げチェック
引数：
- unction（必須）：checksales
出力： その時点の売り上げを "sales: [sales]" の形式で表示する。小数の場合は小数点第二位まで表示されるよう切り上げてください。

全削除
引数：
- function（必須）：deleteall
出力：なし


## 実行例
### ケース1
>*$ curl "http://127.0.0.1:3000/stocker?function=deleteall"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=addstock&name=xxx&amount=100"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=sell&name=xxx&amount=4"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=checkstock&name=xxx"*  
>*xxx: 96*  
>*$ curl "http://127.0.0.1:3000/stocker?function=addstock&name=yyy&amount=100"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=addstock&name=YYY&amount=100"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=checkstock"*  
>*xxx: 96*  
>*yyy: 100*  
>*YYY: 100*  

### ケース2
>*$ curl "http://127.0.0.1:3000/stocker?function=deleteall"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=addstock&name=xxx&amount=1.1"*  
>*ERROR*  

### ケース3
>*$ curl "http://127.0.0.1:3000/stocker?function=deleteall"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=addstock&name=aaa&amount=10"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=addstock&name=bbb&amount=10"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=sell&name=aaa&amount=4&price=100"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=sell&name=aaa&price=80"*  
>*$ curl "http://127.0.0.1:3000/stocker?function=checkstock&name=aaa"*  
>*aaa: 5*  
>*$ curl "http://127.0.0.1:3000/stocker?function=checksales"*  
>*sales: 480*  
