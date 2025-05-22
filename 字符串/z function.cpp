// https://www.cnblogs.com/luckyblock/p/17977668#%E5%8C%B9%E9%85%8D%E5%AD%90%E4%B8%B2
// https://www.luogu.com.cn/problem/P5410
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int kN = 2e7 + 10;
int z[kN], p[kN];
string a, b;
int n, m;

void z_function() {
    z[1] = m;
    for (int i = 2, l = 0, r = 0; i <= m; ++i) {
        if (i <= r && z[i - l + 1] < r - i + 1) {
            z[i] = z[i - l + 1];
        } else {
            z[i] = std::max(0, r - i + 1);
            while (i + z[i] <= m && b[z[i] + 1] == b[i + z[i]])
                ++z[i];
        }
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
void extend() {
    for (int i = 1, l = 0, r = 0; i <= n; ++i) {
        if (i <= r && z[i - l + 1] < r - i + 1) {
            p[i] = z[i - l + 1];
        } else {
            p[i] = std::max(0, r - i + 1);
            while (i + p[i] <= n && a[i + p[i]] == b[p[i] + 1])
                ++p[i];
        }
        if (i + p[i] - 1 > r)
            l = i, r = i + p[i] - 1;
    }
}
int main() {
    cin >> a >> b;
    n = a.size(), m = b.size();
    a = ' ' + a, b = ' ' + b;
    z_function();
    extend();
    LL ans = 0;
    for (int i = 1; i <= m; ++i)
        ans ^= 1ll * i * (z[i] + 1);
    printf("%lld\n", ans);
    ans = 0;
    for (int i = 1; i <= n; ++i)
        ans ^= 1ll * i * (p[i] + 1);
    printf("%lld\n", ans);
    return 0;
}
