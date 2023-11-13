#include <bits/stdc++.h>
using namespace std;
//Filename: acwing835.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-04 21:48:21
//Last modified: 2021-05-04 21:58:39

const int N = 100010;
int son[N][26], cnt[N], idx;
char str[N];
//如果是多组数组的话，需要
// memset(son, 0, sizeof son);
// memset(cnt, 0, sizeof cnt);
// idx = 0;

void insert(char *str) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		if (!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;
}

int query(char *str) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		if (!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char op[2];
		scanf("%s%s", op, str);
		if (op[0] == 'I') insert(str);
		else printf("%d\n", query(str));
	}
	return 0;
}
