struct LIS {
    int n;
    vector<int> a;
    vector<int> f;
    LIS(int n) : n(n), a(n + 1), f(n + 1) {}
    void init() {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }
    int work() {
        int len = 0;
        f[0] = -2e9;
        // f[i]: 长度为i的LIS数组的最小结尾数字
        for (int i = 1; i <= n; i++) {
            int x = a[i];
            int l = 0, r = len;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                // 如果是最长不降子序列，这里改为f[mid] <= x
                if (f[mid] < x)
                    l = mid;
                else
                    r = mid - 1;
            }
            f[l + 1] = x;
            len = max(len, l + 1);
        }
        return len;
    }
};
