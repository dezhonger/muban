const int MX = 5;
int c[MX][MX];

// 预处理组合数
auto init = []() {
    for (int i = 0; i < MX; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    return 0;
}();

// 计算 C(n, k) % p，要求 p 是质数
int lucas(int n, int k, int p) {
    if (k == 0) {
        return 1;
    }
    return c[n % p][k % p] * lucas(n / p, k / p, p) % p;
};
