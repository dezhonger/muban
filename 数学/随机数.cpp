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
