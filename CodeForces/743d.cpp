#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> g[200005];
int a[200005];
ll dp[200005];
ll sum[200005];
//bool vis[200005];
ll ans=LONG_LONG_MIN;
int n;
void dfs(int u, int f) {
    //vis[u]=1;
    ll maxdp = LONG_LONG_MIN;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if(v!=f) {
            dfs(v, u);
            sum[u]+=sum[v];
            maxdp=max(maxdp,dp[v]);
        }
    }
    sum[u]+=a[u];
    dp[u]=max(maxdp,sum[u]);
}
void dfs2(int u, int f) {
    ll t1,t2;
    t1=t2=LONG_LONG_MIN;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if(v==f)
            continue;
        dfs2(v,u);
        if(dp[v]>t1) {
            t2=t1;
            t1=dp[v];
        } else if(dp[v]>t2) {
            t2=dp[v];
        }
    }
    if(t1!=LONG_LONG_MIN && t2!=LONG_LONG_MIN) {
        if(t1)
        ans=max(ans,t1+t2);
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp,0,sizeof(dp));
    //memset(vis,0,sizeof(vis));
    dfs(1,0);
    //memset(vis,0,sizeof(vis));
    dfs2(1,0);
    if(ans == LONG_LONG_MIN)
        cout<<"Impossible"<<endl;
    else
        cout<<ans<<endl;
}
