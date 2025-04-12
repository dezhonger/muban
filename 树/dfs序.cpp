vector<int> id(2 * n + 1);
vector<int> in(n + 1), out(n + 1);

// 下标从1开始
int cnt = 0;

function<void(int, int, int)> dfs = [&](int x, int f, int d) {
    id[++cnt] = x;
    in[x] = cnt;
    for (auto& e : g[x]) {
        int y = e.first;
        if (y == f)
            continue;
        dfs(y, x, d + e.second);

    }
    id[++cnt] = x;
    out[x] = cnt;
};

// 下标从1开始
// 对于树 {[1, 2], [1, 3]}
// [id]: {0, 1, 2, 2, 3, 3, 1, 0, 0}
// [in]: {0, 1, 2, 4, 0}
// [out]: {0, 6, 3, 5, 0}
