#include <bits/stdc++.h>
using namespace std;
//Filename: 5.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-11-23 22:16:12

const int V = 2010;
int n, m;
int f[V];

int main() {
	vector< pair<int, int > > goods;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		//v:体积 w:价值 s:数量
		int v, w, s;
		cin >> v >> w >> s;
		//二进制拆分
		for (int k = 1; k <= s; k *= 2) {
			s -= k;
			goods.push_back(make_pair(k * v, k * w));
		}
		if (s > 0) goods.push_back(make_pair(s * v, s * w));


	}
	//做一个0/1背包
	for (auto g : goods) {
		for (int j = m; j >= g.first; j--){
			f[j] = max(f[j], f[j - g.first] + g.second);
		}
	}
	cout << f[m] << endl;
    return 0;
}

