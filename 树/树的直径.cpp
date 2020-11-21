#include <bits/stdc++.h>
using namespace std;
//Filename: 1437.cpp
// 求树的直径
//Author: dezhonger - csdisassembly@gmail.com
//spoj1437 
//https://www.luogu.com.cn/problem/solution/SP1437
//

//Create: 2020-11-22 00:26:59

const int N = 100100;
int h[N], nxt[N], e[N], w[N], idx;
bool st[N];
int n, ans;
//d[x]表示从节点x走到以x为根的子树，能够达到的最远距离
int d[N];

void add(int x, int y, int z) {
	e[idx] = y, nxt[idx] = h[x], w[idx] = z, h[x] = idx++;
}

void calc(int x, int parent) {
	st[x] = true;
	for (int i = h[x]; ~i; i = nxt[i]) {
		int y = e[i];
		if (st[y]) continue;
		calc(y, x);
		ans = max(ans, d[x] + d[y] + w[i]);
		d[x] = max(d[x], d[y] + w[i]);
	}
}

int main() {
	scanf("%d", &n);
	memset(h, -1, sizeof h);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y, 1);
		add(y, x, 1);
	}
	calc(1, -1);
	printf("%d\n", ans);
	return 0;
}

