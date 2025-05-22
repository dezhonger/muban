#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define reps(i, a, b) for(int i = (a); i <= (b); i++)
#define F first
#define S second

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];

//样例输入:
//3
//aba
//5
//ababa
//样例输出:
//0 2 
int main()
{
    //下标从1开始计算
    cin >> n >> p + 1 >> m >> s + 1;

    for (int i = 2, j = 0; i <= n; i ++ )
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }
    //for (int i = 1; i <= n; i++) cout << ne[i] << endl;
    for (int i = 1, j = 0; i <= m; i ++ )
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}




// muban 参考上面的样例
const int N = 100010, M = 1000010;
int ne[N];
vector<int> solve(int n, string p, int m, string s) {
    vector<int> ans;
    memset(ne, 0, sizeof ne);
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n) {
            // printf("%d ", i - n);
            ans.push_back(i - n); // 这里的下标是从0开始的,如果想从1开始,这里改为i-n+1
            j = ne[j];
        }
    }
    return ans;
}

// 如何调用
// solve(s1.size(), " " + s1, s2.size(), " " + s2);
// s1="ABA", s2="ABABABC", ans={0, 2}
// for (int i = 1; i <= s1.size(); i++) {
//     cout << ne[i] << " \n"[i == ne.size()];
// }

