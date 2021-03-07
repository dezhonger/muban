#include <bits/stdc++.h>
using namespace std;


typedef long long LL;
int n;
int a[100010], b[100010];


LL mergeSort(int a[], int l, int r) {
    if (l == r) return 0;
    int mid = l + r >> 1;
    LL ans = 0;
    ans += mergeSort(a, l, mid);
    ans += mergeSort(a, mid + 1, r);
    
    
    
    int i = l, j = mid + 1, idx = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[idx++] = a[i++];
        else {
            b[idx++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid) b[idx++] = a[i++];
    while (j <= r) b[idx++] = a[j++];
    for (int i = 0, j = l; i < idx; i++, j++) a[j] = b[i];
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << mergeSort(a, 0, n - 1); 
    return 0;
}
