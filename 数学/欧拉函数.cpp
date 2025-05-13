// 求单个数的欧拉函数值
int phi(int x) {
    int res = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}


// 线性筛求欧拉函数
// https://oi-wiki.org/math/number-theory/sieve/#%E7%AD%9B%E6%B3%95%E6%B1%82%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0
vector<int> pri;
bool not_prime[N];
int phi[N];

void pre(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!not_prime[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        phi[i * pri_j] = phi[i] * pri_j;
        break;
      }
      phi[i * pri_j] = phi[i] * phi[pri_j];
    }
  }
}
