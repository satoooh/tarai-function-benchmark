# Tarai function Benchmark

Python, Ruby, C++, Java, JavaScript, Go, Rust, PHP の各言語で、Tarai function を実装と実行時間の計測を行い、それぞれの結果を比較する。
各言語での実装では、ChatGPTとの対話を参考にしている。

## 結果

tarai(13, 5, 0) を実行した結果を以下の表に示す。

| language | version | Average time (sec) | Standard deviation (sec) | source | other |
| --- | --- | --- | --- | --- | --- |
| Python | 3.10.5 | 4.113185453414917 | 0.0610696132287615 | [tarai.py](./tarai.py) | `python tarai.py` で実行 |
| Ruby | 3.1.2 | 2.3376888 | 0.03658753548354963 | [tarai.rb](./tarai.rb) | `ruby tarai.rb` で実行 |
| PHP | 8.2.6 | 2.0136955976486 | 0.012492157295195 | [tarai.php](./tarai.php) | `php tarai.php` で実行 |
| JavaScript | node v19.8.1 | 0.21630000000000002 | 0.0023685438564654045 | [tarai.js](./tarai.js) | `node tarai.js` で実行 |
| C++ | C++20 (202002) | 0.106396 | 0.00468259 | [tarai.cpp](./tarai.cpp) | `g++ -std=c++20 tarai.cpp -o tarai && ./tarai` で実行 |
| Java | 20.0.1 | 0.0512 | 0.0012489995996796796 | [tarai.java](./tarai.java) | `javac tarai.java && java tarai` で実行 |
| Go | go1.20.5 | 0.069549 | 0.007391 | [tarai.go](./tarai.go) | `go run tarai.go` で実行 |
| Rust | rustc 1.69.0 | 0.10643837520000002 | 0.002337982066436942 | [tarai.rs](./tarai.rs) | `rustc tarai.rs && ./tarai` で実行 |

- 実行時間は、10回の平均と標準偏差を記録している
- C++ コンパイラについて: `gcc version 13.1.0 (Homebrew GCC 13.1.0)`

結果から、C++, Java, Go, Rust が高速なパフォーマンスを示し、Python, Ruby, PHP が低速なパフォーマンスを示している。

## Tarai function とは

次の数式により再帰的に定義される関数。

$$
Tarai(x, y, z) =
\begin{cases}
    y & \text{if } x \le y \\
    Tarai(Tarai(x-1, y, z), Tarai(y-1, z, x), Tarai(z-1, x, y)) & \text{otherwise}
\end{cases}
$$

[竹内関数 - Wikipedia](https://ja.wikipedia.org/wiki/%E7%AB%B9%E5%86%85%E9%96%A2%E6%95%B0)
