#include <bits/stdc++.h>
using namespace std;
//Filename: EK.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-11-14 12:59:47


typedef long long LL;

const int N = 1010;
const int M = 20010;
const int INF = 1e8;
//点数，边数，源点编号，汇点编号
int n, m, S, T;
//邻接表存储图, f表示边的容量
int h[N], e[M], f[M], ne[M], idx;
//q表示队列，d用来在bfs中计算到某个点的容量，pre用来表示残余网络中一条增广路的点的前驱
int q[N], d[N], pre[N];
//bfs中标记去重
bool st[N];

void add(int a, int b, int c) {
	e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
	e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
	int hh = 0, tt = 0;
	memset(st, 0, sizeof st);
	q[0] = S, st[S] = true, d[S] = INF;
	while (hh <= tt) {
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i]) {
			int ver = e[i];
			if (!st[ver] && f[i]) {
				st[ver] = true;
				d[ver] = min(d[t], f[i]);
				//记录前驱边的编号
				pre[ver] = i;
				if (ver == T) return true;
				q[++tt] = ver;
			}
		}
	}
	return false;
}

int EK() {
	int r = 0;
	while (bfs()) {
		r += d[T];
		//pre[i] ^ 1表示反向边
		for (int i = T; i != S; i = e[pre[i] ^ 1]) {
			//计算残余网络流量
			f[pre[i]] -= d[T], f[pre[i] ^ 1] += d[T];
		}
	}
	return r;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &S, &T);
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}
	printf("%d\n", EK());
    return 0;
}

