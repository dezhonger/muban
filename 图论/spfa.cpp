#include <bits/stdc++.h>
using namespace std;
//Filename: spfa.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//https://www.acwing.com/problem/content/description/853/

//Create: 2021-03-07 13:34:20

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
	memset(dist, 0x3f, sizeof dist);
	queue<int> q;
	q.push(1);
	st[1] = true;
	dist[1] = 0;
	while (q.size()) {
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if (!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}

	spfa();

	if (dist[n] == 0x3f3f3f3f) puts("impossible");
	else printf("%d\n", dist[n]);
	return 0;


}
