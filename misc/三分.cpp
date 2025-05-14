这个是一个单峰函数（是“先增后减”或“先减后增”），可以用三分法优化求最大值。

// 三分法找最大值
// [l, r]
while (r - l > 5) {
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;
    ll val1 = compute(m1);
    ll val2 = compute(m2);
    // 求最小值需要把这里反向
    if (val1 < val2)
        l = m1;
    else
        r = m2;
}

for (ll x = l; x <= r; ++x) {
    ans = max(ans, compute(n, m, a, b, x));
}
