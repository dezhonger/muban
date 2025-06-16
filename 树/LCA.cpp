    static const int MAXN = 100000 + 5;
    static const int MAXM = MAXN * 2;
    static const int P    = 18;               // 支持到 2^17 ≥ 1e5

    // 链式前向星存图
    int  h[MAXN], e[MAXM], ne[MAXM], idx;
    LL   w[MAXM];
    // BFS／LCA 用
    int      depth[MAXN], fa[MAXN][P], q[MAXN];
    LL       distRoot[MAXN];

    // 加边
    void add(int a, int b, LL wt) {
        e[idx] = b;
        w[idx] = wt;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    // BFS 计算 depth[]、distRoot[]，并在过程中填 fa[][0..P-1]
    void bfs(int root) {
        // 标记未访问
        memset(depth, 0x3f, sizeof depth);
        depth[root]   = 0;
        distRoot[root] = 0;
        // 先把 root 的所有祖先都设为自己，保证倍增安全
        for (int k = 0; k < P; k++) fa[root][k] = root;

        int hh = 0, tt = 0;
        q[0] = root;
        while (hh <= tt) {
            int u = q[hh++];
            for (int i = h[u]; ~i; i = ne[i]) {
                int v = e[i];
                if (depth[v] > depth[u] + 1) {
                    depth[v]     = depth[u] + 1;
                    distRoot[v]  = distRoot[u] + w[i];
                    fa[v][0]     = u;
                    // 倍增
                    for (int k = 1; k < P; k++) {
                        fa[v][k] = fa[ fa[v][k-1] ][k-1];
                    }
                    q[++tt] = v;
                }
            }
        }
    }

    // 标准倍增 LCA
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a,b);
        // 抬高 a
        for (int k = P-1; k >= 0; k--) {
            if (depth[ fa[a][k] ] >= depth[b])
                a = fa[a][k];
        }
        if (a == b) return a;
        // 一起向上
        for (int k = P-1; k >= 0; k--) {
            if (fa[a][k] != fa[b][k]) {
                a = fa[a][k];
                b = fa[b][k];
            }
        }
        return fa[a][0];
    }
