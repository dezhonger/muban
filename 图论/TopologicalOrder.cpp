bool topsort()
{
    int hh = 0, tt = -1;

    // d[i] 存储点i的入度
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
    return tt == n - 1;
}



// 另一种写法，更简单看起来

vector<vector<int>> e(n);   // 邻接表
vector<int> indeg(n);   // 入度表
// 预处理
for (const auto& edge: edges) {
    e[edge[0]].push_back(edge[1]);
    ++indeg[edge[1]];
}
// 广度优先搜索求解拓扑排序
queue<int> q;
for (int i = 0; i < n; ++i) {
    if (!indeg[i]) {
        q.push(i);
    }
}
while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v: e[u]) {
        // 更新子节点的祖先哈希表
        anc[v].insert(u);
        for (int i: anc[u]) {
            anc[v].insert(i);
        }
        --indeg[v];
        if (!indeg[v]) {
            q.push(v);
        }
    }
}
