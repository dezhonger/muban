//lc2711
class Solution {
public:
    void DiagonalNumbering(vector<vector<int>>& g) {
        //n: 行数 m:列数
        int n = g.size(), m = g[0].size();

        vector<vector<int>> res(n, vector<int>(m, 0));

        // 编号对角线 [1, n + m - 1]
        for (int s = 1; s <= n + m - 1; s++)
        {
            // 对角线起始纵坐标
            int minJ = max(0, m - s);
            // 对角线结束纵坐标
            int maxJ = min(m - 1, n + m - 1 - s);

            unordered_set<int> st;
            for (int j = minJ; j <= maxJ; j++)
            {
                // 对应的横坐标
                int i = s + j - m;
                cout << s << " " << i << " " << j << endl;
            }
            cout << endl;
        }
        return res;
    }
};

n = 3, m = 4;
1 0 3

2 0 2
2 1 3

3 0 1
3 1 2
3 2 3

4 0 0
4 1 1
4 2 2

5 1 0
5 2 1

6 2 0

n = m = 3:
1 0 2

2 0 1
2 1 2

3 0 0
3 1 1
3 2 2

4 1 0
4 2 1

5 2 0
