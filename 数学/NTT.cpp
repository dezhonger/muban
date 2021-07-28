// Code by KSkun, 2018/3
// https://ksmeow.moe/fast_number_thoery_transformation/
// https://www.luogu.com.cn/problem/P3803
#include <cstdio>

#include <algorithm>

typedef long long LL;

inline char fgc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline LL readint() {
    register LL res = 0, neg = 1;
    char c = fgc();
    while(c < '0' || c > '9') {
        if(c == '-') neg = -1;
        c = fgc();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = fgc();
    }
    return res * neg;
}

const int MAXN = 1 << 22, G = 3, MO = 998244353;

int n, m, len, rev[MAXN];
LL a[MAXN], b[MAXN];

inline LL fpow(LL n, LL k) {
    LL t = 1;
    while(k) {
        if(k & 1) t = (t * n) % MO;
        n = (n * n) % MO;
        k >>= 1;
    }
    return t;
}

inline void ntt(LL *arr, int f) {
    for(int i = 0; i < n; i++) {
        if(i < rev[i]) std::swap(arr[i], arr[rev[i]]);
    }
    for(int i = 1; i < n; i <<= 1) {
        LL gn = fpow(G, (MO - 1) / (i << 1));
        if(f == -1) gn = fpow(gn, MO - 2);
        for(int j = 0; j < n; j += i << 1) {
            LL w = 1;
            for(int k = 0; k < i; k++) {
                LL x = arr[j + k], y = w * arr[j + k + i] % MO;
                arr[j + k] = (x + y) % MO;
                arr[j + k + i] = ((x - y) % MO + MO) % MO;
                w = (w * gn) % MO;
            }
        }
    }
}

int main() {
    n = readint(); m = readint();
    for(int i = 0; i <= n; i++) {
        a[i] = readint();
    }
    for(int i = 0; i <= m; i++) {
        b[i] = readint();
    }
    m += n;
    for(n = 1; n <= m; n <<= 1) len++;
    for(int i = 0; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
    }
    ntt(a, 1);
    ntt(b, 1);
    for(int i = 0; i <= n; i++) {
        a[i] = (a[i] * b[i]) % MO;
    }
    ntt(a, -1);
    int invn = fpow(n, MO - 2);
    for(int i = 0; i <= m; i++) {
        printf("%lld ", a[i] * invn % MO);
    }
    return 0;
}
