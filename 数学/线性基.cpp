#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "C:\zwl\files\docs\debug.h"
#else
#define debug(...) 42
#endif
using LL = long long;

template <typename T>
string printBinary(const T& value) {
    if (value == 0)
        return "0";
    int bits = sizeof(T) * 8;
    bits = 8; //输出的位数,可以自己调整
    string result;
    result.reserve(bits);
    for (int i = bits - 1; i >= 0; --i) {
        result += ((value >> i) & 1) ? '1' : '0';
    }

    return result;

    //去掉前导0, 如果不需要可以注释掉. 不输出的话二进制不对齐,不好看
    // size_t first_non_zero = result.find_first_not_of('0');
    // if (first_non_zero == string::npos)
    //     return "0";
    // return result.substr(first_non_zero);
}

LL p[64];
int cnt = 0;
// 线性基
vector<LL> v;
// 规范线性基
// 对于d[i], 假设它的最高位为第k位, 那么所有的j>i, d[j]的第k位为0
vector<LL> d;
bool zero = false;

// 线性基构造, 逐个插入即可. p[i]不为0的元素即为线性基的元素.
// 从高位到低位进行, 考虑x的2进制表示
// 如果x第i位为1，判断p[i]是否插入，没有就插入并且退出，否则就异或上p[i]去进行下一位操作
inline void insert(LL x) {
    for (int i = 62; i >= 0; i--) {
        if (x & (1LL << i)) {
            if (!p[i]) {
                p[i] = x;
                cnt++;
                return;
            } else
                x ^= p[i];
        }
    }
    zero = true;
}

// 查询一个元素是否可以被异或出来
// 从高到低，如果这一位为1就异或上这一位的线性基，把1消去，根据性质一，如果最后得到了0，那这个数就可以表示出来
inline bool ask(LL x) {
    for (int i = 62; i >= 0; i--)
        if (x & (1LL << i))
            x ^= p[i];
    return x == 0;
}

// 输出线性基
void print() {
    for (int i = 51; i >= 0; i--) {
        if (p[i]) {
            v.push_back(p[i]);
            debug(i, printBinary(p[i]));
        }
    }

    debug(v.size());
    debug(v);
    for (int i = 0; i < v.size(); i++) {
        debug(i, printBinary(v[i]));
    }
    debug(zero);  // 原数列是否能异或出0
    debug(d);
    for (int i = 0; i < v.size(); i++) {
        debug(i, printBinary(d[i]));
    }
}

// 查询异或最大值
inline LL queryMax() {
    LL ans = 0;
    for (int i = 62; i >= 0; i--)
        if ((ans ^ p[i]) > ans) {
            ans ^= p[i];
        }
    return ans;
}

// 查询异或最小值
// 其实异或的最小值一般来说就是线性基里的最小元素
// 因为插入这个元素的时候我们总是尽量让它的高位为0才来插入这一位
// 但是为什么是“一般”呢？因为有可能会有出现0，得要在插入的时候记下个标记来特判才行
inline LL queryMin() {
    if (zero)
        return 0;
    for (int i = 0; i <= 62; i++)
        if (p[i])
            return p[i];
}

inline void rebuild() {
    for (int i = 62; i >= 0; i--)
        for (int j = i - 1; j >= 0; j--)
            if (p[i] & (1LL << j))
                p[i] ^= p[j];
    for (int i = 0; i <= 62; i++)
        if (p[i])
            d.push_back(p[i]);
}

// 查询异或第k小
inline LL kth(int k) {
    if (k >= (1LL << cnt))
        return -1;
    LL ans = 0;
    for (int i = d.size() - 1; i >= 0; i--)
        if (k & (1LL << i))
            ans ^= d[i];
    return ans;
}
// 调用的时候注意考虑是否有0的情况

// 查询排名
inline int rank(LL x) {
    int ans = 0;
    for (int i = d.size() - 1; i >= 0; i--)
        if (x >= d[i])
            ans += (1 << i), x ^= d[i];
    return ans + zero;
}

int main() {
    int n;
    cin >> n;
    LL x, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        insert(x);
    }

    rebuild();
    // print();
    cout << queryMax() << endl;
    return 0;
}

// 测试
// 4
// 3 5 6 7

// 4
// 3 5 6 100