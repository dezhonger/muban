// 线性求任意 n 个数的逆元
// https://oi-wiki.org/math/number-theory/inverse/#%E7%BA%BF%E6%80%A7%E6%B1%82%E4%BB%BB%E6%84%8F-n-%E4%B8%AA%E6%95%B0%E7%9A%84%E9%80%86%E5%85%83
s[0] = 1;
for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * a[i] % p;
sv[n] = qpow(s[n], p - 2);
// 当然这里也可以用 exgcd 来求逆元,视个人喜好而定.
for (int i = n; i >= 1; --i) sv[i - 1] = sv[i] * a[i] % p;
for (int i = 1; i <= n; ++i) inv[i] = sv[i] * s[i - 1] % p;
