#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LSON l,mid,i<<1
#define RSON mid+1,r,i<<1|1
int a[MAXN];
struct s{
    int l,r,sum;
    int lazy;
}seg[MAXN<<2];

void build(int l, int r, int i) {
    seg[i].l = l;
    seg[i].r = r;
    seg[i].lazy = 0;
    if (l == r) {
        seg[i].sum = a[l];
    } else {
        int mid = (l + r) >> 1;
        build(LSON);
        build(RSON);
        seg[i].sum = seg[i<<1].sum + seg[i<<1|1].sum;
    }
}
//i:节点序号
void pushdown(int i) {
    if (seg[i].lazy) {
        int m = seg[i].r - seg[i].l + 1;//区间长度
        seg[i<<1].lazy = seg[i].lazy;
        seg[i<<1].sum = seg[i].lazy * (m - (m>>1));//左孩子sum更新

        seg[i<<1|1].lazy = seg[i].lazy;
        seg[i<<1|1].sum = seg[i].lazy * (m>>1);//右孩子sum更新

        seg[i].lazy = 0;//清空父节点
    }
}

void update(int l, int r, int i, int val) {
    int m = seg[i].r - seg[i].l + 1;//区间长度
    if (l <= seg[i].l && seg[i].r <= r) {
        seg[i].lazy = val;//该节点要改成val
        seg[i].sum = val*m;
        return;
    } else {
        pushdown(i);//下放
        int mid = (seg[i].l + seg[i].r) >> 1;
        if (l > mid) {
            update(l, r, i<<1|1, val);
        } else if (r <= mid) {
            update(l, r, i<<1, val);
        } else {
            update(l, r, i<<1|1, val);
            update(l, r, i<<1, val);
        }
        seg[i].sum = seg[i<<1].sum + seg[i<<1|1].sum;
    }
}

int query(int l, int r, int i) {
    if (l <= seg[i].l && seg[i].r <= r)
        return seg[i].sum;
    else {
        pushdown(i);
        int mid = (seg[i].l + seg[i].r) >> 1;
        if (l > mid) {
            return query(l, r, i<<1|1);
        } else if (r <= mid) {
            return query(l, r, i<<1);
        } else {
            return query(l, r, i<<1|1) + query(l, r, i<<1);
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    build(1,n,1);
    cin >> m;
    int o,p,q,r;
    while (m--) {
        cin >> o >> p >> q;
        if (o == 0) {
            cout << query(p ,q, 1) << endl;
        } else {
            cin >> r;
            update(p, q, 1, r);
        }
    }
}
