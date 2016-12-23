#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[105];
int n,m,u,v;
bool vis[105];
int ans;
int dfs(int u) {
    vis[u]=1;
    int node=0;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if(!vis[v]) {
            int t=dfs(v);
            if(t%2==0)
                ans++;
            else
                node+=t;
        }
    }
    return node+1;
}
int main(){
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    while(m--) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans=0;
    dfs(1);
    cout<<ans<<endl;
}
