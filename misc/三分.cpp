这个是一个单峰函数（是“先增后减”或“先减后增”），可以用三分法优化求最大值。

// 三分法找最大值
// [l, r]
while (r - l > 5) {
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;
    ll val1 = compute(m1);
    ll val2 = compute(m2);
    if (val1 < val2)
        l = m1;
    else
        r = m2;
}

for (ll x = l; x <= r; ++x) {
    ans = max(ans, compute(n, m, a, b, x));
}


// 三分板子 最小值
double l = 0.0, r = 1e9;
while (r - l >= 1e-7) {
    // 要求1e-6
    double s = (r - l) / 3.0;
    double t1 = l + s;
    double t2 = l + 2 * s;

    double res1 = calc(y, x, v, t1);
    double res2 = calc(y, x, v, t2);

    if (res1 >= res2) {
        l = t1;
    } else {
        r = t2;
    }
}

System.out.println(calc(y, x, v, l));

}
