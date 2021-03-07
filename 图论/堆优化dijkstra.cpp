#include <bits/stdc++.h>
using namespace std;
//Filename: 849.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//dijkstra求最短路算法模板

//Create: 2021-03-07 13:50:47

const int N = 510;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

void dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	//循环n-1次
	for (int i = 0; i < n - 1; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++) {
			if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
		}
		for (int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		}
		st[t] = true;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = min(g[a][b], c);
	}

	dijkstra();
	if (dist[n] == 0x3f3f3f3f) printf("%d\n", -1);
	else printf("%d\n", dist[n]);
	return 0;
}
