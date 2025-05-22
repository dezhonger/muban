// https://www.luogu.com.cn/problem/P4777
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "C:\zwl\files\docs\debug.h"
#else
#define debug(...) 42
#endif
typedef long long LL;
typedef unsigned long long ULL;
typedef long long LL;

LL read() {
    LL f = 1, x = 0;
    char ss = getchar();
    while (ss < '0' || ss > '9') {
        if (ss == '-')
            f = -1;
        ss = getchar();
    }
    while (ss >= '0' && ss <= '9') {
        x = x * 10 + ss - '0';
        ss = getchar();
    }
    return f * x;
}

const int maxn = 100010;
int n;
LL ai[maxn], bi[maxn];

// a * b % mod
LL mul(LL a, LL b, LL mod) {
    LL res = 0;
    while (b > 0) {
        if (b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

LL exgcd(LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL gcd = exgcd(b, a % b, x, y);
    LL tp = x;
    x = y;
    y = tp - a / b * y;
    return gcd;
}

LL excrt() {
    LL x, y, k;
    // x mod b = a
    // LL M = bi[1], ans = ai[1];  // 第一个方程的解特判
    LL M = 1, ans = 0;  // 第一个方程的解特判, 也可以这么写,下面的循环改为从1开始
    for (int i = 2; i <= n; i++) {
        LL a = M, b = bi[i], c = (ai[i] - ans % b + b) % b;  // ax≡c(mod b)
        LL gcd = exgcd(a, b, x, y), bg = b / gcd;
        if (c % gcd != 0)
            return -1;  // 判断是否无解(这题其实不用)
        x = mul(x, c / gcd, bg);
        ans += x * M;  // 更新前k个方程组的答案
        M *= bg;       // M为前k个m的lcm
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i)
        bi[i] = read(), ai[i] = read();
    printf("%lld", excrt());
    return 0;
}
