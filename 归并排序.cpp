#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010], b[100010];

void mergeSort(int a[], int l, int r) {
    if (l == r) return ;
    int mid = l + r >> 1;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    int i = l, j = mid + 1, idx = 0;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) b[idx++] = a[i++];
        else b[idx++] = a[j++];
    }
    while (i <= mid) b[idx++] = a[i++];
    while (j <= r) b[idx++] = a[j++];
    for (int i = 0, j = l; i < idx; i++, j++) a[j] = b[i];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
