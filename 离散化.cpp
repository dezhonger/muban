#include <bits/stdc++.h>
using namespace std;
//Filename: 802.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//https://www.acwing.com/problem/content/804/
//离散化
//Create: 2021-03-07 21:48:03
#define F first
#define S second

typedef pair<int, int> PII;
const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;


//离散化，找到原值离散化后的值
int find(int x) {
	int l = 0, r = alls.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;//为了后面使用前缀和算法，我们这里返回的下标从1开始
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	}

	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r);
	}

	//离散化操作
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	for (auto item: add) {
		int x = find(item.F);
		a[x] += item.S;
	}

	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

	for (auto item: query) {
		int l = find(item.F), r = find(item.S);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
