#include <bits/stdc++.h>
using namespace std;


const int N = 510, M = 10010, INF = 1e8;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
//q是队列，d是分层路，cur是当前弧优化
int q[N], d[N], cur[N];
//计算在残留网络上从S出发可以达到的点的集合
bool vis_s[N];
//计算在残留网络上可以到到达S点的集合
bool vis_t[N];

void add(int a, int b, int c) {
	e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
	e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
	int hh = 0, tt = 0;
	memset(d, -1, sizeof d);
	q[0] = S, d[S] = 0, cur[S] = h[S];
	while (hh <= tt) {
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i]) {
			int ver = e[i];
			//如果这个点没有搜过并且流量大于0
			if (d[ver] == -1 && f[i]) {
				d[ver] = d[t] + 1;
				cur[ver] = h[ver];
				if (ver == T) return true;
				q[++tt] = ver;
			}
		}
	}
	return false;
}

int find(int u, int limit) {
	if (u == T) return limit;
	int flow = 0;
	//从当前没有满的路径开始搜
	for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
		cur[u] = i; //当前弧优化
		int ver = e[i];
		if (d[ver] == d[u] + 1 && f[i]) {
			int t = find(ver, min(f[i], limit - flow));
			//从这个点出发是搜不到路径的，就删除这个点
			if (!t) d[ver] = -1;
			f[i] -= t, f[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}

int dinic() {
	int r = 0, flow;
	while (bfs()) {
		while (flow = find(S, INF)) r += flow;
	}
	return r;
}

void dfs(int u, bool st[], int t) {
	st[u] = 1;
	for (int i = h[u]; ~i; i = ne[i]) {
		//如果是源点，搜索正向边; 如果是汇点，搜索反向边(计算可以到达汇点的边)
		int j = i ^ t, ver = e[i];
		//如果是有流量的话，继续搜索
		if (f[j] && !st[ver]) dfs(ver, st, t);
	}
}

int main() {
	int res = 0;
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	S = 0, T = n - 1;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}
	dinic();
	//搜索从源点在残留网络上可以到达的点
	dfs(S, vis_s, 0);
	//搜索在残留网络上可以到达汇点的点
	dfs(T, vis_t, 1);
	//求的是原网络，只枚举正向边。也就是边的编号是偶数
	for (int i = 0; i < m * 2; i += 2) {
		//如果该边流量跑满了，并且存在一条s-u v-t的路,即满足条件
		if (!f[i] && vis_s[e[i ^ 1]] && vis_t[e[i]]) res++;
	}
	printf("%d\n", res);
	return 0;
}


