constexpr int mod = 1'000'000'007;
constexpr int maxn = 10000 + 13;
int f[maxn], g[maxn];


void factorial() {
  // 多次调用，mod不同的话，需要     memset(f, 0, sizeof f); memset(g, 0, sizeof g);
  for (int i = 0; i < maxn; i += 1) f[i] = i ? 1LL * f[i - 1] * i % mod : 1;
  for (int i = 1; i < maxn; i += 1) g[i] = i == 1 ? 1 : 1LL * (mod - mod / i) * g[mod % i] % mod;
  for (int i = 0; i < maxn; i += 1) g[i] = g[i] ? 1LL * g[i - 1] * g[i] % mod : 1;
}

// 组合数
LL C(int n, int m) {
    if (n < m) return 0;
    return 1LL * f[n] * g[m] % mod * g[n - m] % mod;
}
