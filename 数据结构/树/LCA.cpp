#include <bits/stdc++.h>
using namespace std;

// 代码的下标是从0开始的
// 2**17 >= MAXN
static const int MAXN = 100000;
static const int LOG = 17;

int n; // 节点个数
vector<pair<int,int>> adj[MAXN]; // 图的边表示
int up[LOG+1][MAXN]; // 倍增数组
int depth[MAXN]; //深度数组, 0是根节点 depth[0]=0;
long long dist0[MAXN]; // 根节点到每个节点的距离


class Solution {
public:


    void dfs(int u, int p) {
        up[0][u] = p;
        for (auto &e : adj[u]) {
            int v = e.first, w = e.second;
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dist0[v] = dist0[u] + w;
            dfs(v, u);
        }
    }

    int lca0(int u, int v) {
        if (depth[u] < depth[v]) 
            swap(u, v);
        int diff = depth[u] - depth[v];
        for (int k = 0; k <= LOG; ++k) {
            if (diff & (1 << k)) {
                u = up[k][u];
            }
        }
        if (u == v) return u;
        for (int k = LOG; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return up[0][u];
    }

    // u, v 是节点编号, 返回 u, v 之间的距离
    long long dist(int u, int v) {
        int w = lca0(u, v);
        return dist0[u] + dist0[v] - 2LL * dist0[w];
    }

    void lca_init(vector<vector<int>>& edges) {
        n = edges.size() + 1; // 节点个数是边的数 +1
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        depth[0] = 0;
        dist0[0] = 0;
        dfs(0, 0); //求出 depth 和 dist0, 注意这里根的父节点写为自己

        // 预处理 up 数组
        for (int k = 1; k <= LOG; ++k) {
            for (int v = 0; v < n; ++v) {
                up[k][v] = up[k-1][ up[k-1][v] ];
            }
        }
    }
};
