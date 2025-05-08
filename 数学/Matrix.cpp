#include <iostream>
#include <vector>
#define LL long long
const int mod = 1e9 + 7;

// 用1到n的下标存储矩阵，会多开一个元素的空间
struct Matrix {
    int n;
    std::vector<std::vector<LL>> v;

    Matrix(int _n, bool isIdentity = false) {
        n = _n;
        v = std::vector<std::vector<LL>>(n + 1, std::vector<LL>(n + 1, 0));
        if (isIdentity) {
            for (int i = 1; i <= n; i++) {
                v[i][i] = 1;
            }
        }
    }

    Matrix operator*(Matrix x) const {
        Matrix c(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    c.v[i][j] += 1LL * v[i][k] * x.v[k][j], c.v[i][j] %= mod;
        return c;
    }

    Matrix operator+(Matrix x) const {
        Matrix c(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                c.v[i][j] = (v[i][j] + x.v[i][j]) % mod;
            }
        return c;
    }

    Matrix operator-(Matrix x) const {
        Matrix c(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                c.v[i][j] = (v[i][j] - x.v[i][j] + mod) % mod;
            }
        return c;
    }

    Matrix qpow(Matrix x, long long y) {
        Matrix c = Matrix(n, true);
        while (y) {
            if (y & 1)
                c = c * x;
            x = x * x;
            y >>= 1;
        }
        return c;
    }
};

int main() {
    LL n, k;
    cin >> n >> k;
    Matrix res(n);

    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> res.v[i][j];
        }
    }

    res = res.qpow(res, k);
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << res.v[i][j] << " ";
        }
      cout << endl;
    }

return 0;
}
