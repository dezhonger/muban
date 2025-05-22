#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "C:\zwl\files\docs\debug.h"
#else
#define debug(...) 42
#endif
typedef unsigned long long ULL;

const int maxn = 1e6 + 10;
ULL H[maxn];
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ULL rnd() {
    return (unsigned long long)rng();
}

int main() {
    for (int i = 0; i < 100; i++) {
        H[i] = rnd();
    }
    for (int i = 0; i < 100; i++) {
        cout << H[i] << " "; 
    }
    return 0;
}

// 整数均匀分布
#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // [lower, upper]
    int lower = 1, upper = 100;
    std::uniform_int_distribution<> dis(lower, upper);

    for (int i = 0; i < 5; ++i)
        std::cout << dis(gen) << ' ';
    std::cout << '\n';

    return 0;
}

// 浮点数均匀分布
int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    [lower, upper)
    double lower = 0.0, upper = 1.0;
    std::uniform_real_distribution<> dis(lower, upper);

    for (int i = 0; i < 5; ++i)
        std::cout << dis(gen) << ' ';
    std::cout << '\n';

    return 0;
}
