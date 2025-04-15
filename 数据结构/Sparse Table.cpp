#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
typedef long long LL;
// https://www.luogu.com.cn/problem/P3865 P3865 【模板】ST 表
struct ST {
    // 下标都是从1开始
    int M;
    vector<int> w;
    vector<vector<int>> f;
    ST() {}
    ST(int n) {
        w = vector<int>(n + 1);
        // pow(2, M) >= n, there is no harm in applying for more.
        M = log(n) / log(2) + 2; 
        f = vector<vector<int>>(n + 1, vector<int>(M));
    }
    
    void read(int n) {
        for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    }
    
    void work(int n) {
        for (int j = 0; j < M; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                if (!j) f[i][j] = w[i];
                else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    
    int query(int l, int r) {
        int k = log2(r - l + 1);
        return max(f[l][k], f[r - (1 << k) + 1][k]);
    }
};

int main()
{
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    ST st(n);
    st.read(n);
    st.work(n);
    while (m--) {
        scanf("%d%d", &l, &r);
        printf("%d\n",st.query(l,r));
    }
    return 0;
}
