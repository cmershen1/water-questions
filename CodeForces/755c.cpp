#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 10005
int f[MAXN];

void init() {
    for(int i=1;i<=MAXN;i++) {
        f[i]=i;
    }
}

int find(int x) {
    return f[x]==x?x:f[x]=find(f[x]);
}

int Union(int x, int y) {
    x=find(x);
    y=find(y);
    if(x!=y) {
        f[x]=y;
    }
}
int main() {
    int n,m;
    cin>>n;
    init();
    for (int i = 1; i <= n; i++) {
        cin>>m;
        Union(i,m);
    }
    int cnt=0;
    for (int i = 1; i<=n;i++) {
        if(f[i]==i)
            cnt++;
    }
    cout<<cnt<<endl;
}
