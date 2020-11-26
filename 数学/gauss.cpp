#include <bits/stdc++.h>
using namespace std;
//Filename: gauss.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-11-27 01:37:26

const int N = 50;
double a[N][N];
double eps = 1e-6;
int n;

// a[N][N]是增广矩阵
int gauss()
{
    int c, r;
    for (c = 0, r = 0; c < n; c ++ )
    {
        int t = r;
        for (int i = r; i < n; i ++ )   // 找到绝对值最大的行
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) continue;

        for (int i = c; i <= n; i ++ ) swap(a[t][i], a[r][i]);      // 将绝对值最大的行换到最顶端
        for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];      // 将当前上的首位变成1
        for (int i = r + 1; i < n; i ++ )       // 用当前行将下面所有的列消成0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];

        r ++ ;
    }

    if (r < n)
    {
        for (int i = r; i < n; i ++ )
            if (fabs(a[i][n]) > eps)
                return 2; // 无解
        return 1; // 有无穷多组解
    }

    for (int i = n - 1; i >= 0; i -- )
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[i][j] * a[j][n];

    return 0; // 有唯一解
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			scanf("%lf", &a[i][j]);
		}
	}
	int ans = gauss();
	if (ans == 2) {
		puts("-1");
	} else if (ans == 1) {
		puts("0");
	} else {
		for (int i = 0; i < n; i++) printf("x%d=%.2f\n", i + 1, a[i][n]);
	}

    return 0;
}



