#include <bits/stdc++.h>
using namespace std;
//Filename: LIS_NlgN.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-11-23 22:54:28




const int N = 1010;
//f[i]: 长度为i的LIS数组的最小结尾数字
int f[N];
int n, ans;

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
	cin >> n;
	int len = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		f[0] = -2e9;
		int l = 0, r = len;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (f[mid] < x) l = mid;
			else r = mid - 1;
		}
		f[l + 1] = x;
		len = max(len, l + 1);
	}
	cout << len << endl;
    return 0;
}

