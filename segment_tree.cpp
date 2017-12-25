#include <bits/stdc++.h>
using namespace std;

#define MAXN 10005
#define LSON l,mid,i<<1
#define RSON mid+1,r,i<<1|1
int a[MAXN];
struct s{
    int l,r;
    int m;//min
}seg[MAXN<<2];

void build(int l, int r, int i) {
    seg[i].l = l;
    seg[i].r = r;
    if (l == r) {
        seg[i].m = a[l];
    } else {
        int mid = (l + r) >> 1;
        build(LSON);
        build(RSON);
        seg[i].m = min(seg[i<<1].m, seg[i<<1|1].m);
    }
}

void update(int q, int val, int i) {
    if (seg[i].l == q && seg[i].r == q) {
        seg[i].m = val;
    } else {
        int mid = (seg[i].l + seg[i].r) >> 1;
        if (q <= mid)
            update(q, val, i<<1);
        else if (q > mid)
            update(q, val, i<<1|1);
        seg[i].m = min(seg[i<<1].m, seg[i<<1|1].m);
    }
}

int query(int l, int r, int i) {
    if (l <= seg[i].l && seg[i].r <= r)
        return seg[i].m;
    else {
        int mid = (seg[i].l + seg[i].r) >> 1;
        if (l > mid)
            return query(l, r, i<<1|1);
        else if (r <= mid)
            return query(l, r, i<<1);
        else
            return min(query(l, r, i<<1), query(l, r, i<<1|1));
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
    int o,p,q;
    while (m--) {
        cin >> o >> p >> q;
        if (o == 0) {
            cout << query(p ,q, 1) << endl;
        } else {
            update(p, q, 1);
        }
    }
}
