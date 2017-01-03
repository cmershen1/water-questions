#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
struct EDGE {
    int u,v,w;
}edge[123456];
int m[123456]; //machine
int f[123456],sum[123456],r[123456];
bool cmp(EDGE x,EDGE y) {
    return x.w<y.w;
}
int find(int x) {
    return x==f[x]?f[x]:f[x]=find(f[x]);
}
void un(int i,int j) {
    int x=find(i),y=find(j);
    if(x!=y) {
        if(r[x]<r[y]) {
            f[x]=y;
            sum[y]+=sum[x];
        }
        else {
            f[y]=x;
            sum[x]+=sum[y];
            if(r[x]==r[y])
                r[x]++;
        }
    }
}
ll solve() {
    ll ans=0;
    for(int i=0;i<n;i++) {
        f[i]=i;
        sum[i]=m[i];
        r[i]=1;
    }
    sort(edge,edge+n-1,cmp);
    for(int i=n-1;i>=0;i--) {
        int u=find(edge[i].u),v=find(edge[i].v);
        if(u!=v) {
            if(sum[u]+sum[v]<=1)
                un(u,v);
            else
                ans+=edge[i].w;
        }
    }
    return ans;
}
int main(){
    cin>>n>>k;
    memset(m,0,sizeof(m));
    int x,y,z;
    for(int i=0;i<n-1;i++) {
        cin>>x>>y>>z;
        edge[i].u=x;edge[i].v=y;edge[i].w=z;
    }
    for(int i=0;i<k;i++) {
        cin>>x;
        m[x]=1;
    }
    cout<<solve()<<endl;
}
