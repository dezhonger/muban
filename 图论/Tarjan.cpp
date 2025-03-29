struct Tarjan {  // index from 0 to n - 1
    static const int N = 100000 + 10;
    std::vector<int> SCC[N];
    int low[N], dfn[N], col[N];
    int stk[N], top, scc_cnt, sz;
    int n;

    void dfs(int x, const std::vector<int> G[]) {
        low[x] = dfn[x] = ++sz;
        stk[++top] = x;
        for (auto& y : G[x]) {
            if (!dfn[y]) {
                dfs(y, G);
                low[x] = std::min(low[x], low[y]);
            } else if (col[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            SCC[scc_cnt++].clear();
            do {
                SCC[scc_cnt - 1].push_back(stk[top]);
                col[stk[top]] = scc_cnt - 1;
            } while (stk[top--] != x);
        }
    }

    int run(int n, const std::vector<int> G[]) {
        this->n = n;
        sz = top = scc_cnt = 0;
        memset(dfn, 0, sizeof(*dfn) * n);
        memset(col, -1, sizeof(*col) * n);
        for (int i = 0; i < n; ++i) {
            if (!dfn[i])
                dfs(i, G);
        }
        int ans = 0;
        for (int i = 0; i < scc_cnt; i++) {
            ans = max(ans, (int)SCC[i].size());
        }
        return ans;
    }

    void print() {
        for (int i = 0; i < scc_cnt; i++) {
            cout << "SCC " << i << ": ";
            for (int j = 0; j < SCC[i].size(); j++) {
                cout << SCC[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++) {
            cout << "Node " << i << ": ";
            cout << col[i] << endl;
        }
    }
};

Tarjan tar;
vector<int> G[100010];

// https://leetcode.cn/problems/longest-cycle-in-a-graph/
class Solution {
   public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        for (int i = 0; i < n; i++)
            G[i].clear();
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                G[i].push_back(edges[i]);
            }
        }
        int ans = tar.run(n, G);
        if (ans == 1)
            return -1;
        return ans;
    }
};
