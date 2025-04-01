int n = grid.size(), m = grid[0].size();
vector<vector<int>> sum(n + 1, vector<int>(m + 1));
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i - 1][j - 1];
    }
}
