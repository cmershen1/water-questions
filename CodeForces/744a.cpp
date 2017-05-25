#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[1000];
bool gov[1000],vis[1000];
int f[1000],sum[1000];
ll ans=0;
int find(int x) {
    return x==f[x]?x:f[x]=find(f[x]);
}
void Union(int x,int y) {
    x=find(x);y=find(y);
    if(x!=y) {
        if(gov[x] && !gov[y])
            swap(x,y);
        f[x]=y;
        sum[y]+=sum[x];
    }
}

int main() {
    int n,m,k,u,v;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        f[i]=i;
        sum[i]=1;
    }
    for(int i=0;i<k;i++) {
        cin>>c[i];
        gov[c[i]]=true;
    }
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        Union(u,v);
    }

    //find largest gov
    int max_id = -1,max_gov=-1;
    for(int i=0;i<k;i++) {
        int id=find(c[i]);
        if(sum[id] > max_gov) {
            max_id=id;
            max_gov=sum[id];
        }
    }
    //added no gov sub graph
    for(int i=1;i<=n;i++) {
        if(i==find(i) && !gov[i])
            Union(i,max_id);
    }
    //add edges into complete graph
    for(int i=0;i<k;i++) {
        ans+=sum[c[i]]*(sum[c[i]]-1)/2;
    }

    cout<<ans-m<<endl;

}
