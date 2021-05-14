#include <bits/stdc++.h>
using namespace std;
//Filename: 758.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-15 00:05:20
//Last modified: 2021-05-15 00:09:08


const int N = 100005;
int n;
int a[N];

void qsort(int a[], int l, int r) {
    if (l >= r) return ;
    int x = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    qsort(a, l, j);
    qsort(a, j + 1, r);
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    qsort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}

