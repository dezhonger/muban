// https://www.luogu.com.cn/problem/P1495
// 中国剩余定理模板题
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "C:\zwl\files\docs\debug.h"
#else
#define debug(...) 42
#endif
typedef long long LL;
typedef unsigned long long ULL;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    LL M = 1;
    // x ≡ b[i] (mod a[i])
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        M *= a[i];
    }

    debug(M);
    for (int i = 1; i <= n; i++) {
        int k = M / a[i];
        int x, y;
        exgcd(k, a[i], x, y);
        ans = ans + b[i] * k * x % M;
    }
    cout << (ans % M + M) % M << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
