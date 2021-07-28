#include <bits/stdc++.h>
using namespace std;
//Filename: 2523.cpp
//https://www.luogu.com.cn/problem/AT1219
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-11-05 23:05:53


typedef long long LL;


const int N = 1000005;
int n, m, len;
int w[N], cnt[N];
LL ans[N];
struct Query {
	int id, l, r;
}q[N];

vector<int> nums;

int get(int x) {
	return x / len;
}

bool cmp(const Query& a, const Query& b) {
	int i = get(a.l), j = get(b.l);
	if (i != j) return i < j;
	return a.r < b.r;
}

void add(int x, LL& res) {
	cnt[x]++;
	res = max(res, (LL)cnt[x] * nums[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	len = sqrt(n);
	for (int i = 0; i < n; i++) scanf("%d", w + i), nums.push_back(w[i]);
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	for (int i = 0; i < n; i++) {
		w[i] = lower_bound(nums.begin(), nums.end(), w[i]) - nums.begin();
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		q[i] = {i, l, r};
	}
	sort(q, q + m, cmp);
	for (int x = 0; x < m; ) {
		int y = x;
		while (y < m && get(q[y].l) == get(q[x].l)) y++;
		int right = (get(q[x].l)) * len + len - 1;
		
		//左右端点都在一个块内
		while (x < y && q[x].r <= right) {
			LL res = 0;
			int id = q[x].id, l = q[x].l, r = q[x].r;
			for (int k = l; k <= r; k++) add(w[k], res);
			ans[id] = res;
			for (int k = l; k <= r; k++) cnt[w[k]]--;
			x++;
		}

		LL res = 0;
		int i = right, j = right + 1;
		//左端点在一个块内，右端点不在一个块内
		while (x < y) {
			int id = q[x].id, l = q[x].l, r = q[x].r;
			while (i < r) add(w[++i], res);
			LL backup = res;
			while (j > l) add(w[--j], res);
			ans[id] = res;
			while (j < right + 1) cnt[w[j++]]--;
			res = backup;
			x++;
		}
		memset(cnt, 0, sizeof cnt);
	}

	for (int i = 0; i < m; i++) {
		printf("%lld\n", ans[i]);
	}
}



