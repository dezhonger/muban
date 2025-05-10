typedef long long LL;
int mod = (int)1e9 + 7;
LL powmod(LL a,LL b) {
	LL res = 1;
	a %= mod;
	assert(b >= 0);
	for (; b; b >>= 1) {
		if (b & 1)res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

int inv(int n){
    return powmod(n, mod - 2);
}
int C(int m, int n){
    int res = 1;
    for(int i = 0; i < n; i += 1) res = 1LL * res * (m - i) % mod;
    for(int i = 1; i <= n; i += 1) res = 1LL * res * inv(i) % mod;
    return res;
}

// 直接求，可能会溢出，需要注意
LL C(int n, int k) {
	k = min(k, n - k);
	long long res = 1;
	for (int i = 1; i <= k; i++) res = res * (n + 1 - i) / i;
	return res;
}

LL comb(int n, int m) {
    if (n < m || n < 0 || m < 0)
        return 0;
    return 1LL * f[n] * g[m] % mod * g[n - m] % mod;
}
