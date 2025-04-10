//下标是从1开始的

struct Bit {
    int n;
    vector<int> tr;

    Bit(int n) :n(n) { tr = vector<int>(n + 1, 0); }

    int lowbit(int x) { return x & (-x); }

    void add(int pos, int x) {
        for (int i = pos; i <= n; i += lowbit(i)) tr[i] += x;
    }

    int sum(int pos) {
        int res = 0;
        for (int i = pos; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    int query(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};

//模板化
template <typename T>
struct Bit {
    int n;
    std::vector<T> tr;

    Bit(int n) : n(n) { tr = std::vector<T>(n + 1, 0); }

    int lowbit(int x) { return x & (-x); }

    void add(int pos, T x) {
        for (int i = pos; i <= n; i += lowbit(i))
            tr[i] += x;
    }

    T sum(int pos) {
        T res = 0;
        for (int i = pos; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }

    T query(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};
