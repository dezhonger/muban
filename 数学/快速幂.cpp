typedef long long LL;
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
