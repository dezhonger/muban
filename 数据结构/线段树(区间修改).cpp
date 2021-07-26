//https://www.luogu.com.cn/problem/P3372
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

typedef long long LL;

int n, m;
int w[N];
struct Node {
    int l, r;
    LL sum, add;
}tr[N << 2];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    auto& root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add, left.sum += (LL)(left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (LL)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, w[l], 0};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        // 注意这里
        pushup(u);
    }
}

void modify(int u, int l, int r, int d) {
    if (l <= tr[u].l && r >= tr[u].r) {
        // [l, r]完全包含u对应的区间
        // 处理sum和懒标记
        tr[u].sum += (LL)d * (tr[u].r - tr[u].l + 1);
        tr[u].add += d;
    } else {
        // 注意这里
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        // 注意这里
        pushup(u);
    }
}

LL query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) return tr[u].sum;
    
    // 注意这里
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL sum = 0;
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", w + i);
    
    build(1, 1, n);
    
    int op, l, r, d;
    
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &l, &r, &d);
            modify(1, l, r, d);
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}


