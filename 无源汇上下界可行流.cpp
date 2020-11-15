#include <bits/stdc++.h>
using namespace std;
//Filename: 2188(无源汇上下界可行流).cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-11-14 21:20:47

const int N = 210, M = (10200 + N) * 2, INF = 1e8;
int n, m, S, T;
//f是上界，l是下界
int h[N], e[M], f[M], l[M], ne[M], idx;
//q是队列，d是分层路，cur是当前弧优化, A数组当前点需要多增加的流量
int q[N], d[N], cur[N], A[N];

void add(int a, int b, int c, int d) {
	e[idx] = b, f[idx] = d - c, l[idx] = c, ne[idx] = h[a], h[a] = idx++;
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

int main() {
	scanf("%d%d", &n, &m);
	S = 0, T = n + 1;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		add(a, b, c, d);
		A[a] -= c, A[b] += c;
	}

	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i] > 0) {
			add(S, i, 0, A[i]);
			tot += A[i];
			//cout << "S: " << i << " " << A[i] << endl;
		} else if (A[i] < 0) { 
			add(i, T, 0, -A[i]);
		   	//cout << "T: " << i << " " << -A[i] << endl;
		}
	}
	if (dinic() != tot) puts("NO");
	else {
		puts("YES");
		for (int i = 0; i < m * 2; i += 2) {
			printf("%d\n", f[i ^ 1] + l[i]);
		}
	}
	return 0;
}

