// 求 x 的二进制长度（去掉前导零后最高位所在的位置 + 1）。
// 例如 x=1 -> 返回 1；x=2 (10₂)->返回 2；x=5(101₂)->返回 3。
// 注意：x>0 时 __builtin_clzll 定义良好；若 x=0，不调用本函数。
inline int bit_length(ull x) {
    // __builtin_clzll(x) 返回 x 的高 64 位里，前导零的个数
    // 例如 x=1 -> clz=63，64-63 = 1；x=5 -> clz=61, 64-61=3
    return 64 - __builtin_clzll(x);
}

// x>0, 返回最大的k, 2^k | x
int v2(long long x) {
    return __builtin_ctzll(x);
}
