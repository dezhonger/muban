// or:
void FWT_OR(vector<int>& a, bool inv) {
    int n = a.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int m = d << 1, i = 0; i < n; i += m) {
            for (int j = 0; j < d; j ++) {
                if (!inv)
                    a[i + j + d] += a[i + j];
                else
                    a[i + j + d] -= a[i + j];
            }
        }
    }
}

// and:
void FWT_AND(vector<int>& a, bool inv) {
    int n = a.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int m = d << 1, i = 0; i < n; i += m) {
            for (int j = 0; j < d; ++j) {
                if (!inv)
                    a[i + j] += a[i + j + d];
                else
                    a[i + j] -= a[i + j + d];
            }
        }
    }
}

// xor:
void FWT_XOR(vector<int>& a, bool inv) {
    int n = a.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += (d << 1)) {
            for (int j = 0; j < d; j ++) {
                int u = a[i + j], v = a[i + j + d];
                a[i + j] = u + v;
                a[i + j + d] = u - v;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i ++) {
            a[i] /= n;
        }
    }
}

// n是2的幂, 比如求a和b的或卷积
vector<LL> OrConv(const vector<LL>& a, const vector<LL>& b) {
    vector<LL> A = a, B = b;
    int n = 1;
    while (n < (int)max(a.size(), b.size()))  n <<= 1;
    A.resize(n);
    B.resize(n);
    vector<LL> C(n);
    FWT_OR(A, 0), FWT_OR(B, 0);
    for (int i = 0; i < n; i++) C[i] = A[i] * B[i] % MOD;
    FWT_OR(C, 1);
    return C;
}


// 参考资料
// https://yharim.com/posts/%E4%BF%A1%E6%81%AF%E5%AD%A6/%E6%95%B0%E8%AE%BA/%E5%A4%9A%E9%A1%B9%E5%BC%8F/%E5%BF%AB%E9%80%9F%E6%B2%83%E5%B0%94%E4%BB%80%E5%8F%98%E6%8D%A2/#
// https://blog.csdn.net/Gh0st_Lx/article/details/139843147
// https://oi-wiki.org/math/poly/fwt/#%E5%BC%82%E6%88%96%E8%BF%90%E7%AE%97
