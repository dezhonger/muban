#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "C:\zwl\files\docs\debug.h"
#else
#define debug(...) 42
#endif
typedef long long LL;
typedef unsigned long long ULL;
const LL MOD = 998244353;

// FWT 或运算正变换
void OrFWT(vector<LL>& a, LL type) {
    int n = a.size();
    for (LL x = 2; x <= n; x <<= 1) {
        LL k = x >> 1;
        for (LL i = 0; i < n; i += x) {
            for (LL j = 0; j < k; j++) {
                (a[i + j + k] += a[i + j] * type) %= MOD;
                if (a[i + j + k] < 0)
                    a[i + j + k] += MOD;
            }
        }
    }
}

// 计算或卷积
vector<LL> OrConv(const vector<LL>& a, const vector<LL>& b) {
    vector<LL> A = a, B = b;
    int n = 1;
    while (n < (int)max(a.size(), b.size()))
        n <<= 1;
    A.resize(n);
    B.resize(n);

    debug(n);  // [n]: 8

    // 正变换
    debug(A);     // [A]: {1, 2, 3, 4, 5, 0, 0, 0} 下标从0开始
    OrFWT(A, 1);  // [A]: {1, 3, 4, 10, 6, 8, 9, 15}
    debug(A);

    debug(B);  //[B]: {6, 7, 8, 9, 10, 11, 0, 0}
    OrFWT(B, 1);
    debug(B);  // [B]: {6, 13, 14, 30, 16, 34, 24, 51}

    // 点乘
    vector<LL> C(n);
    for (int i = 0; i < n; i++) {
        C[i] = A[i] * B[i] % MOD;
    }

    debug(C);  // [C]: {6, 39, 56, 300, 96, 272, 216, 765}
    // 逆变换
    OrFWT(C, -1);
    debug(C); // [C]: {6, 33, 50, 211, 90, 143, 70, 162}
    return C;
}

// 暴力计算或卷积
vector<LL> bruteForceOrConv(const vector<LL>& a, const vector<LL>& b) {
    int n = 1;
    while (n < (int)max(a.size(), b.size()))
        n <<= 1;
    vector<LL> result(n, 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            int idx = i | j;
            result[idx] = (result[idx] + a[i] * b[j]) % MOD;
        }
    }
    return result;
}

int main() {
    vector<LL> a = {1, 2, 3, 4, 5};
    vector<LL> b = {6, 7, 8, 9, 10, 11};

    std::vector<LL> resultFWT = OrConv(a, b);
    std::vector<LL> resultBruteForce = bruteForceOrConv(a, b);

    std::cout << "FWT 计算的卷积结果: ";
    for (LL val : resultFWT) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "暴力计算的卷积结果: ";
    for (LL val : resultBruteForce) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
