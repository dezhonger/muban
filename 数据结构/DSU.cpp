// 下标从0开始
struct DSU {
    std::vector<int> f, siz, edges;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        edges.assign(n, 0);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            edges[x]++;
            return false;
        }
        siz[x] += siz[y];
        edges[x] += edges[y] + 1;
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }

    void print() {
        for (int i = 0; i < f.size(); i++) {
            cout << i << " " << f[i] << " " << siz[i] << " " << edges[i] << endl;
        }
    }
};
