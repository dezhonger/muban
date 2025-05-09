int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
long long lcm(int a, int b) {
    return 1LL * a * b / gcd(a, b);
}
