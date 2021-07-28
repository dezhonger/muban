#include <bits/stdc++.h>
using namespace std;


const int N = 100010;


int a[N], len;
inline int get(int x) {
    return x / len;
}

//循环结构体
struct Query {
    int l, r, id;
    
    //莫队排序
    bool operator< (const Query& w) const {
        int i = get(l);
        int j = get(w.l);
        if (i != j) return i < j;
        return r < w.r;
    }
    
}q[N];


vector<int> cnt;
int cc;

inline void add(int x) {
    if (!cnt[x]) cc++;
    cnt[x]++;
}

inline void del(int x) {
    if (cnt[x] == 1) cc--;
    cnt[x]--;
}

int main() {
    int nn, qq;
    scanf("%d%d", &nn, &qq);
    for (int i = 1; i <= nn; i++) scanf("%d", a + i);
    for (int i = 0; i < qq; i++) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    
    //分块大小
    len = (int)sqrt(nn);
    cnt = vector<int>(nn + 1);
    cc = 0;
    vector<bool> ans(qq + 1);
    sort(q, q + qq);
    // k枚举所有询问,[j, i]表示初始区间
    // 若区间下标是0-base的,则初始化为 i = -1, j = 0
    for (int k = 0, i = 0, j = 1; k < qq; k++) {
        int id = q[k].id, l = q[k].l, r = q[k].r;
        while (i < r) add(a[++i]);
        while (i > r) del(a[i--]);
        while (j < l) del(a[j++]);
        while (j > l) add(a[--j]);
        if (r - l + 1 == cc) ans[id] = true;
    }
    for (int i = 0; i < qq; i++) {
        if (ans[i]) puts("Yes");
        else puts("No");
    }
    return 0;
};
