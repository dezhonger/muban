// 两次dfs求直径的方法不能用于存在负权边的情形 https://oi-wiki.org/graph/tree-diameter/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

typedef long long LL;

// 给定一颗树,边权为1,顶点下标从1开始,求直径长度
// https://www.spoj.com/problems/PT07Z/ https://www.luogu.com.cn/problem/SP1437

// n节点个数, c: dfs函数使用
int n, c;
// 图
vector<vector<int>> g;
// 距离数组
vector<int> d;

// 设调用dfs传入u的值为x,dfs结束后d数组保存的是以x为根各个节点到x的路径长度, c保存了距离x最远的节点的编号
void dfs(int u, int fa) {
	for (int v: g[u]) {
		if (v == fa) continue;
		d[v] = d[u] + 1;
		if (d[v] > d[c]) c = v;
		dfs(v, u);
	}
}

int main() {
	cin >> n;
	g = vector<vector<int>>(n, vector<int>());
	d = vector<int>(n, 0);
	for (int i = 1; i < n; i++) {
		// 本题中的节点下标输入从1开始
		int u, v; 
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	// 以0号节点作为根进行第一次dfs
	dfs(0, -1);
	d[c] = 0, dfs(c, -1);
	cout << d[c] << endl;
	return 0;
}
