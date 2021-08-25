#include <bits/stdc++.h>
using namespace std;
//Filename: acwing253.cpp
//普通平衡树
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-11-29 00:15:41


typedef long long LL;

const int N = 100010, INF = 1e8;

//节点个数
int n; 
struct Node {
    int l, r; //左右节点
    int key; //元素的值 BST使用
    int val; //随机值 堆使用
    int cnt; //当前key相等的节点的个数
    int size; //当前子树的节点个数, 相同值会计算多次
}tr[N];

//root表示节点的编号
int root, idx;

void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

//分配节点
int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].l = tr[idx].r = 0;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}

//右旋
void zig(int &p) {
    int q = tr[p].l;
    tr[p].l = tr[q].r, tr[q].r = p, p = q;
    pushup(tr[p].r), pushup(q);
}

//左旋
void zag(int &p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;
    pushup(tr[p].l), pushup(p);
}

//初始化操作
void build() {
    idx = 0;
    get_node(-INF), get_node(INF);
    root = 1, tr[root].r = 2;
    pushup(root);

    if (tr[root].val < tr[2].val) zag(root);
}

//插入操作
void insert(int &p, int key) {
    if (!p) p = get_node(key);
    else if (tr[p].key == key) tr[p].cnt++;
    else if (tr[p].key > key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) zig(p);
    } else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) zag(p);
    }
    pushup(p);
}

//删除操作
void remove(int &p, int key) {
    if (!p) return ;
    if (tr[p].key == key) {
        if (tr[p].cnt > 1) tr[p].cnt--;
        else if (tr[p].l || tr[p].r) {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                zig(p);
                remove(tr[p].r, key);
            } else {
                zag(p);
                remove(tr[p].l, key);
            }
        } else {
            p = 0;
        }
    } else if (tr[p].key > key) remove(tr[p].l, key);
    else remove(tr[p].r, key);
    pushup(p);
}

//通过数值找排名
int getRankByKey(int p, int key) {
    if (!p) return 0;
    if (tr[p].key == key) return tr[tr[p].l].size + 1;
    if (tr[p].key > key) return getRankByKey(tr[p].l, key);
    return tr[tr[p].l].size + tr[p].cnt + getRankByKey(tr[p].r, key);
}

//通过排名找数值
int getKeyByRank(int p, int rank) {
    if (!p) return INF;
    if (tr[tr[p].l].size >= rank) return getKeyByRank(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;
    return getKeyByRank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}

//找前驱, 严格小于key的最大值
int getPrve(int p, int key) {
    if (!p) return -INF;
    if (tr[p].key >= key) return getPrve(tr[p].l, key);
    return max(tr[p].key, getPrve(tr[p].r, key));
}

//找后继，严格大于key的最小值
int getNext(int p, int key) {
    if (!p) return INF;
    if (tr[p].key <= key) return getNext(tr[p].r, key);
    return min(tr[p].key, getNext(tr[p].l, key));
}

int main() {
    build();
    scanf("%d", &n);
    while (n--) {
        int opt, x;
        scanf("%d%d", &opt, &x);

        if (opt == 1) insert(root, x);
        else if (opt == 2) remove(root, x);
        else if (opt == 3) printf("%d\n", getRankByKey(root, x) - 1);
        else if (opt == 4) printf("%d\n", getKeyByRank(root, x + 1));
        else if (opt == 5) printf("%d\n", getPrve(root, x));
        else printf("%d\n", getNext(root, x));

    }
    return 0;
}

