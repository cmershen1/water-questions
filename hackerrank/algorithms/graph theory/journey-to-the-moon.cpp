#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,u,v;
int f[100005],sum[100005],r[100005];
int find(int x) {
    if(x!=f[x])
        f[x]=find(f[x]);
    return f[x];
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
void pre() {
    for(int i=0;i<n;i++) {
        f[i]=i;
        sum[i]=1;
        r[i]=0;
    }
}
void calc() {
    ll ans=0,pre=0;
    for(int i=0;i<n;i++) {
        if(f[i]==i) {
            ans+=pre*sum[i];
            pre+=sum[i];
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin>>n>>m;
    pre();
    while(m--) {
        cin>>u>>v;
        un(u,v);
    }
    calc();
}
