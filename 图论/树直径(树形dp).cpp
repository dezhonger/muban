// 适用于负权边
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int N = 1e4 + 5;

typedef long long LL;

// n节点个数, 
int n, ans;
// 图
vector<vector<int>> g;
// 距离数组: 以当前节点作为根向下能延伸的最长路径长度和次长路径长度
vector<int> d1, d2;

// 树形dp求直径长度
void dfs(int u, int fa) {
	d1[u] = d2[u] = 0;
	for (int v: g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		int t = d1[v] + 1;
		if (t > d1[u]) d2[u] = d1[u], d1[u] = t;
		else if (t > d2[u]) d2[u] = t;
		ans = max(ans, d1[u] + d2[u]);
	}
}

int main() {
	cin >> n;
	g = vector<vector<int>>(n, vector<int>());
	d1 = vector<int>(n, 0);
	d2 = vector<int>(n, 0);
	for (int i = 1; i < n; i++) {
		// 本题中的节点下标输入从1开始
		int u, v; 
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	cout << ans << endl;
	return 0;
}
