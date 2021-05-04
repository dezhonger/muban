#include <bits/stdc++.h>
using namespace std;
//Filename: acwing835.cpp 
//https://www.acwing.com/problem/content/837/
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-04 21:48:21
//Last modified: 2021-05-04 21:58:39

LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}

const int N = 100010;
int son[N][26], cnt[N], idx;
char str[N];

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

