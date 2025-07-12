//  S = sum_{d=1..N} floor(N/d) ，O(sqrt(N))
LL f(LL N) {
    LL S = 0;
    for (LL i = 1, j; i <= N; i = j + 1) {
        LL q = N / i;
        j = N / q;
        S = (S + ((__int128)q * (j - i + 1)) % MOD) % MOD;
    }
    return S;
}
