//https://www.luogu.com.cn/problem/P1082
//求求关于x的同余方程ax≡1(modb) 的最小正整数解。

#include <iostream>
#include <algorithm>

using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main()
{
	int n;

	int a, b;
	scanf("%d%d", &a, &b);
	int x, y;
	//ax + by = gcd(a, b) 求出一组解(x, y)
	exgcd(a, b, x, y);
	
	cout << (x % b + b) % b << endl;

	return 0;
}
